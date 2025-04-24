#include "../include/Operator.h"
#include <stdexcept>
#include <cmath> // For std::pow and std::log
#include <functional> // For std::function
#include <map> // For std::unordered_map

Operator::Operator(const std::string& op, Inode* l, Inode* r)
    : op(op), left(l), right(r) {}

Operator::~Operator() {
    delete left;
    delete right;
}

double Operator::calc() const {
    double leftValue = left ? left->calc() : 0;
    double rightValue = right ? right->calc() : 0;

    // unordered_map would be slightly faster for large number of operations
    static const std::map<std::string, std::function<double(double, double)>> operations = {
        {"+", [](double l, double r) { return l + r; }},
        {"-", [](double l, double r) { return l - r; }},
        {"*", [](double l, double r) { return l * r; }},
        {"/", [](double l, double r) {
            if (r == 0) throw std::runtime_error("Division by zero");
            return l / r;
        }}
    };

    // Find the operator in the map
    auto it = operations.find(op);
    if (it != operations.end()) {
        return it->second(leftValue, rightValue); // Call the corresponding function
    }

    throw std::runtime_error("Unknown operator: " + op);
}

std::string Operator::print() const {
    return "(" + left->print() + " " + op + " " + right->print() + ")";
}