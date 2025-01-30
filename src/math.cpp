#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/pair.h>
#include "math.hpp"
#include "internal_math.hpp"

NB_MODULE(math, m) {
    using namespace atcoder;
    m.def("crt", crt);
    m.def("floor_sum", floor_sum);

    using namespace internal;
    auto internal = m.def_submodule("internal");
    internal.def("is_prime", is_prime_constexpr);
    internal.def("primitive_root", primitive_root_constexpr);
}
