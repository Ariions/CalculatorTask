#pragma once
#include <unordered_map>
#include <string>

class VariableResolver {
public:
    static double resolve(const std::string& varName);
};