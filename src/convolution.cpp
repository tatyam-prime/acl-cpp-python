#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include "convolution.hpp"

namespace nb = nanobind;

NB_MODULE(convolution, m) {
    using namespace atcoder;
    m.def("convolution", static_cast<std::vector<modint998244353> (*)(std::vector<modint998244353>&&, std::vector<modint998244353>&&)>(convolution));
    m.def("convolution", static_cast<std::vector<modint> (*)(std::vector<modint>&&, std::vector<modint>&&)>(convolution));
    m.def("convolution", convolution_dynamic, nb::arg("a"), nb::arg("b"), nb::arg("mod"));
    m.def("convolution_ll", convolution_ll);
    
    auto internal = m.def_submodule("internal");
    using namespace internal;
    internal.def("butterfly", [](std::vector<modint998244353> a) { butterfly(a); return a; });
    internal.def("butterfly", [](std::vector<modint> a) { butterfly(a); return a; });
    internal.def("butterfly_inv", [](std::vector<modint998244353> a) { butterfly_inv(a); return a; });
    internal.def("butterfly_inv", [](std::vector<modint> a) { butterfly_inv(a); return a; });
}
