#include <gtest/gtest.h>
#include "var.h"

// Tests for addition, subtraction, multiplication, and division operations

TEST(VarArithmetic, AdditionInt) {
    var a = 10;
    var b = 20;
    var c = a + b;
    ASSERT_TRUE(c.is_int());
    ASSERT_EQ(c._int(), 30);
}

TEST(VarArithmetic, AdditionDouble) {
    var a = 3.5;
    var b = 2.6;
    var c = a + b;
    ASSERT_TRUE(c.is_double());
    ASSERT_DOUBLE_EQ(c._double(), 6.1);
}

TEST(VarArithmetic, SubtractionInt) {
    var a = 50;
    var b = 20;
    var c = a - b;
    ASSERT_TRUE(c.is_int());
    ASSERT_EQ(c._int(), 30);
}

TEST(VarArithmetic, SubtractionDouble) {
    var a = 5.5;
    var b = 2.2;
    var c = a - b;
    ASSERT_TRUE(c.is_double());
    ASSERT_DOUBLE_EQ(c._double(), 3.3);
}

TEST(VarArithmetic, MultiplicationInt) {
    var a = 5;
    var b = 6;
    var c = a * b;
    ASSERT_TRUE(c.is_int());
    ASSERT_EQ(c._int(), 30);
}

TEST(VarArithmetic, MultiplicationDouble) {
    var a = 2.6;
    var b = 4.0;
    var c = a * b;
    ASSERT_TRUE(c.is_double());
    ASSERT_DOUBLE_EQ(c._double(), 10.4);
}

TEST(VarArithmetic, DivisionInt) {
    var a = 100;
    var b = 4;
    var c = a / b;
    ASSERT_TRUE(c.is_int());
    ASSERT_EQ(c._int(), 25);
}

TEST(VarArithmetic, DivisionDouble) {
    var a = 22.0;
    var b = 7.0;
    var c = a / b;
    ASSERT_TRUE(c.is_double());
    ASSERT_NEAR(c._double(), 3.142857, 1e-6);
}

TEST(VarArithmetic, MixedTypeAddition) {
    var a = 10;
    var b = 3.5;
    var c = a + b;
    ASSERT_TRUE(c.is_double());
    ASSERT_DOUBLE_EQ(c._double(), 13.5);
}

TEST(VarArithmetic, DivisionByZero) {
    var a = 10;
    var b = 0;
    try {
        var c = a / b;
        FAIL() << "Expected division by zero exception";
    } catch (const std::exception &e) {
        SUCCEED();
    }
}
