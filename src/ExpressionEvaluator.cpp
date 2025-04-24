#include "../include/ExpressionEvaluator.h"
#include "../include/Parser.h"
#include "../include/VariableResolver.h"
#include "../include/IDialogInput.h"
#include <map>
#include <set>
#include <string>

double evaluateExpression(const std::string& expression, IDialogInput& inputHandler) {
    // Extract variables from the expression
    VariableResolver resolver;
    std::set<std::string> extractedVariables = resolver.extractVariables(expression);

    // Resolve variable values
    std::map<std::string, double> variables;
    resolver.resolveVariables(extractedVariables, variables, inputHandler);

    // Parse and evaluate the expression
    Parser parser;
    Inode* root = parser.parse(expression, variables);

    // Evaluate the result
    double result = root->calc();

    // Clean up
    delete root;

    return result;
}