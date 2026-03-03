#include <gtest/gtest.h>
#include "var.h"

// Tests for implicit and explicit type conversions

TEST(VarTypeConversion, ImplicitIntToDouble) {
    var a = 42;
    double b = a;
    ASSERT_DOUBLE_EQ(b, 42.0);
}

TEST(VarTypeConversion, ImplicitDoubleToInt) {
    var a = 3.99;
    int b = a;
    ASSERT_EQ(b, 3); // Expected truncation
}

TEST(VarTypeConversion, ExplicitVarToInt) {
    var a = "123";
    int b = a._int();
    ASSERT_EQ(b, 123);
}

TEST(VarTypeConversion, ExplicitVarToDouble) {
    var a = "3.14";
    double b = a._double();
    ASSERT_DOUBLE_EQ(b, 3.14);
}

TEST(VarTypeConversion, ImplicitCharToVar) {
    char c = 'A';
    var a = c;
    ASSERT_TRUE(a.is_char());
    ASSERT_EQ(a, 'A');
}

TEST(VarTypeConversion, ImplicitStringToVar) {
    std::string s = "test";
    var a = s;
    ASSERT_TRUE(a.is_str());
    ASSERT_EQ(a, "test");
}

TEST(VarTypeConversion, CastVarToString) {
    var a = "hello";
    std::string s = a._str();
    ASSERT_EQ(s, "hello");
}

TEST(VarTypeConversion, BoolToIntConversion) {
    var a = true;
    int b = a;
    ASSERT_EQ(b, 1);
}

TEST(VarTypeConversion, IntToBoolConversion) {
    var a = 0;
    bool b = a;
    ASSERT_FALSE(b);
}

TEST(VarTypeConversion, VarToCharConversion) {
    var a = 65;
    char c = a;
    ASSERT_EQ(c, 'A');
}
