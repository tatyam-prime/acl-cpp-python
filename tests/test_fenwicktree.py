from acl_cpp.fenwicktree import fenwick_tree
import pytest

def test_fenwicktree():
    a = fenwick_tree()
    a = fenwick_tree(5)
    a.add(0, 1)
    assert a.sum(0, 5) == 1

    with pytest.raises(ValueError):
        fenwick_tree(-1)
    with pytest.raises(ValueError):
        a.add(-1, 0)
    with pytest.raises(ValueError):
        a.sum(1, 0)
