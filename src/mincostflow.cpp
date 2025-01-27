#include <nanobind/nanobind.h>
#include <nanobind/stl/pair.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include "mincostflow.hpp"

namespace nb = nanobind;
using mcf_graph = atcoder::mcf_graph<long long, long long>;

NB_MODULE(mincostflow, m) {
    auto mcf_graph_class = nb::class_<mcf_graph>(m, "mcf_graph")
    .def(nb::init<>())
    .def(nb::init<int>())
    .def("add_edge", &mcf_graph::add_edge)
    .def("get_edge", &mcf_graph::get_edge)
    .def("edges", &mcf_graph::edges)
    .def("flow", static_cast<std::pair<long long, long long> (mcf_graph::*)(int, int)>(&mcf_graph::flow))
    .def("flow", static_cast<std::pair<long long, long long> (mcf_graph::*)(int, int, long long)>(&mcf_graph::flow))
    .def("slope", static_cast<std::vector<std::pair<long long, long long>> (mcf_graph::*)(int, int)>(&mcf_graph::slope))
    .def("slope", static_cast<std::vector<std::pair<long long, long long>> (mcf_graph::*)(int, int, long long)>(&mcf_graph::slope))
    ;
    nb::class_<mcf_graph::edge>(mcf_graph_class, "edge")
    .def(nb::init<int, int, long long, long long, long long>())
    .def_ro("from_", &mcf_graph::edge::from)
    .def_ro("to", &mcf_graph::edge::to)
    .def_ro("cap", &mcf_graph::edge::cap)
    .def_ro("flow", &mcf_graph::edge::flow)
    .def_ro("cost", &mcf_graph::edge::cost)
    .def("__repr__", [](const mcf_graph::edge& e) {
        return "<edge from_=" + std::to_string(e.from) + " to=" + std::to_string(e.to) + " cap=" + std::to_string(e.cap) + " flow=" + std::to_string(e.flow) + " cost=" + std::to_string(e.cost) + ">";
    })
    ;
}
