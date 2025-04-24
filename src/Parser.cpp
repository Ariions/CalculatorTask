#include "../include/Parser.h"
#include "../include/Value.h"
#include "../include/Operator.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <map>

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
            left = new Operator(std::string(1, op), left, right);
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
            left = new Operator(std::string(1, op), left, right); // Use Operator class for * and /
        } else if (std::isalpha(op) || op == '(') {
            // Handle implicit multiplication (e.g., 2(3+4) -> 2 * (3+4))
            Inode* right = parseFactor(stream, variables);
            left = new Operator("*", left, right); // Use Operator class for implicit multiplication
        } else {
            break;
        }
    }

    return left;
}

Inode* Parser::parseFactor(std::istringstream& stream, std::map<std::string, double>& variables) {
    stream >> std::ws; // Skip whitespace
    char next = stream.peek();

    // Handle unary minus
    if (next == '-') {
        stream.get(); // Consume the '-'
        if (std::isdigit(stream.peek()) || stream.peek() == '.') {
            // Parse a negative number
            double value;
            stream >> value;
            return new Value(-value);
        } else {
            // Negate the result of the next factor
            Inode* operand = parseFactor(stream, variables);
            return new Operator("*", new Value(-1), operand); // Multiply by -1 to negate
        }
    }

    // Handle numeric values
    if (std::isdigit(next) || next == '.') {
        double value;
        stream >> value;
        return new Value(value);
    }

    // Handle variables
    if (std::isalpha(next)) {
        std::string varName;
        while (std::isalnum(stream.peek())) {
            varName += stream.get();
        }

        if (variables.find(varName) == variables.end()) {
            throw std::runtime_error("Variable " + varName + " is not defined.");
        }

        return new Value(variables[varName]);
    }

    // Handle sub-expressions in parentheses
    if (next == '(') {
        stream.get(); // Consume '('
        Inode* expr = parseExpression(stream, variables);
        stream >> std::ws; // Skip whitespace
        if (stream.get() != ')') {
            throw std::runtime_error("Mismatched parentheses");
        }
        return expr;
    }

    // Handle invalid characters
    throw std::runtime_error("Invalid character in expression");
}