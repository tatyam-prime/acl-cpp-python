cmake_minimum_required(VERSION 3.15...3.27)
project(acl_cpp_python)
set(DEV_MODULE Development.Module)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Python 3.9 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)

# Detect the installed nanobind package and import it into CMake
execute_process(
  COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE nanobind_ROOT)
list(APPEND CMAKE_PREFIX_PATH "${NB_DIR}")
find_package(nanobind CONFIG REQUIRED)

# Set optimization flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -march=native")

nanobind_add_module(convolution NOMINSIZE STABLE_ABI LTO src/convolution.cpp)
nanobind_add_module(dsu NOMINSIZE STABLE_ABI LTO src/dsu.cpp)
nanobind_add_module(fenwicktree NOMINSIZE STABLE_ABI LTO src/fenwicktree.cpp)
nanobind_add_module(math NOMINSIZE STABLE_ABI LTO src/math.cpp)
nanobind_add_module(maxflow NOMINSIZE STABLE_ABI LTO src/maxflow.cpp)
nanobind_add_module(mincostflow NOMINSIZE STABLE_ABI LTO src/mincostflow.cpp)
nanobind_add_module(scc NOMINSIZE STABLE_ABI LTO src/scc.cpp)
nanobind_add_module(string NOMINSIZE STABLE_ABI LTO src/string.cpp)
nanobind_add_module(twosat NOMINSIZE STABLE_ABI LTO src/twosat.cpp)

install(TARGETS dsu fenwicktree math maxflow mincostflow scc string twosat convolution LIBRARY DESTINATION acl_cpp)
install(DIRECTORY src/acl_cpp/ DESTINATION acl_cpp)
