#include <gtest/gtest.h>
#include "../../include/Value.h"

// Test for creating a Value object
TEST(ValueClass, CreateValue) {
    Value v(42.0);
    EXPECT_DOUBLE_EQ(v.calc(), 42.0); // Ensure the value is stored correctly
}

// Test for printing a Value object
TEST(ValueClass, PrintValue) {
    Value v(3.14);
    EXPECT_EQ(v.print(), "3.14"); // Ensure the value is printed correctly
}