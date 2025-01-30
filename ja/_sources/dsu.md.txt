# acl_cpp.dsu

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/dsu.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/dsu.cpp)

## dsu.dsu

```python
# dsu
from acl_cpp.dsu import dsu
```

無向グラフに対して、

- 辺の追加
- $2$ 頂点が連結かの判定

をならし $O(\alpha(n))$ 時間で処理することが出来ます。

ここで、$\alpha(n)$ はアッカーマン関数の逆関数で、ほとんど定数時間とみなせます。

また、内部的に各連結成分ごとに代表となる頂点を $1$ つ持っています。辺の追加により連結成分がマージされる時、新たな代表元は元の連結成分の代表元のうちどちらかになります。

### コンストラクタ

```python
# dsu::dsu(int n)
def dsu(n: int = 0) -> dsu
```

- $n$ 頂点 $0$ 辺の無向グラフを作ります。

**制約**

- $0 \le n \lt 2^{31}$

**計算量**

- $O(n)$

### dsu.merge

```python
# void dsu::merge(int a, int b)
def dsu.merge(a: int, b: int) -> None
```

辺 $(a, b)$ を足します。

$a, b$ が連結だった場合はその代表元、非連結だった場合は新たな代表元を返します。

**制約**

- $0 \le a \lt n$
- $0 \le b \lt n$

**計算量**

- ならし $O(\alpha(n))$

### dsu.same

```python
# bool dsu::same(int a, int b)
def dsu.same(a: int, b: int) -> bool
```

頂点 $a, b$ が連結かどうかを返します。

**制約**

- $0 \le a \lt n$
- $0 \le b \lt n$

**計算量**

- ならし $O(\alpha(n))$

### dsu.leader

```python
# int dsu::leader(int a)
def dsu.leader(a: int) -> int
```

頂点 $a$ の属する連結成分の代表元を返します。

**制約**

- $0 \le a \lt n$

**計算量**

- ならし $O(\alpha(n))$

### dsu.size

```python
# int dsu::size(int a)
def dsu.size(a: int) -> int
```

頂点 $a$ の属する連結成分のサイズを返します。

**制約**

- $0 \le a \lt n$

**計算量**

- ならし $O(\alpha(n))$

### dsu.groups

```python
# vector<vector<int>> dsu::groups()
def dsu.groups() -> list[list[int]]
```

グラフを連結成分に分け、その情報を返します。

返り値は「「一つの連結成分の頂点番号のリスト」のリスト」です。
（内側外側限らず）vector 内でどの順番で頂点が格納されているかは未定義です。

**計算量**

- $O(n)$

## 使用例

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_a>

```python
from acl_cpp.dsu import dsu

N, Q = map(int, input().split())
d = dsu(N)

for _ in range(Q):
    t, u, v = map(int, input().split())
    if t == 0:
        d.merge(u, v)
    else:
        print(int(d.same(u, v)))
```
