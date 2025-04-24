#include "../include/IDialogInput.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class TerminalInput : public IDialogInput {
public:
    // Get the expression from the user
    std::string getExpression() const {
        std::cout << "Enter an expression: ";
        std::string expression;
        std::getline(std::cin, expression);
        return expression;
    }

    // Resolve a variable's value
    double resolveVariable(const std::string& variableName) const override {
        std::cout << "Enter value for " << variableName << ": ";
        std::string input;
        std::cin >> input;

        // Validate if the input is a valid number
        std::istringstream iss(input);
        double value;
        if (!(iss >> value) || !(iss.eof())) {
            throw std::runtime_error("Invalid input for variable " + variableName + ". Expected a number.");
        }

        return value;
    }
};