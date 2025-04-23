#include "../include/VariableResolver.h"
#include <iostream>
#include <cctype>
#include <sstream>

VariableResolver::VariableResolver() {}

VariableResolver::~VariableResolver() {}

std::set<std::string> VariableResolver::extractVariables(const std::string& expression) {
    std::set<std::string> variables;
    std::string currentVar;

    for (char ch : expression) {
        if (std::isalpha(ch)) {
            currentVar += ch; // Build variable name
        } else {
            if (!currentVar.empty()) {
                variables.insert(currentVar); // Add variable to the set
                currentVar.clear();
            }
        }
    }

    // Add the last variable if any
    if (!currentVar.empty()) {
        variables.insert(currentVar);
    }

    return variables;
}

void VariableResolver::resolveVariables(const std::set<std::string>& variables, std::map<std::string, double>& variableValues) {
    for (const auto& var : variables) {
        if (variableValues.find(var) == variableValues.end()) {
            std::cout << "Enter value for " << var << ": ";
            double value;
            std::cin >> value;
            variableValues[var] = value;
        }
    }
}