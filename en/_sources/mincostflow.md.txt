# acl_cpp.mincostflow

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/mincostflow.html)
- [ソースコード](https://github.com/tatyam-prime/acl-cpp-python/blob/main/src/mincostflow.cpp)

## mincostflow.mcf_graph

```python
# mcf_graph<ll, ll>
from acl_cpp.mincostflow import mcf_graph
```

[最小費用流問題](https://en.wikipedia.org/wiki/Minimum-cost_flow_problem) を扱うライブラリです。

### コンストラクタ

```python
# mcf_graph::mcf_graph(int n)
def mcf_graph(n: int) -> mcf_graph
```

$n$ 頂点 $0$ 辺のグラフを作ります。

**制約**

- $0 \le n < 2^{31}$

**計算量**

- $O(n)$

### mcf_graph.add_edge

```python
# int mcf_graph::add_edge(int from, int to, ll cap, ll cost)
def mcf_graph.add_edge(from_: int, to: int, cap: int, cost: int) -> int
```

頂点 $\mathit{from\_}$ から頂点 $\mathit{to}$ へ最大容量 $\mathit{cap}$, コスト $\mathit{cost}$, 流量 $0$ の辺を追加します。何番目に追加された辺かを返します (0-origin) 。

**制約**

- $0 \le \mathit{from\_} < n$
- $0 \le \mathit{to} < n$
- $0 \le \mathit{cap}, \mathit{cost} < 2^{63}$

**計算量**

- ならし $O(1)$

### mcf_graph.flow

```python
# (1) pair<ll, ll> mcf_graph::flow(int s, int t)
def mcf_graph.flow(s: int, t: int) -> tuple[int, int]

# (2) pair<ll, ll> mcf_graph::flow(int s, int t, ll flow_limit)
def mcf_graph.flow(s: int, t: int, flow_limit: int) -> tuple[int, int]
```

- (1) `flow(s, t, (1 << 63) - 1)` と等価です。
- (2) 流量 $\mathit{flow\_limit}$ に達するか、これ以上流せなくなるまで頂点 $s$ から頂点 $t$ へ流し、流せた量と、その量を流すための最小コストを返します。

**制約**

- `slope` と同じ

**計算量**

- `slope` と同じ

### mcf_graph.slope

```python
# (1) vector<pair<ll, ll>> mcf_graph::slope(int s, int t)
def mcf_graph.slope(s: int, t: int) -> list[tuple[int, int]]

# (2) vector<pair<ll, ll>> mcf_graph::slope(int s, int t, ll flow_limit)
def mcf_graph.slope(s: int, t: int, flow_limit: int) -> list[tuple[int, int]]
```

(1) `slope(s, t, (1 << 63) - 1)` と等価です。

(2) 流量に対する最小コストは広義単調増加・下に凸な折れ線 (区分線形関数) となります。この折れ線の頂点を返します。

具体的には、流量 $x$ の時の最小コストを $g(x)$ として、$(x, g(x))$ の列を以下の条件を満たすように返します。

- 返り値の最初の点は $(0, 0)$
- 返り値の $x$ は狭義単調増加、$g(x)$ は広義単調増加
- 返り値の最後の点は、`y = flow(s, t, flow_limit)[0]` として $(y, g(y))$
- 返り値の中間の点で $g(x)$ の傾きが増加する（すなわち、同一直線上の $3$ 点を含まない）
- 返り値の点を順に繋いだ折れ線が $g(x)\ (0 \le x \le \text{flow_limit})$ のグラフを表現する

$g(x)$ が **64 bit 符号付き整数** に収まらない場合、mod $2^{64}$ で等しい値を返すはずです。

**制約**

- $s \neq t$
- $0 \leq s, t \lt n$
- <span style="color: red">`slope` や `flow` を合わせて複数回呼んだときの動作は未定義</span>
- <span style="color: red">辺のコストの最大値を $x$ として、$n \cdot x \leq 8 \times 10^{18} + 1000$
    - <span style="color: red">より正確には、(単純パスの最大コスト) $\leq 8 \times 10^{18} + 1000$</span>
    - これが満たされない場合の動作は未定義

**計算量**

$F$ を流量、$m$ を追加した辺の本数として

- $O(F (n + m) \log (n + m))$

### mcf_graph.edge

- mcf_graph 上の辺を表す class です。read-only な変数 `from_`, `to`, `cap`, `flow`, `cost` からなります。
- `cap` は最大容量、`flow` は現在の流量を表します。
- `from` は予約語なので `from_` としています。

#### コンストラクタ

```python
# mcf_graph::edge::edge(int from, int to, ll cap, ll flow, ll cost)
def mcf_graph.edge(from_: int, to: int, cap: int, flow: int, cost: int) -> mcf_graph.edge
```

### mcf_graph.get_edge

```python
# mcf_graph.edge mcf_graph::get_edge(int i)
def mcf_graph.get_edge(i: int) -> mcf_graph.edge
```

$i$ 番目に追加された辺の現在の状態を返します。

**制約**

$m$ をこれまでに追加された辺の数として

- $0 \le i < m$

**計算量**

- $O(1)$

### mcf_graph.edges

```python
# vector<mcf_graph::edge> mcf_graph::edges()
def mcf_graph.edges() -> list[mcf_graph.edge]
```

すべての辺の現在の状態を返します。辺は追加された順に並びます。

**計算量**

- $O(m)$

## 使用例

AC code of <https://atcoder.jp/contests/practice2/tasks/practice2_e>

```python
from acl_cpp.mincostflow import mcf_graph

BIG = 10 ** 9
N, K = map(int, input().split())

# generate (s -> row -> column -> t) graph
# i-th row correspond to vertex i
# i-th col correspond to vertex n + i
g = mcf_graph(N * 2 + 2)
s = N * 2
t = N * 2 + 1

# we can "waste" the flow
g.add_edge(s, t, N * K, BIG)

for i in range(N):
    g.add_edge(s, i, K, 0)
    g.add_edge(N + i, t, K, 0)

for i in range(N):
    A = list(map(int, input().split()))
    for j, a in enumerate(A):
        g.add_edge(i, N + j, 1, BIG - a)

result = g.flow(s, t, N * K)
print(BIG * N * K - result[1])

grid = [bytearray(b'.' * N) for _ in range(N)]
for e in g.edges():
    if e.from_ == s or e.to == t or e.flow == 0:
        continue
    grid[e.from_][e.to - N] = ord('X')

for row in grid:
    print(row.decode())
```
