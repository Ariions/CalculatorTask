#pragma once
#ifndef VARIABLERESOLVER_H
#define VARIABLERESOLVER_H

#include <string>
#include <map>
#include <set>

class VariableResolver {
public:
    VariableResolver();
    ~VariableResolver();

    // Extract variables from the expression
    std::set<std::string> extractVariables(const std::string& expression);

    // Resolve variables by prompting the user for their values
    void resolveVariables(const std::set<std::string>& variables, std::map<std::string, double>& variableValues);
};

#endif // VARIABLERESOLVER_H