#include "../include/Value.h"
#include <iomanip>
#include <sstream>

Value::Value(double val) : value(val) {}

double Value::calc() const {
    return value;
}

std::string Value::print() const {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}