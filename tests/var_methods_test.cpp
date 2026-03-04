#include <gtest/gtest.h>
#include "var.h"

// Tests for methods like size(), empty(), clear(), etc.

TEST(VarMethods, SizeOfString) {
    var a = "hello";
    ASSERT_EQ(a.length(), 5);
}

TEST(VarMethods, SizeOfArray) {
    var a = {1, 2, 3, 4};
    ASSERT_EQ(a.length(), 4);
}

TEST(VarMethods, EmptyOnDefaultVar) {
    var a;
    ASSERT_FALSE(a.is_def()); // Check if the var is undefined
}

TEST(VarMethods, EmptyOnString) {
    var a = "";
    ASSERT_TRUE(a.empty());
}

TEST(VarMethods, EmptyOnArray) {
    var a = var({}); // Initialize as an empty array
    ASSERT_TRUE(a.empty());
}

TEST(VarMethods, ClearMethod) {
    var a = {1, 2, 3};
    a.clear();
    ASSERT_TRUE(a.empty());
    ASSERT_EQ(a.length(), 0);
}

TEST(VarMethods, PushBackMethod) {
    var a = var({}); // Initialize as an empty array
    a.push_back(10);
    ASSERT_EQ(a.length(), 1);
    ASSERT_EQ(a[0], 10);
}

TEST(VarMethods, PopBackMethod) {
    var a = {1, 2, 3};
    a.pop_back();
    ASSERT_EQ(a.length(), 2);
    ASSERT_EQ(a[1], 2);
}

TEST(VarMethods, InsertMethod) {
    var a = {1, 3};
    a.insert(1, 2);
    ASSERT_EQ(a.length(), 3);
    ASSERT_EQ(a[1], 2);
}

TEST(VarMethods, EraseMethod) {
    var a = {1, 2, 3};
    a.erase(1);
    ASSERT_EQ(a.length(), 2);
    ASSERT_EQ(a[1], 3);
}

TEST(VarMethods, ResizeMethod) {
    var a = {1, 2, 3};
    a.resize(5);
    ASSERT_EQ(a.length(), 5);
}

TEST(VarMethods, ReserveMethod) {
    var a = var({}); // Initialize as an empty array
    a.reserve(10);
    ASSERT_TRUE(a.capacity() >= 10);
}

TEST(VarMethods, SwapMethod) {
    var a = var({}); // Initialize as an empty array
    var b = var({}); // Initialize as an empty array
    a.push_back(10);
    b.push_back(20);
    a.swap(b);
    ASSERT_EQ(a[0], 20);
    ASSERT_EQ(b[0], 10);
}

TEST(VarMethods, FrontMethod) {
    var a = {1, 2, 3};
    ASSERT_EQ(a.front(), 1);
}

TEST(VarMethods, BackMethod) {
    var a = {1, 2, 3};
    ASSERT_EQ(a.back(), 3);
}
