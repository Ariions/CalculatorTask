#include <gtest/gtest.h>
#include "../../include/Operator.h"
#include "../../include/Value.h"

// Test for addition using Operator directly
TEST(OperatorClass, Addition) {
    Value a(3);
    Value b(4);
    Operator op("+", &a, &b);
    EXPECT_DOUBLE_EQ(op.calc(), 7.0);
}

// Test for subtraction using Operator directly
TEST(OperatorClass, Subtraction) {
    Value a(10);
    Value b(4);
    Operator op("-", &a, &b);
    EXPECT_DOUBLE_EQ(op.calc(), 6.0);
}

// Test for multiplication using Operator directly
TEST(OperatorClass, Multiplication) {
    Value a(3);
    Value b(4);
    Operator op("*", &a, &b);
    EXPECT_DOUBLE_EQ(op.calc(), 12.0);
}

// Test for division using Operator directly
TEST(OperatorClass, Division) {
    Value a(12);
    Value b(4);
    Operator op("/", &a, &b);
    EXPECT_DOUBLE_EQ(op.calc(), 3.0);
}

// Test for division by zero
TEST(OperatorClass, DivisionByZero) {
    Value a(12);
    Value b(0);
    Operator op("/", &a, &b);
    EXPECT_THROW(op.calc(), std::runtime_error);
}

// Test for chained operations
TEST(OperatorClass, ChainedOperations) {
    Value a(3);
    Value b(4);
    Value c(2);
    Operator sum("+", &a, &b); // 3 + 4
    Operator product("*", &sum, &c); // (3 + 4) * 2
    EXPECT_DOUBLE_EQ(product.calc(), 14.0);
}

// Test for negative numbers
TEST(OperatorClass, NegativeNumbers) {
    Value a(-3);
    Value b(4);
    Operator sum("+", &a, &b); // -3 + 4
    EXPECT_DOUBLE_EQ(sum.calc(), 1.0);

    Operator product("*", &a, &b); // -3 * 4
    EXPECT_DOUBLE_EQ(product.calc(), -12.0);
}

// Test for zero as an operand
TEST(OperatorClass, ZeroOperand) {
    Value a(0);
    Value b(4);
    Operator sum("+", &a, &b); // 0 + 4
    EXPECT_DOUBLE_EQ(sum.calc(), 4.0);

    Operator product("*", &a, &b); // 0 * 4
    EXPECT_DOUBLE_EQ(product.calc(), 0.0);
}

// Test for large numbers
TEST(OperatorClass, LargeNumbers) {
    Value a(1e9);
    Value b(2e9);
    Operator sum("+", &a, &b); // 1e9 + 2e9
    EXPECT_DOUBLE_EQ(sum.calc(), 3e9);

    Operator product("*", &a, &b); // 1e9 * 2e9
    EXPECT_DOUBLE_EQ(product.calc(), 2e18);
}

// Test for floating-point precision
TEST(OperatorClass, FloatingPointPrecision) {
    Value a(0.1);
    Value b(0.2);
    Operator sum("+", &a, &b); // 0.1 + 0.2
    EXPECT_NEAR(sum.calc(), 0.3, 1e-9); // Allow for floating-point precision errors
}

// Test for invalid operators
TEST(OperatorClass, InvalidOperator) {
    Value a(3);
    Value b(4);
    EXPECT_THROW(Operator op("?", &a, &b), std::invalid_argument); // Unknown operator
}

// Test for null operands
TEST(OperatorClass, NullOperands) {
    Value a(3);
    EXPECT_THROW(Operator op("+", nullptr, &a), std::invalid_argument); // Left operand is null
    EXPECT_THROW(Operator op("+", &a, nullptr), std::invalid_argument); // Right operand is null
}