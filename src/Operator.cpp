#include "../include/Operator.h"
#include <stdexcept>
#include <cmath>
#include <functional> 
#include <map> 

const std::map<std::string, std::function<double(double, double)>> Operator::operations = {
    {"+", [](double l, double r) { return l + r; }},
    {"-", [](double l, double r) { return l - r; }},
    {"*", [](double l, double r) { return l * r; }},
    {"/", [](double l, double r) {
        if (r == 0) throw std::runtime_error("Division by zero");
        return l / r;
    }}
};

Operator::Operator(const std::string& op, INode* l, INode* r)
    : op(op), left(l), right(r) {
    // Check for null operands
    if (!left || !right) {
        throw std::invalid_argument("Operands cannot be null.");
    }

    // Check for invalid operator
    if (operations.find(op) == operations.end()) {
        throw std::invalid_argument("Invalid operator: " + op);
    }
}

double Operator::calc() const {
    double leftValue = left ? left->calc() : 0;
    double rightValue = right ? right->calc() : 0;

    auto it = operations.find(op);
    if (it != operations.end()) {
        return it->second(leftValue, rightValue); // Call the corresponding function
    }

    throw std::runtime_error("Unknown operator: " + op);
}

std::string Operator::print() const {
    return "(" + left->print() + " " + op + " " + right->print() + ")";
}