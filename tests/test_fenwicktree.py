from acl_cpp.fenwicktree import fenwick_tree, fenwick_tree_modint
from acl_cpp.modint import modint
import pytest

def test_fenwicktree():
    a = fenwick_tree()
    a = fenwick_tree(5)
    a.add(0, 1)
    assert a.sum(0, 5) == 1

    with pytest.raises(ValueError):
        a.add(-1, 0)
    with pytest.raises(ValueError):
        a.sum(1, 0)

def test_fenwicktree_modint():
    modint.set_mod(998244353)
    
    a = fenwick_tree_modint()
    a = fenwick_tree_modint(5)
    a.add(0, modint(1))
    assert a.sum(0, 5) == modint(1)

    with pytest.raises(ValueError):
        a.add(-1, modint(0))
    with pytest.raises(ValueError):
        a.sum(1, 0)
