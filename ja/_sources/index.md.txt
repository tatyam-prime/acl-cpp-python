# acl-cpp-python

[![GitHub: acl-cpp-python](https://img.shields.io/badge/GitHub-acl--cpp--python-darkmagenta?logo=GitHub&logoColor=white)](https://github.com/tatyam-prime/acl-cpp-python)
[![PyPI: acl-cpp-python](https://img.shields.io/badge/PyPI-acl--cpp--python-006dad?logo=PyPI&logoColor=white)](https://pypi.org/project/acl-cpp-python/)
[![AC Library: v1.5.1](https://img.shields.io/badge/AC%20Library-v1.5.1-seagreen)](https://github.com/atcoder/ac-library) [![License: CC0 1.0](https://img.shields.io/badge/License-CC0%201.0-darkgoldenrod)](https://creativecommons.org/publicdomain/zero/1.0/)

日本語 | [English](https://tatyam-prime.github.io/acl-cpp-python/en/)

[acl-cpp-python](https://github.com/tatyam-prime/acl-cpp-python) は、C++ で実装された [AtCoder Library (ACL)](https://github.com/atcoder/ac-library) を Python に bind したパッケージです。  
内部的には C++ で実装されているので、高速な畳み込みやフロー、文字列アルゴリズムなどを Python から利用できます。

## インストール

```bash
python3 -m pip install acl-cpp-python
```

**`error: externally-managed-environment` が出る場合:**

動かしたいフォルダの中に [仮想環境](https://www.python.jp/install/windows/venv.html) を作成して、再実行しましょう。

仮想環境なんて面倒！どこでも使えるようにしたい！という場合は

```bash
python3 -m pip install acl-cpp-python --break-system-packages
```

を実行してしまいましょう。

### 更新

```bash
python3 -m pip install --upgrade acl-cpp-python
```

## 使用例

```python
from acl_cpp.convolution import convolution998244353

a = [1, 1]
b = convolution998244353(a, a)
print(b)  # [1, 2, 1]
```

```python
from acl_cpp.string import z_algorithm

a = z_algorithm("abacaba")
print(a)  # [7, 0, 1, 0, 3, 0, 1]
```

## 注意点

- C++ ↔︎ Python 間のデータの変換にはオーバーヘッドがあるため、関数の 1 回の実行時間が長いほど高速化が期待できます。
- `segtree`, `lazysegtree`, `modint` は高速化が期待できないため、現在実装されていません。
- オーバーフローに注意してください。多くの整数は 64 bit 符号付き整数として実装されているため、この範囲を超える計算を行うとオーバーフローが発生し、結果が間違ったものになります。
- ドキュメントでは、`long long` (64 bit 符号付き整数) を `ll` と表記します。

## ドキュメント

```{toctree}
:maxdepth: 1
./fenwicktree.md
./string.md
./math.md
./convolution.md
./dsu.md
./maxflow.md
./mincostflow.md
./scc.md
./twosat.md
```

## リンク

- [C++ 版のドキュメント](https://atcoder.github.io/ac-library/production/document_ja/)
