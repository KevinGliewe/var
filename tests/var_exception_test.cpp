#include <gtest/gtest.h>
#include <climits>
#include "var.h"

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

TEST(VarExceptionHandling, ReserveOverflow) {
    var a = "hello";
    try {
        a.reserve(ULLONG_MAX);
        FAIL() << "Expected length_error or capacity_error exception";
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
