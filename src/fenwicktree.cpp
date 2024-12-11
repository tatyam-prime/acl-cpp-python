#include <nanobind/nanobind.h>
#include "fenwicktree.hpp"
#include "modint.hpp"

namespace nb = nanobind;

NB_MODULE(fenwicktree, m) {
    using namespace atcoder;
    using fenwick_tree = fenwick_tree<long long>;

    nb::class_<fenwick_tree>(m, "fenwick_tree")
    .def(nb::init<>())
    .def(nb::init<int>())
    .def("add", &fenwick_tree::add)
    .def("sum", static_cast<long long (fenwick_tree::*)(int, int)>(&fenwick_tree::sum))
    ;
}
