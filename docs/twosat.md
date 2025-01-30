# acl_cpp.twosat

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/twosat.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/twosat.cpp)

## twosat.two_sat

```python
# two_sat
from acl_cpp.twosat import two_sat
```

2-SAT を解きます。
変数 $x_0, x_1, \cdots, x_{n - 1}$ に関して、

- $(x_i = f) \lor (x_j = g)$

という節を追加していき、すべての節が満たされる変数の割当があるかを調べます。

### コンストラクタ

```python
# two_sat::two_sat(int n)
def two_sat(n: int = 0) -> two_sat
```

$n$ 変数の 2-SAT インスタンスを作成します。

**制約**

- $0 \le n < 2^{31}$

**計算量**

- $O(n)$

### two_sat.add_clause

```python
# void two_sat::add_clause(int i, bool f, int j, bool g)
def two_sat.add_clause(i: int, f: bool, j: int, g: bool) -> None
```

節 $(x_i = f) \lor (x_j = g)$ を追加します。

**制約**

- $0 \le i < n$
- $0 \le j < n$

**計算量**

- ならし $O(1)$

### two_sat.satisfiable

```python
# bool two_sat::satisfiable()
def two_sat.satisfiable() -> bool
```

条件を足す割当が存在するかどうかを判定する。割当が存在するならば `true`、そうでないなら `false` を返す。

**制約**

- 複数回呼ぶことも可能。

**計算量**

足した制約の個数を $m$ として

- $O(n + m)$

### two_sat.answer

```python
# vector<bool> two_sat::answer()
def two_sat.answer() -> list[bool]
```

最後に呼んだ `satisfiable` の、すべての節を満たす割当を返します。  

**制約**

- <span style="color: red;">`two_sat.satisfiable()` が `True` を返した後で呼び出すこと</span>
    - `satisfiable` を呼ぶ前や、`satisfiable` で割当が存在しなかったときにこの関数を呼ぶと、中身が未定義の長さ $n$ の リストを返します。

**計算量**

- $O(n)$

## 使用例

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_h>

```python
from acl_cpp.twosat import two_sat

N, D = map(int, input().split())
X, Y = zip(*(list(map(int, input().split())) for _ in range(N)))

ts = two_sat(N)
for i in range(N):
    for j in range(i + 1, N):
        if abs(X[i] - X[j]) < D:
            ts.add_clause(i, False, j, False)
        if abs(X[i] - Y[j]) < D:
            ts.add_clause(i, False, j, True)
        if abs(Y[i] - X[j]) < D:
            ts.add_clause(i, True, j, False)
        if abs(Y[i] - Y[j]) < D:
            ts.add_clause(i, True, j, True)

if not ts.satisfiable():
    print("No")
    exit()

print("Yes")
answer = ts.answer()
for i in range(N):
    print(X[i] if answer[i] else Y[i])
```
