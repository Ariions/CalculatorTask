#include "../include/ExpretionResolver.h"
#include "../include/Parser.h"
#include "../include/VariableResolver.h"
#include "../include/IDialogInput.h"
#include <map>
#include <set>
#include <string>

std::pair<double, std::string> resolveExpression(const std::string& expression, IDialogInput& inputHandler) {
    // Resolve variable values
    VariableResolver resolver;
    std::map<std::string, double> variables;
    std::set<std::string> extractedVariables = resolver.extractVariables(expression);
    resolver.resolveVariables(extractedVariables, variables, inputHandler);

    // Parse the expression into an AST
    Parser parser;
    Inode* root = parser.parse(expression, variables);

    // Reconstruct the expression with substituted values
    std::string reconstructedExpression = root->print();

    // Evaluate the expression
    double result = root->calc();

    // Clean up the AST
    delete root;

    // Return both the result and the reconstructed expression
    return {result, reconstructedExpression};
}