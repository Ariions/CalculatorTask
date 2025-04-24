#include <gtest/gtest.h>
#include "../../include/Value.h"

TEST(ValueClass, CreateValue) {
    Value v(42.0);
    EXPECT_DOUBLE_EQ(v.calc(), 42.0);
}

TEST(ValueClass, PrintValue) {
    Value v(3.14);
    EXPECT_EQ(v.print(), "3.14");
}