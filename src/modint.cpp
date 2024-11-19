#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include "modint.hpp"

namespace nb = nanobind;

template<class T> auto make_modint(nanobind::module_& m, std::string type) {
    return nb::class_<T>(m, type.c_str())
    .def_static("mod", &T::mod)
    .def_static("raw", &T::raw)
    .def(nb::init<>())
    .def(nb::init<long long>())
    .def("val", &T::val)
    .def("__iadd__", &T::operator+=)
    .def("__isub__", &T::operator-=)
    .def("__imul__", &T::operator*=)
    .def("__itruediv__", &T::operator/=)
    .def("__ipow__", [](T& self, long long n) { return self = self.pow(n); })
    .def("__pos__", &T::operator+)
    .def("__neg__", &T::operator-)
    .def("pow", &T::pow)
    .def("inv", &T::inv)
    .def("__add__", &T::add)
    .def("__sub__", &T::sub)
    .def("__mul__", &T::mul)
    .def("__truediv__", &T::div)
    .def("__pow__", &T::pow)
    .def("__eq__", &T::eq)
    .def("__ne__", &T::ne)
    .def("__str__", [](const T& self) { return std::to_string(self.val()); })
    .def("__repr__", [type](const T& self) { return type + "(" + std::to_string(self.val()) + ")"; })
    ;
};
template<class T> auto make_dynamic_modint(nanobind::module_& m, std::string type) {
    return make_modint<T>(m, type)
    .def_static("set_mod", &T::set_mod)
    ;
}
NB_MODULE(modint, m) {
    using namespace atcoder;
    make_modint<modint998244353>(m, "modint998244353");
    make_modint<modint1000000007>(m, "modint1000000007");
    make_dynamic_modint<modint>(m, "modint");
}

