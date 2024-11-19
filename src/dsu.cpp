#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include "dsu.hpp"

namespace nb = nanobind;
using atcoder::dsu;

NB_MODULE(dsu, m) {
    nb::class_<dsu>(m, "dsu")
    .def(nb::init<>())
    .def(nb::init<int>())
    .def("merge", &dsu::merge)
    .def("same", &dsu::same)
    .def("leader", &dsu::leader)
    .def("size", &dsu::size)
    .def("groups", &dsu::groups)
    ;
}
