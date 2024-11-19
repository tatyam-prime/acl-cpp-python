#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include "scc.hpp"

namespace nb = nanobind;

NB_MODULE(scc, m) {
    using namespace atcoder;

    nb::class_<scc_graph>(m, "scc_graph")
    .def(nb::init<>())
    .def(nb::init<int>())
    .def("add_edge", &scc_graph::add_edge)
    .def("scc", &scc_graph::scc)
    ;
}
