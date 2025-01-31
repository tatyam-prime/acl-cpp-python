#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include <nanobind/stl/pair.h>
#include "math.hpp"

NB_MODULE(math, m) {
    using namespace atcoder;
    m.def("crt", crt);
    m.def("floor_sum", floor_sum);
}
