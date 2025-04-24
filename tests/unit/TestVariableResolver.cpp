#include <gtest/gtest.h>
#include "../../include/VariableResolver.h"
#include "../util/MockInputHandler.cpp"

// Test for extracting variables from an expression
TEST(VariableResolverClass, ExtractVariables) {
    VariableResolver resolver;
    std::set<std::string> variables = resolver.extractVariables("x + y * z");
    EXPECT_EQ(variables.size(), 3);
    EXPECT_TRUE(variables.find("x") != variables.end());
    EXPECT_TRUE(variables.find("y") != variables.end());
    EXPECT_TRUE(variables.find("z") != variables.end());
}

// Test for resolving variables
TEST(VariableResolverClass, ResolveVariables) {
    VariableResolver resolver;
    std::set<std::string> variables = {"x", "y"};
    std::map<std::string, double> resolvedVariables;
    MockInputHandler mockInput("", {{"x", 5.0}, {"y", 3.0}});
    resolver.resolveVariables(variables, resolvedVariables, mockInput);
    EXPECT_DOUBLE_EQ(resolvedVariables["x"], 5.0);
    EXPECT_DOUBLE_EQ(resolvedVariables["y"], 3.0);
}