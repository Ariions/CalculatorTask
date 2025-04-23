#include "../include/Parser.h"
#include "../include/Value.h"
#include "../include/Sum.h"
#include "../include/Mul.h"
#include "../include/Sub.h"
#include "../include/Div.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <map>

Parser::Parser() {}

Parser::~Parser() {}

Inode* Parser::parse(const std::string& expression, std::map<std::string, double>& variables) {
    std::istringstream stream(expression);
    Inode* root = parseExpression(stream, variables);

    // Check if the stream is fully consumed
    if (stream.peek() != EOF) {
        throw std::runtime_error("Parsing error: Unprocessed input remains in the expression.");
    }

    return root;
}

Inode* Parser::parseExpression(std::istringstream& stream, std::map<std::string, double>& variables) {
    Inode* left = parseTerm(stream, variables);

    while (stream) {
        stream >> std::ws; // Skip whitespace
        char op = stream.peek();
        if (op == '+' || op == '-') {
            stream.get(); // Consume the operator
            Inode* right = parseTerm(stream, variables);
            if (op == '+') {
                left = new Sum(left, right);
            } else {
                left = new Sub(left, right);
            }
        } else {
            break;
        }
    }

    return left;
}

Inode* Parser::parseTerm(std::istringstream& stream, std::map<std::string, double>& variables) {
    Inode* left = parseFactor(stream, variables);

    while (stream) {
        stream >> std::ws; // Skip whitespace
        char op = stream.peek();
        if (op == '*' || op == '/') {
            stream.get(); // Consume the operator
            Inode* right = parseFactor(stream, variables);
            if (op == '*') {
                left = new Mul(left, right);
            } else {
                left = new Div(left, right);
            }
        } else {
            break;
        }
    }

    return left;
}

Inode* Parser::parseFactor(std::istringstream& stream, std::map<std::string, double>& variables) {
    stream >> std::ws; // Skip whitespace
    char next = stream.peek();

    if (std::isdigit(next) || next == '.') {
        // Parse a numeric value
        double value;
        stream >> value;
        return new Value(value);
    } else if (std::isalpha(next)) {
        // Parse a multi-character variable name
        std::string varName;
        while (std::isalnum(stream.peek())) { // Read alphanumeric characters
            varName += stream.get();
        }

        if (variables.find(varName) == variables.end()) {
            throw std::runtime_error("Variable " + varName + " is not defined.");
        }

        return new Value(variables[varName]);
    } else if (next == '(') {
        // Parse a sub-expression in parentheses
        stream.get(); // Consume '('
        Inode* expr = parseExpression(stream, variables);
        stream >> std::ws; // Skip whitespace
        if (stream.get() != ')') {
            throw std::runtime_error("Mismatched parentheses");
        }
        return expr;
    } else {
        throw std::runtime_error("Invalid character in expression");
    }
}