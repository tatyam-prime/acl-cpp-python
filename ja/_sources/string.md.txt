# acl_cpp.string

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/string.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/string.cpp)

```python
from acl_cpp.string import suffix_array, lcp_array, z_algorithm
```

## string.suffix_array

```python
# (1) vector<int> suffix_array(string s)
def suffix_array(s: str) -> list[int]

# (2) vector<int> suffix_array<ll>(vector<ll> s)   
def suffix_array(s: list[int]) -> list[int]

# (3) vector<int> suffix_array(vector<int> s, int upper)
def suffix_array(s: list[int], upper: int) -> list[int]
```

$n = \text{len}(s)$ として、以下で定める長さ $n$ の配列 `sa` を返します。

- `sa` は $(0, 1, \ldots, n-1)$ の順列である
- `s[sa[i]:] < s[sa[i+1]:]` を満たす

**制約**

- (2) $-2^{63} \leq s[i] \lt 2^{63}$
- (3) $0 \leq s[i] \leq \text{upper} \lt 2^{31}$

**計算量**

- (1) $O(n)$
- (2) $O(n \log n)$ 時間, $O(n)$ 空間
- (3) $O(n + \mathrm{upper})$

## string.lcp_array

```python
# (1) vector<int> lcp_array(string s, vector<int> sa)
def lcp_array(s: str, sa: list[int]) -> list[int]

# (2) vector<int> lcp_array<ll>(vector<ll> s, vector<int> sa)
def lcp_array(s: list[int], sa: list[int]) -> list[int]
```

$n = \text{len}(s)$ として、以下で定める長さ $n-1$ の配列 `lcp` を返します。

- `lcp[i]` は `s[sa[i]:]` と `s[sa[i+1]:]` の LCP (Longest Common Prefix) の長さ

**制約**

- <span style="color: red;">`sa` は `s` の Suffix Array である</span>
    - これが満たされない場合の動作は未定義

**計算量**

- $O(n)$

## string.z_algorithm

```python
# (1) vector<int> z_algorithm(string s)
def z_algorithm(s: str) -> list[int]

# (2) vector<int> z_algorithm<ll>(vector<ll> s)
def z_algorithm(s: list[int]) -> list[int]
```

$n = \text{len}(s)$ として、以下で定める長さ $n$ の配列 `z` を返します。

- `z[i]` は `s` と `s[i:]` の LCP (Longest Common Prefix) の長さ

**制約**

- (2) $-2^{63} \leq s[i] \lt 2^{63}$

**計算量**

- $O(n)$

## 使用例

```python
from acl_cpp.string import suffix_array

s = "missisippi"
sa = suffix_array(s)

answer = [
    "i",
    "ippi",
    "isippi",
    "issisippi",
    "missisippi",
    "pi",
    "ppi",
    "sippi",
    "sisippi",
    "ssisippi",
]

for i, t in zip(sa, answer):
    assert s[i:] == t
```

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_i>

```python
from acl_cpp.string import suffix_array, lcp_array

s = input()
n = len(s)
sa = suffix_array(s)
lcp = lcp_array(s, sa)

print(n * (n + 1) // 2 - sum(lcp))
```

