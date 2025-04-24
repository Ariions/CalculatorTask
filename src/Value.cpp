#include "../include/Value.h"
#include <iomanip>
#include <sstream>

Value::Value(double val) : value(val) {}

Value::~Value() {}

double Value::calc() const {
    return value;
}

std::string Value::print() const {
    std::ostringstream oss;

    // Check if the number is an integer
    if (value == static_cast<int>(value)) {
        oss << static_cast<int>(value); // Print as an integer
    } else {
        // Determine the precision dynamically
        oss << std::fixed;
        if (std::abs(value * 10 - static_cast<int>(value * 10)) < 1e-6) {
            oss << std::setprecision(1); // 1 decimal place
        } else if (std::abs(value * 100 - static_cast<int>(value * 100)) < 1e-6) {
            oss << std::setprecision(2); // 2 decimal places
        } else if (std::abs(value * 1000 - static_cast<int>(value * 1000)) < 1e-6) {
            oss << std::setprecision(3); // 3 decimal places
        } else {
            oss << std::setprecision(4); // Up to 4 decimal places
        }
        oss << value;
    }

    return oss.str();
}