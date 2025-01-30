#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/pair.h>
#include "internal_math.hpp"

NB_MODULE(math, m) {
    using namespace atcoder::internal;
    m.def("is_prime", is_prime_constexpr);
    m.def("primitive_root", primitive_root_constexpr);
}
