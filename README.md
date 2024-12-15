# acl-cpp-python

English | [日本語](https://github.com/tatyam-prime/acl-cpp-python/blob/main/README_ja.md)

`acl-cpp-python` is a Python binding of the [AtCoder Library (ACL)](https://github.com/atcoder/ac-library) implemented in C++ using [nanobind](https://github.com/wjakob/nanobind).

## Installation

```bash
pip install acl-cpp-python
```

## Example

```python
from acl_cpp.convolution import convolution998244353

a = [1, 1]
b = convolution998244353(a, a)
print(*b)  # 1 2 1
```

## Notes

- `segtree` and `lazysegtree` are not currently implemented. These structures abstract types and operations, and performance improvement is not expected if implemented in Python.
    - Please use Python implementations of segment trees, such as <https://github.com/shakayami/ACL-for-python> or <https://github.com/not522/ac-library-python>.
- Be mindful of integer sizes. Refer to the [AC Library documentation](https://atcoder.github.io/ac-library/production/document_ja/) and ensure that for functions requiring the `int` type, the input values fall within the range of 32-bit signed integers, and for those requiring the `long long` type, the input values fall within the range of 64-bit signed integers. A `TypeError` will occur for out-of-range values.
- Be cautious of overflow. Most integers are implemented as 64-bit signed integers, and calculations exceeding this range may result in overflow and incorrect results.

## Documentation

Refer to the [AC Library documentation](https://atcoder.github.io/ac-library/production/document_ja/).  
Differences from the C++ version are outlined below.

### Data Structures

#### `acl_cpp.fenwicktree`

Includes the class `fenwicktree.fenwick_tree` with `T = long long` and `fenwicktree.fenwick_tree_modint` with `T = modint`.

#### `acl_cpp.segtree`

Not available.

#### `acl_cpp.lazysegtree`

Not available.

#### `acl_cpp.string`

Includes a string version and one with `T = long long`.

### Mathematics

#### `acl_cpp.math`

- `pow_mod` is not available. Use `pow(x, n, m)` instead.
- `inv_mod` is not available. Use `pow(x, -1, m)` instead.

#### `acl_cpp.math.internal`

The following are available:

- `math.internal.barrett`  
    - <https://github.com/atcoder/ac-library/blob/fe9b6fca9ab4e1be946ea23a4e6a2a751cf4aaa2/atcoder/internal_math.hpp#L25>
- `math.internal.is_prime(n: int) -> bool:`  
    - <https://github.com/atcoder/ac-library/blob/fe9b6fca9ab4e1be946ea23a4e6a2a751cf4aaa2/atcoder/internal_math.hpp#L83>
- `math.internal.inv_gcd(a: long long, b: long long) -> (long long, long long):`  
    - <https://github.com/atcoder/ac-library/blob/fe9b6fca9ab4e1be946ea23a4e6a2a751cf4aaa2/atcoder/internal_math.hpp#L107>
- `math.internal.primitive_root(m: int) -> int:`  
    - <https://github.com/atcoder/ac-library/blob/fe9b6fca9ab4e1be946ea23a4e6a2a751cf4aaa2/atcoder/internal_math.hpp#L144C15-L144C29>

#### `acl_cpp.convolution`

The following functions are available:

- `convolution.convolution(a: list[modint.modint998244353], b: list[modint.modint998244353]) -> list[modint.modint998244353]:`
- `convolution.convolution(a: list[modint.modint], b: list[modint.modint]) -> list[modint.modint]:`
    - Implements convolution for `modint`, not present in the C++ version.
    - Note the condition for NTT-friendly mods: `(mod - 1) % (2 ** c) == 0` and `len(a) + len(b) - 1 <= 2 ** c`.
- `convolution.convolution(a: list[long long], b: list[long long], mod: int) -> list[long long]:`
    - Specify `mod` as the third argument for integer mod convolution.
    - Ensure the mod satisfies the NTT-friendly condition above.
- `convolution.convolution_ll(a: list[long long], b: list[long long]) -> list[long long]:`

#### `acl_cpp.convolution.internal`

The following functions, useful for accelerating FPS (Formal Power Series) computations, are available.  
Unlike the C++ version, they do not modify the arguments and return values.

- `convolution.internal.butterfly(a: list[modint.modint998244353]) -> list[modint.modint998244353]:`
- `convolution.internal.butterfly(a: list[modint.modint]) -> list[modint.modint]:`
- `convolution.internal.butterfly_inv(a: list[modint.modint998244353]) -> list[modint.modint998244353]:`
- `convolution.internal.butterfly_inv(a: list[modint.modint]) -> list[modint.modint]:`

#### `acl_cpp.modint`

Includes `modint.modint998244353`, `modint.modint1000000007`, and `modint.modint`.  
`static_modint` and `dynamic_modint` are not available.  
TODO: Add support for creating multiple `dynamic_modint`.

Supports the notation `modint(10) ** 10`.  
`str(modint(10))` converts the value directly to a string.

### Graph

#### `acl_cpp.dsu`

Includes `dsu.dsu`.

#### `acl_cpp.maxflow`

`Cap = long long`.  
Includes `maxflow.mf_graph` and `maxflow.mf_graph.edge`.

#### `acl_cpp.mincostflow`

`Cap = Cost = long long`.  
Includes `mincostflow.mcf_graph` and `mincostflow.mcf_graph.edge`.

#### `acl_cpp.scc`

Includes `scc.scc_graph`.

#### `acl_cpp.twosat`

Includes `twosat.two_sat`.
