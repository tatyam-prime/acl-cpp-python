#include <nanobind/nanobind.h>
#include <nanobind/stl/vector.h>
#include "convolution.hpp"

using namespace atcoder;
using namespace internal;
std::vector<modint998244353> butterfly998244353(std::vector<modint998244353> a) {
    if (a.empty()) return a;
    assert((a.size() & (a.size() - 1)) == 0);
    assert((modint998244353::mod() - 1) % a.size() == 0);
    butterfly(a);
    return a;
}
std::vector<modint> butterfly_dynamic(std::vector<modint> a, int p) {
    if (a.empty()) return a;
    assert((a.size() & (a.size() - 1)) == 0);
    assert((p - 1) % a.size() == 0);
    assert(is_prime_constexpr(p));
    modint::set_mod(p);
    butterfly(a);
    return a;
}
std::vector<modint998244353> butterfly_inv998244353(std::vector<modint998244353> a) {
    if (a.empty()) return a;
    assert((a.size() & (a.size() - 1)) == 0);
    assert((modint998244353::mod() - 1) % a.size() == 0);
    butterfly_inv(a);
    return a;
}
std::vector<modint> butterfly_inv_dynamic(std::vector<modint> a, int p) {
    if (a.empty()) return a;
    assert((a.size() & (a.size() - 1)) == 0);
    assert((p - 1) % a.size() == 0);
    assert(is_prime_constexpr(p));
    modint::set_mod(p);
    butterfly_inv(a);
    return a;
}

NB_MODULE(convolution, m) {
    m.def("butterfly998244353",
                 reinterpret_cast<std::vector<int> (*)(std::vector<int>)>(butterfly998244353));
    m.def("butterfly",
                 reinterpret_cast<std::vector<int> (*)(std::vector<int>, int)>(butterfly_dynamic));
    m.def("butterfly_inv998244353",
                 reinterpret_cast<std::vector<int> (*)(std::vector<int>)>(butterfly_inv998244353));
    m.def("butterfly_inv",
                 reinterpret_cast<std::vector<int> (*)(std::vector<int>, int)>(butterfly_inv_dynamic));
}
