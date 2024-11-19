#ifndef NANOBIND_ASSERT_HPP
#define NANOBIND_ASSERT_HPP

#include <cassert>
#include <nanobind/nanobind.h>

#undef assert
#define assert(...) if (!( __VA_ARGS__ )) { throw nanobind::value_error("Assertion failed: " #__VA_ARGS__); }

#endif
