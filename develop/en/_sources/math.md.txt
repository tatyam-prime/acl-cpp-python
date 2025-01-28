# acl_cpp.math

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/math.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/math.cpp)

```python
from acl_cpp.math import crt, floor_sum
from acl_cpp.math.internal import is_prime, primitive_root
```

## pow_mod

`pow(x, n, mod)` を使用してください。

## inv_mod

`pow(x, -1, mod)` を使用してください。

## math.crt

```python
# pair<ll, ll> crt(vector<ll> r, vector<ll> m)
def crt(r: list[int], m: list[int]) -> tuple[int, int]
```

同じ長さの配列 $r, m$ を渡します。この配列の長さを $n$ とした時、

$$x \equiv r[i] \pmod{m[i]}, \forall i \in \lbrace 0,1,\cdots, n - 1 \rbrace$$

を解きます。答えは(存在するならば) $y, z (0 \leq y < z = \mathrm{lcm}(m[i]))$ を用いて $x \equiv y \pmod z$ の形で書けることが知られており、この $(y, z)$ をpairとして返します。答えがない場合は $(0, 0)$ を返します。$n=0$ の時は $(0, 1)$ を返します。

**制約**

- $\text{len}(r) = \text{len}(m)$
- $-2^{63} \le r[i] < 2^{63}$
- $1 \le m[i] < 2^{63}$
- <span style="color: red;">$\mathrm{lcm}(m[i]) < 2^{63}$</span>

$\mathrm{lcm}(m[i]) < 2^{63}$ を満たさない場合の動作は未定義です。

**計算量**

- $O(n \log \mathrm{lcm}(m[i]))$

## math.floor_sum

```python
# ll floor_sum(ll n, ll m, ll a, ll b)
def floor_sum(n: int, m: int, a: int, b: int) -> int
```

<span></span>

$$\sum_{i = 0}^{n - 1} \left\lfloor \frac{a \times i + b}{m} \right\rfloor$$

を返します。答えが **64 bit 符号付き整数型**に収まらない場合、mod $2^{64}$ で等しい値を返します。

**制約**

- $0 \le n \lt 2^{32}$
- $1 \le m \lt 2^{32}$

**計算量**

- $O(\log m)$

## math.internal

### math.internal.is_prime

```python
# bool is_prime_constexpr(int n)
def is_prime(n: int) -> bool
```

$n$ が素数かどうかを返す。

**制約**

- $0 \le n < 2^{31}$

### math.internal.primitive_root

```python
# int primitive_root_constexpr(int m)
def primitive_root(m: int) -> int
```

mod $m$ における原始根の $1$ つを返す。

**制約**

- $2 \le m < 2^{31}$
- $m$ は素数

### 使用例

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_c>

```python
from acl_cpp.math import floor_sum

T = int(input())
for _ in range(T):
    N, M, A, B = map(int, input().split())
    print(floor_sum(N, M, A, B))
```
