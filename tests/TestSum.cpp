#include <gtest/gtest.h>
#include "Value.h"
#include "../include/Parser.h"
#include "../include/VariableResolver.h"
#include "../include/ExpressionEvaluator.h"
#include "../tests/MockInputHandler.cpp"
#include <map>
#include <set>

TEST(SumTest, SimpleAddition) {
    Value a(3);
    Value b(4);
    //EXPECT_DOUBLE_EQ(sum.calc(), 7.0);
}

TEST(ParserTest, TestSum) {
    // Mock input for testing
    MockInputHandler mockInput("x + y", {{"x", 5}, {"y", 3}});

    // Evaluate the expression
    double result = evaluateExpression(mockInput.getExpression(), mockInput);

    // Assert the result
    EXPECT_DOUBLE_EQ(result, 8.0); // Assert the result of the expression
}