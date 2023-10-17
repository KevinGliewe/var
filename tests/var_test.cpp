#include <gtest/gtest.h>
#include "var.h"

TEST(Var, Simple_Int)
{
    var a = 1;

    ASSERT_EQ(a, 1);
}

TEST(Var, Simple_Float)
{
    var a = 1.1;

    ASSERT_EQ(a, 1.1);
}