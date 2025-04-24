#include <gtest/gtest.h>
#include "../include/ExpressionEvaluator.h"
#include "../tests/MockInputHandler.cpp"

TEST(ParserTest, TestSubstr) {
    // Mock input for testing
    MockInputHandler mockInput("x - y", {{"x", 10}, {"y", 4}});

    // Evaluate the expression
    double result = evaluateExpression(mockInput.getExpression(), mockInput);

    // Assert the result
    EXPECT_DOUBLE_EQ(result, 6.0); // Assert the result of the expression
}