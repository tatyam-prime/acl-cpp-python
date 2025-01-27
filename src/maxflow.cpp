#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/string.h>
#include "maxflow.hpp"

namespace nb = nanobind;
using mf_graph = atcoder::mf_graph<long long>;

NB_MODULE(maxflow, m) {
    auto mf_graph_class = nb::class_<mf_graph>(m, "mf_graph")
    .def(nb::init<>())
    .def(nb::init<int>())
    .def("add_edge", &mf_graph::add_edge)
    .def("get_edge", &mf_graph::get_edge)
    .def("edges", &mf_graph::edges)
    .def("change_edge", &mf_graph::change_edge)
    .def("flow", &mf_graph::flow2)
    .def("flow", &mf_graph::flow)
    .def("min_cut", &mf_graph::min_cut)
    ;
    nb::class_<mf_graph::edge>(mf_graph_class, "edge")
    .def(nb::init<int, int, long long, long long>())
    .def_ro("from_", &mf_graph::edge::from)
    .def_ro("to", &mf_graph::edge::to)
    .def_ro("cap", &mf_graph::edge::cap)
    .def_ro("flow", &mf_graph::edge::flow)
    .def("__repr__", [](const mf_graph::edge& e) {
        return "<edge from_=" + std::to_string(e.from) + " to=" + std::to_string(e.to) + " cap=" + std::to_string(e.cap) + " flow=" + std::to_string(e.flow) + ">";
    })
    ;

}
