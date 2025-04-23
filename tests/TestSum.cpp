#include <gtest/gtest.h>
#include "Sum.h"
#include "Value.h"

TEST(SumTest, SimpleAddition) {
    Value a(3);
    Value b(4);
    Sum sum(&a, &b);
    EXPECT_DOUBLE_EQ(sum.calc(), 7.0);
}