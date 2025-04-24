#include <gtest/gtest.h>
#include "../../include/Operator.h"
#include "../../include/Value.h"

TEST(OperatorClass, Addition) {
    Value a(3);
    Value b(4);
    Operator op("+", &a, &b);
    EXPECT_DOUBLE_EQ(op.calc(), 7.0);
}

TEST(OperatorClass, Subtraction) {
    Value a(10);
    Value b(4);
    Operator op("-", &a, &b);
    EXPECT_DOUBLE_EQ(op.calc(), 6.0);
}

TEST(OperatorClass, Multiplication) {
    Value a(3);
    Value b(4);
    Operator op("*", &a, &b);
    EXPECT_DOUBLE_EQ(op.calc(), 12.0);
}

TEST(OperatorClass, Division) {
    Value a(12);
    Value b(4);
    Operator op("/", &a, &b);
    EXPECT_DOUBLE_EQ(op.calc(), 3.0);
}

TEST(OperatorClass, DivisionByZero) {
    Value a(12);
    Value b(0);
    Operator op("/", &a, &b);
    EXPECT_THROW(op.calc(), std::runtime_error);
}

TEST(OperatorClass, ChainedOperations) {
    Value a(3);
    Value b(4);
    Value c(2);
    Operator sum("+", &a, &b); 
    Operator product("*", &sum, &c); 
    EXPECT_DOUBLE_EQ(product.calc(), 14.0);
}

TEST(OperatorClass, NegativeNumbers) {
    Value a(-3);
    Value b(4);
    Operator sum("+", &a, &b); 
    EXPECT_DOUBLE_EQ(sum.calc(), 1.0);

    Operator product("*", &a, &b); 
    EXPECT_DOUBLE_EQ(product.calc(), -12.0);
}

TEST(OperatorClass, ZeroOperand) {
    Value a(0);
    Value b(4);
    Operator sum("+", &a, &b); 
    EXPECT_DOUBLE_EQ(sum.calc(), 4.0);

    Operator product("*", &a, &b); 
    EXPECT_DOUBLE_EQ(product.calc(), 0.0);
}

TEST(OperatorClass, LargeNumbers) {
    Value a(1e9);
    Value b(2e9);
    Operator sum("+", &a, &b); 
    EXPECT_DOUBLE_EQ(sum.calc(), 3e9);

    Operator product("*", &a, &b); 
    EXPECT_DOUBLE_EQ(product.calc(), 2e18);
}

TEST(OperatorClass, FloatingPointPrecision) {
    Value a(0.1);
    Value b(0.2);
    Operator sum("+", &a, &b); 
    EXPECT_NEAR(sum.calc(), 0.3, 1e-9); 
}

TEST(OperatorClass, InvalidOperator) {
    Value a(3);
    Value b(4);
    EXPECT_THROW(Operator op("?", &a, &b), std::invalid_argument); 
}

TEST(OperatorClass, NullOperands) {
    Value a(3);
    EXPECT_THROW(Operator op("+", nullptr, &a), std::invalid_argument);
    EXPECT_THROW(Operator op("+", &a, nullptr), std::invalid_argument);
}