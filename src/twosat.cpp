#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include "twosat.hpp"

namespace nb = nanobind;

NB_MODULE(twosat, m) {
    using namespace atcoder;

    nb::class_<two_sat>(m, "two_sat")
    .def(nb::init<>())
    .def(nb::init<int>())
    .def("add_clause", &two_sat::add_clause)
    .def("satisfiable", &two_sat::satisfiable)
    .def("answer", &two_sat::answer)
    ;
}
