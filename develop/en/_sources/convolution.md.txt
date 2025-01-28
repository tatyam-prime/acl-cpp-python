# acl_cpp.convolution

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/convolution.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/convolution.cpp)

```python
from acl_cpp.convolution import convolution998244353, convolution, convolution_ll
from acl_cpp.convolution.internal import butterfly998244353, butterfly, butterfly_inv998244353, butterfly_inv
```

## convolution.convolution998244353

```python
# vector<modint998244353> convolution<998244353>(vector<modint998244353> a, vector<modint998244353> b)
def convolution998244353(a: list[int], b: list[int]) -> list[int]
```

$a, b$ のうちの少なくとも一方が空配列の場合、空配列を返します。  
そうでない場合、以下で定義される長さ $\text{len}(a) + \text{len}(b) - 1$ の配列 $c$ を返します。

$$c[k] = \left(\sum_{i + j = k} a[i] \cdot b[j]\right) \bmod {998244353}$$

**制約**

- <span style="color: red;">$0 \leq a[i], b[i] < 998244353$</span>
- $\text{len}(a) + \text{len}(b) - 1 \le 2^{23}$

$0 \leq a[i], b[i] < 998244353$ を満たさない場合の動作は未定義です。

**計算量**

$n = \text{len}(a) + \text{len}(b)$ として 

- $O(n \log n)$

## convolution.convolution

```python
# dynamic_modint version of convolution
def convolution(a: list[int], b: list[int], p: int) -> list[int]
```

$a, b$ のうちの少なくとも一方が空配列の場合、空配列を返します。  
そうでない場合、以下で定義される長さ $\text{len}(a) + \text{len}(b) - 1$ の配列 $c$ を返します。

$$c[k] = \left(\sum_{i + j = k} a[i] \cdot b[j]\right) \bmod {p}$$

**制約**

- <span style="color: red;">$0 \leq a[i], b[i] < p$</span>
- $2 \le p \lt 2^{31}$
- $p$ は素数
- ある非負整数 $k$ が存在し、$\text{len}(a) + \text{len}(b) - 1 \le 2^k$ かつ $p-1$ が $2^k$ の倍数である

$0 \leq a[i], b[i] < p$ を満たさない場合の動作は未定義です。

**計算量**

$n = \text{len}(a) + \text{len}(b)$ として

- $O(n \log n + \log p)$

## convolution.convolution_ll

```python
# vector<ll> convolution_ll(vector<ll> a, vector<ll> b)
def convolution_ll(a: list[int], b: list[int]) -> list[int]
```

畳み込みを計算します。$a, b$ のうちの少なくとも一方が空配列の場合は空配列を返します。

**制約**

- $\text{len}(a) + \text{len}(b) - 1 \le 2^{24}$
- $-2^{63} \le a[i], b[i] < 2^{63}$
- <span style="color: red;">答えの配列を $c$ として、$-2^{63} \le c[i] < 2^{63}$</span>

$-2^{63} \le c[i] < 2^{63}$ を満たさない場合の動作は未定義です。

**計算量**

$n = \text{len}(a) + \text{len}(b)$ として

- $O(n \log n)$

## convolution.internal

- 参照渡しでリストを変更することができないため、変更後のリストを返しています。
- butterfly 関数は畳み込みや FPS (形式的冪級数) を高速化するのに有用です。
- `butterfly_inv(butterfly(a))` すると各要素が `len(a)` 倍されるので、`len(a)` で割る必要があります。

### convolution.internal.butterfly998244353

```python
# void butterfly<modint998244353>(vector<modint998244353> &a)
def butterfly998244353(a: list[int]) -> list[int]
```

$\text{len}(a) = 2^k$ とし、関数 $\text{bit_reverse}(x)$ を $x$ の下 $k$ ビットを左右反転させた整数とします。  
mod $998244353$ の原始 $2^k$ 乗根を $g$ として、以下で定める長さ $2^k$ の配列 $b$ を返します。

$$b[\text{bit_reverse}(i)] = \left(\sum_{j = 0}^{2^k-1}g^{ij} \cdot a[j]\right)\bmod{998244353}$$

**制約**

- ある整数 $0 \le k \le 23$ が存在し、$\text{len}(a) = 2^k$
- <span style="color: red;">$0 \leq a[i] < 998244353$</span>

$0 \leq a[i] < 998244353$ を満たさない場合の動作は未定義です。

### convolution.internal.butterfly998244353_inv

```python
# void butterfly<modint998244353>(vector<modint998244353> &a)
def butterfly998244353_inv(a: list[int]) -> list[int]
```

$\text{len}(a) = 2^k$ とし、関数 $\text{bit_reverse}(x)$ を $x$ の下 $k$ ビットを左右反転させた整数とします。  
mod $998244353$ の原始 $2^k$ 乗根を $g$ として、以下で定める長さ $2^k$ の配列 $b$ を返します。

$$b[i] = \left(\sum_{j = 0}^{2^k-1}g^{-ij} \cdot a[\text{bit_reverse}(j)]\right) \bmod {998244353}$$

**制約**

- ある整数 $0 \le k \le 23$ が存在し、$\text{len}(a) = 2^k$
- <span style="color: red;">$0 \leq a[i] < 998244353$</span>

$0 \leq a[i] < 998244353$ を満たさない場合の動作は未定義です。

### convolution.internal.butterfly

```python
# dynamic_modint version of butterfly
def butterfly(a: list[int], p: int) -> list[int]
```

$\text{len}(a) = 2^k$ とし、関数 $\text{bit_reverse}(x)$ を $x$ の下 $k$ ビットを左右反転させた整数とします。  
mod $p$ の原始 $2^k$ 乗根を $g$ として、以下で定める長さ $2^k$ の配列 $b$ を返します。

$$b[\text{bit_reverse}(i)] = \left(\sum_{j = 0}^{2^k-1}g^{ij} \cdot a[j]\right)\bmod{p}$$

**制約**

- ある非負整数 $k$ が存在し、$\text{len}(a) = 2^k$ かつ $p-1$ が $2^k$ の倍数
- $2 \le p \lt 2^{31}$
- $p$ は素数
- <span style="color: red;">$0 \leq a[i] < p$</span>

$0 \leq a[i] < p$ を満たさない場合の動作は未定義です。

### convolution.internal.butterfly_inv

```python
# dynamic_modint version of butterfly_inv
def butterfly_inv(a: list[int], p: int) -> list[int]
```

$\text{len}(a) = 2^k$ とし、関数 $\text{bit_reverse}(x)$ を $x$ の下 $k$ ビットを左右反転させた整数とします。
mod $p$ の原始 $2^k$ 乗根を $g$ として、以下で定める長さ $2^k$ の配列 $b$ を返します。

$$b[i] = \left(\sum_{j = 0}^{2^k-1}g^{-ij} \cdot a[\text{bit_reverse}(j)]\right) \bmod {p}$$

**制約**

- ある非負整数 $k$ が存在し、$\text{len}(a) = 2^k$ かつ $p-1$ が $2^k$ の倍数
- $2 \le p \lt 2^{31}$
- $p$ は素数
- <span style="color: red;">$0 \leq a[i] < p$</span>

$0 \leq a[i] < p$ を満たさない場合の動作は未定義です。

## 使用例

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_f>

```python
from acl_cpp.convolution import convolution998244353

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = convolution998244353(A, B)

print(*C)
```

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_f>

```python
from acl_cpp.convolution import convolution

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = convolution(A, B, 998244353)

print(*C)
```
