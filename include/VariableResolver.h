#pragma once
#ifndef VARIABLERESOLVER_H
#define VARIABLERESOLVER_H

#include <set>
#include <string>
#include <map>
#include "IDialogInput.h"

class VariableResolver {
public:
    // Extract variables from the expression
    std::set<std::string> extractVariables(const std::string& expression);

    // Resolve variables by prompting the user for their values
    static void resolveVariables(const std::set<std::string>& variables, std::map<std::string, double>& variableValues, const IDialogInput& inputResolver);
};

#endif // VARIABLERESOLVER_H