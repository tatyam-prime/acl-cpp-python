#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/pair.h>
#include "math.hpp"
#include "internal_math.hpp"

namespace nb = nanobind;

NB_MODULE(math, m) {
    using namespace atcoder;
    m.def("crt", crt);
    m.def("floor_sum", floor_sum);

    using namespace internal;
    auto internal = m.def_submodule("internal");
    nb::class_<barrett>(internal, "barrett")
    .def(nb::init<unsigned int>())
    .def("umod", &barrett::umod)
    .def("mul", &barrett::mul)
    ;
    internal.def("is_prime", is_prime_constexpr);
    internal.def("inv_gcd", inv_gcd);
    internal.def("primitive_root", primitive_root_constexpr);
}
