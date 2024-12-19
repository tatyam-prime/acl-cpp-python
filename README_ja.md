# acl-cpp-python

[English](https://github.com/tatyam-prime/acl-cpp-python/blob/main/README.md) | [日本語](https://github.com/tatyam-prime/acl-cpp-python/blob/main/README_ja.md)

acl-cpp-python は、C++ で実装された [AtCoder Library (ACL)](https://github.com/atcoder/ac-library) を [nanobind](https://github.com/wjakob/nanobind) を使用して Python に bind したものです。

## インストール

```bash
pip install acl-cpp-python
```

## 使い方

```python
from acl_cpp.convolution import convolution998244353

a = [1, 1]
b = convolution998244353(a, a)
print(*b)  # 1 2 1
```

## 注意点

- `segtree`, `lazysegtree`, `modint` は高速化が期待できないため、現在実装されていません。
- 整数の大きさに注意してください。`int` 型が要求されている関数には、32 bit 符号付き整数の範囲に収まる値を、`long long` 型が要求されている関数には、64 bit 符号付き整数の範囲に収まる値を渡してください。範囲外の値を入れると、`TypeError` が発生します。
- オーバーフローに注意してください。多くの整数は 64 bit 符号付き整数として実装されているため、この範囲を超える計算を行うとオーバーフローが発生し、結果が間違ったものになります。

## ドキュメント

[AC Library](https://atcoder.github.io/ac-library/production/document_ja/) のドキュメントをお読みください。  
C++ 版との差異を以下に示します。

### データ構造

#### `acl_cpp.fenwicktree`

`T = long long` とした class `fenwicktree.fenwick_tree` が存在します。

#### `acl_cpp.segtree`

存在しません。

#### `acl_cpp.lazysegtree`

存在しません。

#### `acl_cpp.string`

`str` 版と、`T = long long` としたものが存在します。

### 数学

#### `acl_cpp.math`

- `pow_mod` は存在しません。代わりに `pow(x, n, m)` を使用してください。  
- `inv_mod` は存在しません。代わりに `pow(x, -1, m)` を使用してください。 
- `crt(r: list[long long], m: list[long long]) -> (long long, long long):` 存在します。
- `floor_sum(n: long long, m: long long, a: long long, b: long long) -> long long:` 存在します。

#### `acl_cpp.math.internal`

以下が存在します。

- `math.internal.is_prime(n: int) -> bool:`
- `math.internal.primitive_root(m: int) -> int:` 
    - `m` は素数

#### `acl_cpp.convolution`

以下の関数が存在します。

- `convolution.convolution998244353(a: list[int], b: list[int]) -> list[int]:`
    - `a`, `b` の各要素は $0$ 以上 $998244353$ 未満
    - `len(a) + len(b) - 1 <= 2 ** 23`
- `convolution.convolution(a: list[int], b: list[int], mod: int) -> list[int]:`
    - C++ 版に存在しない dynamic_modint の convolution を実装しました。
    - `a`, `b` の各要素は $0$ 以上 `mod` 未満
    - `mod` は素数
    - `(mod - 1) % (2 ** c) == 0` かつ `len(a) + len(b) - 1 <= 2 ** c` となる整数 `c` が存在する
- `convolution.convolution_ll(a: list[long long], b: list[long long]) -> list[long long]:`
    - `len(a) + len(b) - 1 <= 2 ** 23`
    - 畳み込み後の配列の要素が全て `long long` に収まる

#### `acl_cpp.convolution.internal`

以下の関数が存在します。FPS (形式的冪級数) の高速化に有用です。C++ 版と異なり、引数を変更せず新たな配列を返します。

- `convolution.internal.butterfly998244353(a: list[int]) -> list[int]:`
    - `a` の各要素は $0$ 以上 $998244353$ 未満
    - `len(a).bit_count() == 1`
    - `len(a) <= 2 ** 23`
- `convolution.internal.butterfly(a: list[int], mod: int) -> list[int]:`
    - `a` の各要素は $0$ 以上 `mod` 未満
    - `mod` は素数
    - `len(a).bit_count() == 1`
    - `(mod - 1) % len(a) == 0`
- `convolution.internal.butterfly_inv998244353(a: list[int]) -> list[int]:`
    - `a` の各要素は $0$ 以上 $998244353$ 未満
    - `len(a).bit_count() == 1`
    - `len(a) <= 2 ** 23`
- `convolution.internal.butterfly_inv(a: list[int], mod: int) -> list[int]:`
    - `a` の各要素は $0$ 以上 `mod` 未満
    - `mod` は素数
    - `len(a).bit_count() == 1`
    - `(mod - 1) % len(a) == 0` かつ `len(a) <= 2 ** c` となる整数 `c` が存在する

#### `acl_cpp.modint`

存在しません。

### グラフ

#### `acl_cpp.dsu`

`dsu.dsu` が存在します。

#### `acl_cpp.maxflow`

`Cap = long long` としています。  
`maxflow.mf_graph`, `maxflow.mf_graph.edge` が存在します。

#### `acl_cpp.mincostflow`

`Cap = Cost = long long` としています。
`mincostflow.mcf_graph`, `mincostflow.mcf_graph.edge` が存在します。

#### `acl_cpp.scc`

`scc.scc_graph` が存在します。

#### `acl_cpp.twosat`

`twosat.two_sat` が存在します。
