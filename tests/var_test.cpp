#include <gtest/gtest.h>
#include "var.h"

#pragma region Constructor and Assignment Tests
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

#pragma endregion

#pragma region Type Conversion Tests
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

#pragma endregion

#pragma region Arithmetic Operation Tests
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

#pragma endregion

#pragma region Comparison Operator Tests
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

#pragma endregion

#pragma region Method Tests
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

#pragma endregion

#pragma region Exception Handling Tests
// Tests for exception handling and error conditions

TEST(VarExceptionHandling, OutOfRangeAccess) {
    var a = {1, 2, 3};
    try {
        var b = a.at(5);
        FAIL() << "Expected out_of_range exception";
    } catch (const std::exception &e) {
        SUCCEED();
    }
}

TEST(VarExceptionHandling, UseOfUndefinedVar) {
    var a;
    try {
        bool isEmpty = a.empty();
        FAIL() << "Expected use_of_undefined_var exception";
    } catch (const std::exception &e) {
        SUCCEED();
    }
}

TEST(VarExceptionHandling, UnsupportedInterface) {
    var a = 10;
    try {
        a.push_back(20);
        FAIL() << "Expected unsupported_interface exception";
    } catch (const std::exception &e) {
        SUCCEED();
    }
}

TEST(VarExceptionHandling, LengthError) {
    var a = "hello";
    try {
        a.reserve(ULLONG_MAX);
        FAIL() << "Expected length_error exception";
    } catch (const std::exception &e) {
        SUCCEED();
    }
}

TEST(VarExceptionHandling, CapacityError) {
    var a = "hello";
    try {
        a.reserve(ULLONG_MAX);
        FAIL() << "Expected capacity_error exception";
    } catch (const std::exception &e) {
        SUCCEED();
    }
}

TEST(VarExceptionHandling, BadIterator) {
    var a = {1, 2, 3};
    try {
        var b = a.insert(1, a.end(), a.begin());
        FAIL() << "Expected bad_iterator exception";
    } catch (const std::exception &e) {
        SUCCEED();
    }
}

#pragma endregion

