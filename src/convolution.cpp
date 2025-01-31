#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include "convolution.hpp"

using namespace atcoder;
auto convolution998244353 =
    static_cast<std::vector<modint998244353> (*)(std::vector<modint998244353>&&, std::vector<modint998244353>&&)>(convolution);
std::vector<modint> convolution_dynamic(std::vector<modint>&& a, std::vector<modint>&& b, int p) {
    assert(internal::is_prime_constexpr(p));
    modint::set_mod(p);
    return convolution(std::move(a), std::move(b));
}

NB_MODULE(convolution, m) {
    m.def("convolution998244353",
          reinterpret_cast<std::vector<int> (*)(std::vector<int>&&, std::vector<int>&&)>(convolution998244353));
    m.def("convolution",
          reinterpret_cast<std::vector<int> (*)(std::vector<int>&&, std::vector<int>&&, int)>(convolution_dynamic));
    m.def("convolution_ll", convolution_ll);
}
