#include "../include/Parser.h"
#include "../include/VariableResolver.h"
#include <iostream>
#include <map>
#include <set>

int main() {
    std::string expression;
    std::map<std::string, double> variables;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    try {
        VariableResolver resolver;
        std::set<std::string> extractedVariables = resolver.extractVariables(expression);
        resolver.resolveVariables(extractedVariables, variables);

        Parser parser;
        Inode* root = parser.parse(expression, variables);

        std::cout << "Result: " << root->calc() << std::endl;
        std::cout << "Formatted expression: " << root->print() << std::endl;

        delete root; // Clean up the dynamically allocated tree
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
