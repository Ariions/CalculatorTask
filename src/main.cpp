#include "../include/Parser.h"
#include "../include/VariableResolver.h"
#include "../include/ExpressionEvaluator.h"
#include "../src/TerminalInput.cpp" // Include the terminal input handler
#include <map>
#include <set>
#include <iostream>

int main() {
    try {
        TerminalInput input;

        // Get the expression
        std::string expression = input.getExpression();

        // Evaluate the expression
        double result = evaluateExpression(expression, input);

        // Output the result
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
