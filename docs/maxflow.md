# acl_cpp.maxflow

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/maxflow.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/maxflow.cpp)

## maxflow.mf_graph

```python
# mf_graph<ll>
from acl_cpp.maxflow import mf_graph
```

[最大フロー問題](https://ja.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E3%83%95%E3%83%AD%E3%83%BC%E5%95%8F%E9%A1%8C) を解くライブラリです。

### コンストラクタ

```python
# mf_graph::mf_graph(int n)
def mf_graph(n: int = 0) -> mf_graph
```

$n$ 頂点 $0$ 辺のグラフを作ります。

**制約**

- $0 \le n < 2^{31}$

**計算量**

- $O(n)$

### mf_graph.add_edge

```python
# int mf_graph::add_edge(int from, int to, ll cap)
def mf_graph.add_edge(from_: int, to: int, cap: int) -> int
```

頂点 $\mathit{from\_}$ から頂点 $\mathit{to}$ へ最大容量 $\mathit{cap}$ 流量 $0$ の辺を追加します。何番目に追加された辺かを返します (0-origin) 。

**制約**

- $0 \le \mathit{from\_} < n$
- $0 \le \mathit{to} < n$
- $0 \le \mathit{cap} < 2^{63}$

**計算量**

- ならし $O(1)$

### mf_graph.flow

```python
# (1) ll mf_graph::flow(int s, int t)
def mf_graph.flow(s: int, t: int) -> int

# (2) ll mf_graph::flow(int s, int t, ll flow_limit)
def mf_graph.flow(s: int, t: int, flow_limit: int) -> int
```

- (1) `flow(s, t, (1 << 63) - 1)` と等価です。
- (2) 頂点 $s$ から頂点 $t$ へ流量 $\mathit{flow\_limit}$ に達するまで流せる限り流し、流せた量を返します。
- 複数回呼ぶことも可能です。詳細な挙動は [Appendix](https://atcoder.github.io/ac-library/production/document_ja/appendix.html) を参照してください。

**制約**

- $0 \le s < n$
- $0 \le t < n$
- $s \neq t$
- $0 \le \mathit{flow\_limit} < 2^{63}$

**計算量**

$m$ を追加された辺数として

- $O((n + m) \sqrt{m})$ (辺の容量がすべて $1$ のとき)
- $O(n^2 m)$
- 返り値を $F$ として $O(F(n + m))$
- 参考文献: [Dinic 法とその計算量](https://misawa.github.io/others/flow/dinic_time_complexity.html)

### mf_graph.min_cut

```python
# vector<bool> mf_graph::min_cut(int s)
def mf_graph.min_cut(s: int) -> list[bool]
```

以下で定める長さ $n$ の bool の配列 `cut` を返します。

- `cut[i]` は、現在の残余グラフにおいて、頂点 $s$ から頂点 $i$ へ到達可能かどうか

`flow(s, t)` をちょうど $1$ 回呼んだ後に `min_cut(s)` を呼ぶと、返り値は $s$-$t$ 間の最小カットに対応します。詳細な挙動は [Appendix](https://atcoder.github.io/ac-library/production/document_ja/appendix.html) を参照してください。

### mf_graph.edge

- mf_graph 上の辺を表す class です。read-only な変数 `from_`, `to`, `cap`, `flow` からなります。
- `cap` は最大容量、`flow` は現在の流量を表します。
- `from` は予約語なので `from_` としています。

#### コンストラクタ

```python
# mf_graph::edge::edge(int from, int to, ll cap, ll flow)
def mf_graph.edge(from_: int, to: int, cap: int, flow: int) -> mf_graph.edge
```

### mf_graph.get_edge

```python
# mf_graph::edge mf_graph::get_edge(int i)
def mf_graph.get_edge(i: int) -> mf_graph.edge
```

$i$ 番目に追加された辺の現在の状態を返します。

**制約**

$m$ をこれまでに追加された辺の数として

- $0 \le i < m$

**計算量**

- $O(1)$

### mf_graph.edges

```python
# vector<mf_graph::edge> mf_graph::edges()
def mf_graph.edges() -> list[mf_graph.edge]
```

すべての辺の現在の状態を返します。辺は追加された順に並びます。

**計算量**

- $O(m)$

### mf_graph.change_edge

```python
# void mf_graph::change_edge(int i, ll new_cap, ll new_flow)
def mf_graph.change_edge(i: int, new_cap: int, new_flow: int) -> None
```

$i$ 番目 (0-origin) に追加された辺の最大容量を $\mathit{new\_cap}$ 、流量を $\mathit{new\_flow}$ に変更します。詳細は [Appendix](https://atcoder.github.io/ac-library/production/document_ja/appendix.html) を参照してください。

**制約**

- $0 \le i < m$
- $0 \le \mathit{new\_flow} \le \mathit{new\_cap} < 2^{63}$

## 使用例

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_d>

```python
from acl_cpp.maxflow import mf_graph
HASH = ord('#')
DOT = ord('.')

N, M = map(int, input().split())
grid = [bytearray(input().encode()) for _ in range(N)]

s = N * M
t = s + 1
g = mf_graph(N * M + 2)

# s -> even / odd -> t
for i in range(N):
    for j in range(M):
        if grid[i][j] == HASH:
            continue
        v = i * M + j
        if (i + j) % 2 == 0:
            g.add_edge(s, v, 1)
        else:
            g.add_edge(v, t, 1)

# even -> odd
for i in range(N):
    for j in range(M):
        if (i + j) % 2 or grid[i][j] == HASH:
            continue
        v0 = i * M + j
        if i > 0 and grid[i - 1][j] == DOT:
            g.add_edge(v0, v0 - M, 1)
        if i + 1 < N and grid[i + 1][j] == DOT:
            g.add_edge(v0, v0 + M, 1)
        if j > 0 and grid[i][j - 1] == DOT:
            g.add_edge(v0, v0 - 1, 1)
        if j + 1 < M and grid[i][j + 1] == DOT:
            g.add_edge(v0, v0 + 1, 1)

print(g.flow(s, t))

for e in g.edges():
    if e.from_ == s or e.to == t or e.flow == 0:
        continue
    i0, j0 = divmod(e.from_, M)
    i1, j1 = divmod(e.to, M)
    
    if i0 + 1 == i1:
        grid[i0][j0] = ord('v')
        grid[i1][j1] = ord('^')
    elif i1 + 1 == i0:
        grid[i1][j1] = ord('v')
        grid[i0][j0] = ord('^')
    elif j0 + 1 == j1:
        grid[i0][j0] = ord('>')
        grid[i1][j1] = ord('<')
    else:
        grid[i1][j1] = ord('>')
        grid[i0][j0] = ord('<')

for row in grid:
    print(row.decode())
```
