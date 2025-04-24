#include <gtest/gtest.h>
#include "../include/ExpressionEvaluator.h"
#include "../tests/MockInputHandler.cpp"

TEST(ParserTest, TestComplexExpression) {
    // Mock input for testing
    MockInputHandler mockInput("(x + y) * z", {{"x", 2}, {"y", 3}, {"z", 4}});

    // Evaluate the expression
    double result = evaluateExpression(mockInput.getExpression(), mockInput);

    // Assert the result
    EXPECT_DOUBLE_EQ(result, 20.0); // Assert the result of the expression
}