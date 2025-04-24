#include <gtest/gtest.h>
#include "../../include/ExpretionResolver.h"
#include "../util/MockInputHandler.cpp"

TEST(ExpretionResolverClass, EvaluateSimpleExpression) {
    MockInputHandler mockInput("3 + 4", {});
    auto [result, reconstructedExpression] = resolveExpression(mockInput.getExpression(), mockInput);
    EXPECT_DOUBLE_EQ(result, 7.0);
    EXPECT_EQ(reconstructedExpression, "(3 + 4)");
}

TEST(ExpretionResolverClass, EvaluateExpressionWithVariables) {
    MockInputHandler mockInput("x + y", {{"x", 5.0}, {"y", 3.0}});
    auto [result, reconstructedExpression] = resolveExpression(mockInput.getExpression(), mockInput);
    EXPECT_DOUBLE_EQ(result, 8.0);
    EXPECT_EQ(reconstructedExpression, "(5 + 3)");
}

TEST(ExpretionResolverClass, EvaluateComplexExpression) {
    MockInputHandler mockInput("(x + y) * z", {{"x", 2.0}, {"y", 3.0}, {"z", 4.0}});
    auto [result, reconstructedExpression] = resolveExpression(mockInput.getExpression(), mockInput);
    EXPECT_DOUBLE_EQ(result, 20.0);
    EXPECT_EQ(reconstructedExpression, "((2 + 3) * 4)");
}

TEST(ExpretionResolverClass, DivisionByZero) {
    MockInputHandler mockInput("10 / 0", {});
    EXPECT_THROW(resolveExpression(mockInput.getExpression(), mockInput), std::runtime_error);
}

TEST(ExpretionResolverClass, EmptyExpression) {
    MockInputHandler mockInput("", {});
    EXPECT_THROW(resolveExpression(mockInput.getExpression(), mockInput), std::runtime_error);
}

TEST(ExpretionResolverClass, UndefinedVariable) {
    MockInputHandler mockInput("x + y", {{"x", 5.0}});
    EXPECT_THROW(resolveExpression(mockInput.getExpression(), mockInput), std::runtime_error);
}