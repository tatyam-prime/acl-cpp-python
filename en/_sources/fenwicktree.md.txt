# acl_cpp.fenwicktree

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/fenwicktree.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/fenwicktree.cpp)

## fenwicktree.fenwick_tree

```python
# fenwick_tree<ll>
from acl_cpp.fenwicktree import fenwick_tree
```

長さ $n$ の整数列に対し、

- 要素の $1$ 点変更
- 区間の要素の総和

を $O(\log n)$ 時間で求めることが出来るデータ構造です。

### コンストラクタ

```python
# fenwick_tree::fenwick_tree(int n)
def fenwick_tree(n: int = 0) -> fenwick_tree
```

長さ $n$ の整数列 $a_0, a_1, \dots, a_{n-1}$ を作ります。初期値はすべて $0$ です。

**制約**

- $0 \leq n < 2^{31}$

**計算量**

- $O(n)$

### add

```python
# void fenwick_tree::add(int p, ll x)
def fenwick_tree.add(p: int, x: int) -> None
```

`a[p] += x` を行います。

**制約**

- $0 \leq p < n$

**計算量**

- $O(\log n)$

### sum

```python
# ll fenwick_tree::sum(int l, int r)
def fenwick_tree.sum(l: int, r: int) -> int
```

`a[l] + a[l + 1] + ... + a[r - 1]` を返します。  
答えが **64 bit 符号付き整数型**に収まらない場合、mod $2^{64}$ で等しい値を返します。

**制約**

- $0 \leq l \leq r \leq n$

**計算量**

- $O(\log n)$

## 使用例

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_b>

```python
from acl_cpp.fenwicktree import fenwick_tree

N, Q = map(int, input().split())
a = list(map(int, input().split()))

fw = fenwick_tree(N)
for i in range(N):
    fw.add(i, a[i])

for _ in range(Q):
    t, a, b = map(int, input().split())
    if t == 0:
        fw.add(a, b)
    else:
        print(fw.sum(a, b))
```
