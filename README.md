# acl-cpp-python

[English](https://github.com/tatyam-prime/acl-cpp-python/blob/main/README.md) | [日本語](https://github.com/tatyam-prime/acl-cpp-python/blob/main/README_ja.md)

`acl-cpp-python` is a Python binding for the [AtCoder Library (ACL)](https://github.com/atcoder/ac-library) implemented in C++, using [nanobind](https://github.com/wjakob/nanobind).

## Installation

```bash
pip install acl-cpp-python
```

## Usage

```python
from acl_cpp.convolution import convolution998244353

a = [1, 1]
b = convolution998244353(a, a)
print(*b)  # 1 2 1
```

## Notes

- `segtree`, `lazysegtree`, and `modint` are not implemented as they are unlikely to offer performance improvements.
- Be mindful of integer size. Functions requiring `int` must receive values within the range of 32-bit signed integers, and functions requiring `long long` must receive values within the range of 64-bit signed integers. Passing values outside these ranges will raise a `TypeError`.
- Watch out for overflow. Many integers are implemented as 64-bit signed integers. Calculations exceeding this range will result in overflow and produce incorrect results.

## Documentation

Refer to the [AC Library documentation](https://atcoder.github.io/ac-library/production/document_en/).  
The differences from the C++ version are outlined below.

### Data Structures

#### `acl_cpp.fenwicktree`

Contains a class `fenwicktree.fenwick_tree` where `T = long long`.

#### `acl_cpp.segtree`

Not available.

#### `acl_cpp.lazysegtree`

Not available.

#### `acl_cpp.string`

Includes implementations for `str` and `T = long long`.

### Mathematics

#### `acl_cpp.math`

- `pow_mod` is not available. Use `pow(x, n, m)` instead.
- `inv_mod` is not available. Use `pow(x, -1, m)` instead.
- `crt(r: list[long long], m: list[long long]) -> (long long, long long)` is available.
- `floor_sum(n: long long, m: long long, a: long long, b: long long) -> long long` is available.

#### `acl_cpp.math.internal`

The following functions are available:

- `math.internal.is_prime(n: int) -> bool`
- `math.internal.primitive_root(m: int) -> int`  
  - `m` must be a prime number.

#### `acl_cpp.convolution`

The following functions are available:

- `convolution.convolution998244353(a: list[int], b: list[int]) -> list[int]`  
  - Each element of `a` and `b` must be in the range [0, 998244353).
  - `len(a) + len(b) - 1 <= 2 ** 23`.
- `convolution.convolution(a: list[int], b: list[int], mod: int) -> list[int]`  
  - Implements convolution for dynamic_modint, which is not available in the C++ version.
  - Each element of `a` and `b` must be in the range [0, mod).
  - `mod` must be a prime number.
  - There must exist an integer `c` such that `(mod - 1) % (2 ** c) == 0` and `len(a) + len(b) - 1 <= 2 ** c`.
- `convolution.convolution_ll(a: list[long long], b: list[long long]) -> list[long long]`  
  - `len(a) + len(b) - 1 <= 2 ** 23`.
  - All elements of the resulting array fit within `long long`.

#### `acl_cpp.convolution.internal`

These functions are useful for optimizing formal power series (FPS). Unlike the C++ version, they return new arrays instead of modifying arguments.

- `convolution.internal.butterfly998244353(a: list[int]) -> list[int]`  
  - Each element of `a` must be in the range [0, 998244353).
  - `len(a).bit_count() == 1`.
  - `len(a) <= 2 ** 23`.
- `convolution.internal.butterfly(a: list[int], mod: int) -> list[int]`  
  - Each element of `a` must be in the range [0, mod).
  - `mod` must be a prime number.
  - `len(a).bit_count() == 1`.
  - `(mod - 1) % len(a) == 0`.
- `convolution.internal.butterfly_inv998244353(a: list[int]) -> list[int]`  
  - Each element of `a` must be in the range [0, 998244353).
  - `len(a).bit_count() == 1`.
  - `len(a) <= 2 ** 23`.
- `convolution.internal.butterfly_inv(a: list[int], mod: int) -> list[int]`  
  - Each element of `a` must be in the range [0, mod).
  - `mod` must be a prime number.
  - `len(a).bit_count() == 1`.
  - There must exist an integer `c` such that `(mod - 1) % len(a) == 0` and `len(a) <= 2 ** c`.

#### `acl_cpp.modint`

Not available.

### Graphs

#### `acl_cpp.dsu`

`dsu.dsu` is available.

#### `acl_cpp.maxflow`

Implemented with `Cap = long long`.  
`maxflow.mf_graph` and `maxflow.mf_graph.edge` are available.

#### `acl_cpp.mincostflow`

Implemented with `Cap = Cost = long long`.  
`mincostflow.mcf_graph` and `mincostflow.mcf_graph.edge` are available.

#### `acl_cpp.scc`

`scc.scc_graph` is available.

#### `acl_cpp.twosat`

`twosat.two_sat` is available.
