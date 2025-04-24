#pragma once
#include <string>
#include <utility>
#include "../include/IDialogInput.h"

// Function to evaluate an expression using the provided input handler
std::pair<double, std::string> resolveExpression(const std::string& expression, IDialogInput& inputHandler);