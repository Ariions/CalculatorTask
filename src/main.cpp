#include "../include/Parser.h"
#include "../include/VariableResolver.h"
#include "../include/ExpretionResolver.h"
#include "../src/TerminalInput.cpp"
#include <map>
#include <set>
#include <iostream>

int main() {
    try {
        TerminalInput input;

        std::string expression = input.getExpression();

        auto [result, reconstructedExpression] = resolveExpression(expression, input);

        // Output the result and the reconstructed expression
        std::cout << reconstructedExpression << std::endl;
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
