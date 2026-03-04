#include <gtest/gtest.h>
#include "var.h"

// Tests for equality and relational operators

TEST(VarComparison, EqualityInt) {
    var a = 10;
    var b = 10;
    ASSERT_TRUE(a == b);
    b = 20;
    ASSERT_FALSE(a == b);
}

TEST(VarComparison, EqualityDouble) {
    var a = 3.14;
    var b = 3.14;
    ASSERT_TRUE(a == b);
    b = 2.71;
    ASSERT_FALSE(a == b);
}

TEST(VarComparison, EqualityString) {
    var a = "test";
    var b = "test";
    ASSERT_TRUE(a == b);
    b = "Test";
    ASSERT_FALSE(a == b);
}

TEST(VarComparison, EqualityChar) {
    var a = 'a';
    var b = 'a';
    ASSERT_TRUE(a == b);
    b = 'b';
    ASSERT_FALSE(a == b);
}

TEST(VarComparison, NotEqualOperator) {
    var a = "hello";
    var b = "world";
    ASSERT_TRUE(a != b);
    b = "hello";
    ASSERT_FALSE(a != b);
}

TEST(VarComparison, RelationalInt) {
    var a = 5;
    var b = 10;
    ASSERT_TRUE(a < b);
    ASSERT_TRUE(b > a);
    ASSERT_TRUE(a <= b);
    ASSERT_FALSE(a >= b);
}

TEST(VarComparison, RelationalDouble) {
    var a = 2.5;
    var b = 2.5;
    ASSERT_TRUE(a <= b);
    ASSERT_TRUE(a >= b);
    b = 3.0;
    ASSERT_TRUE(a < b);
    ASSERT_FALSE(a > b);
}

TEST(VarComparison, ComplexComparisons) {
    var a = {1, 2, 3};
    var b = {1, 2, 3};
    ASSERT_FALSE(a == b);
    b = {1, 2, 4};
    ASSERT_FALSE(a == b);
}
