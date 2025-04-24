#include "../include/VariableResolver.h"
#include "../include/IDialogInput.h"
#include <iostream>
#include <cctype>
#include <sstream>

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

void VariableResolver::resolveVariables(const std::set<std::string>& variables, std::map<std::string, double>& variableValues, const IDialogInput& inputResolver) {
    for (const auto& var : variables) {
        if (variableValues.find(var) == variableValues.end()) {
            // Use the input resolver to get the variable's value
            variableValues[var] = inputResolver.resolveVariable(var);
        }
    }
}