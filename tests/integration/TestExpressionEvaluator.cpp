#include <gtest/gtest.h>
#include "../../include/ExpressionEvaluator.h"
#include "../util/MockInputHandler.cpp"

TEST(ExpressionEvaluatorClass, EvaluateSimpleExpression) {
    MockInputHandler mockInput("3 + 4", {});
    double result = evaluateExpression(mockInput.getExpression(), mockInput);
    EXPECT_DOUBLE_EQ(result, 7.0);
}

TEST(ExpressionEvaluatorClass, EvaluateExpressionWithVariables) {
    MockInputHandler mockInput("x + y", {{"x", 5.0}, {"y", 3.0}});
    double result = evaluateExpression(mockInput.getExpression(), mockInput);
    EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST(ExpressionEvaluatorClass, EvaluateComplexExpression) {
    MockInputHandler mockInput("(x + y) * z", {{"x", 2.0}, {"y", 3.0}, {"z", 4.0}});
    double result = evaluateExpression(mockInput.getExpression(), mockInput);
    EXPECT_DOUBLE_EQ(result, 20.0);
}

TEST(ExpressionEvaluatorClass, DivisionByZero) {
    MockInputHandler mockInput("10 / 0", {});
    EXPECT_THROW(evaluateExpression(mockInput.getExpression(), mockInput), std::runtime_error);
}

TEST(ExpressionEvaluatorClass, EmptyExpression) {
    MockInputHandler mockInput("", {});
    EXPECT_THROW(evaluateExpression(mockInput.getExpression(), mockInput), std::runtime_error);
}

TEST(ExpressionEvaluatorClass, UndefinedVariable) {
    MockInputHandler mockInput("x + y", {{"x", 5.0}});
    EXPECT_THROW(evaluateExpression(mockInput.getExpression(), mockInput), std::runtime_error);
}