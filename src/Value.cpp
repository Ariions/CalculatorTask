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
    oss << std::fixed << std::setprecision(2) << value; // Set precision to 2 decimal places
    return oss.str();
}