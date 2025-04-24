#pragma once
#include <string>
#include "../include/IDialogInput.h"

// Function to evaluate an expression using the provided input handler
double evaluateExpression(const std::string& expression, IDialogInput& inputHandler);