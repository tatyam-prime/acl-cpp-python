#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h>
#include <nanobind/stl/vector.h>
#include "string.hpp"

NB_MODULE(string, m) {
    m.def("suffix_array", static_cast<std::vector<int> (*)(const std::string&)>(&atcoder::suffix_array));
    m.def("suffix_array", static_cast<std::vector<int> (*)(const std::vector<long long>&)>(&atcoder::suffix_array));
    m.def("suffix_array", static_cast<std::vector<int> (*)(const std::vector<int>&, int)>(&atcoder::suffix_array));
    m.def("lcp_array", static_cast<std::vector<int> (*)(const std::string&, const std::vector<int>&)>(&atcoder::lcp_array));
    m.def("lcp_array", static_cast<std::vector<int> (*)(const std::vector<long long>& s, const std::vector<int>& sa)>(&atcoder::lcp_array));
    m.def("z_algorithm", static_cast<std::vector<int> (*)(const std::string&)>(&atcoder::z_algorithm));
    m.def("z_algorithm", static_cast<std::vector<int> (*)(const std::vector<long long>&)>(&atcoder::z_algorithm));
}
