#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include "convolution.hpp"

using namespace atcoder;
std::vector<modint998244353> butterfly998244353(std::vector<modint998244353> a) {
    butterfly(a);
    return a;
}
std::vector<modint> butterfly_dynamic(std::vector<modint> a, int mod) {
    modint::set_mod(mod);
    butterfly(a);
    return a;
}
std::vector<modint998244353> butterfly_inv998244353(std::vector<modint998244353> a) {
    butterfly_inv(a);
    return a;
}
std::vector<modint> butterfly_inv_dynamic(std::vector<modint> a, int mod) {
    modint::set_mod(mod);
    butterfly_inv(a);
    return a;
}
auto convolution998244353 =
    static_cast<std::vector<modint998244353> (*)(std::vector<modint998244353>&&, std::vector<modint998244353>&&)>(convolution);
std::vector<modint> convolution_dynamic(std::vector<modint>&& a, std::vector<modint>&& b, int mod) {
    modint::set_mod(mod);
    return convolution(std::move(a), std::move(b));
}

NB_MODULE(convolution, m) {
    m.def("convolution998244353",
          reinterpret_cast<std::vector<int> (*)(std::vector<int>&&, std::vector<int>&&)>(convolution998244353));
    m.def("convolution",
          reinterpret_cast<std::vector<int> (*)(std::vector<int>&&, std::vector<int>&&, int)>(convolution_dynamic));
    m.def("convolution_ll", convolution_ll);

    auto internal = m.def_submodule("internal");
    using namespace internal;
    internal.def("butterfly998244353",
                 reinterpret_cast<std::vector<int> (*)(std::vector<int>)>(butterfly998244353));
    internal.def("butterfly",
                 reinterpret_cast<std::vector<int> (*)(std::vector<int>, int)>(butterfly_dynamic));
    internal.def("butterfly_inv998244353",
                 reinterpret_cast<std::vector<int> (*)(std::vector<int>)>(butterfly_inv998244353));
    internal.def("butterfly_inv",
                 reinterpret_cast<std::vector<int> (*)(std::vector<int>, int)>(butterfly_inv_dynamic));
}
