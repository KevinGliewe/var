#include <gtest/gtest.h>
#include "var.h"

// Tests for constructors and assignment operators

TEST(VarConstructor, DefaultConstructor) {
    var a;
    ASSERT_FALSE(a.is_def());
}

TEST(VarConstructor, IntConstructor) {
    var a(42);
    ASSERT_TRUE(a.is_int());
    ASSERT_EQ(a._int(), 42);
}

TEST(VarConstructor, DoubleConstructor) {
    var a(3.14);
    ASSERT_TRUE(a.is_double());
    ASSERT_DOUBLE_EQ(a._double(), 3.14);
}

TEST(VarConstructor, BoolConstructor) {
    var a(true);
    ASSERT_TRUE(a.is_bool());
    ASSERT_EQ(a, true);
}

TEST(VarConstructor, CharConstructor) {
    var a('c');
    ASSERT_TRUE(a.is_char());
    ASSERT_EQ(a, 'c');
}

TEST(VarConstructor, StringConstructor) {
    var a("hello");
    ASSERT_TRUE(a.is_str());
    ASSERT_STREQ(((std::string)a._str()).c_str(), "hello");
}

TEST(VarConstructor, ArrayConstructor) {
    var a = {1, 2, 3, 4, 5};
    ASSERT_TRUE(a.is_arr());
    ASSERT_EQ(a.size(), 5 * sizeof(int) + sizeof(int));
    ASSERT_EQ(a[0], 1);
    ASSERT_EQ(a[4], 5);
}

TEST(VarConstructor, NestedArrayConstructor) {
    var a = {1, {2, {3, 4}}, 5};
    ASSERT_TRUE(a.is_arr());
    ASSERT_TRUE(a[1].is_arr());
    ASSERT_TRUE(a[1][1].is_arr());
    ASSERT_EQ(a[1][1][0], 3);
    ASSERT_EQ(a[1][1][1], 4);
}

TEST(VarAssignment, IntAssignment) {
    var a;
    a = 99;
    ASSERT_TRUE(a.is_int());
    ASSERT_EQ(a._int(), 99);
}

TEST(VarAssignment, StringAssignment) {
    var a;
    a = std::string("test");
    ASSERT_TRUE(a.is_str());
    ASSERT_STREQ(((std::string)a._str()).c_str(), "test");
}
