# acl_cpp.scc

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/scc.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/scc.cpp)

## scc.scc_graph

```python
# scc_graph
from acl_cpp.scc import scc_graph
```

有向グラフを強連結成分分解します。

### コンストラクタ

```python
# scc_graph::scc_graph(int n)
def scc_graph(n: int) -> scc_graph
```

$n$ 頂点 $0$ 辺のグラフを作成します。

**制約**

- $0 \le n < 2^{31}$

**計算量**

- $O(n)$

### scc_graph.add_edge

```python
# void scc_graph::add_edge(int from, int to)
def scc_graph.add_edge(from_: int, to: int) -> None
```

頂点 $\mathit{from\_}$ から頂点 $\mathit{to}$ への辺を追加します。

**制約**

- $0 \le \mathit{from\_} < n$
- $0 \le \mathit{to} < n$

**計算量**

- ならし $O(1)$

### scc_graph.scc

```python
# vector<vector<int>> scc_graph::scc()
def scc_graph.scc() -> list[list[int]]
```

以下の条件を満たすような、「頂点のリスト」のリストを返します。

- 全ての頂点がちょうど 1 つずつ、どれかのリストに含まれます。
- 内側のリストと強連結成分が一対一に対応します。リスト内での頂点の順序は未定義です。
- リストはトポロジカルソートされています。異なる強連結成分の頂点 $u, v$ について、$u$ から $v$ に到達できる時、$u$ の属するリストは $v$ の属するリストよりも前です。

**計算量**

追加した辺の本数を $m$ として

- $O(n + m)$

## 使用例

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_g>

```python
from acl_cpp.scc import scc_graph

N, M = map(int, input().split())
g = scc_graph(N)

for _ in range(M):
    u, v = map(int, input().split())
    g.add_edge(u, v)

scc = g.scc()
print(len(scc))
for component in scc:
    print(len(component), *component)
```
