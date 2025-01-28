from acl_cpp.dsu import dsu
import pytest

def test_dsu():
    a = dsu()
    a = dsu(5)
    assert a.merge(0, 1) == 0
    assert a.same(0, 1) == True
    assert a.same(0, 2) == False
    assert a.leader(0) == 0
    assert a.size(0) == 2
    assert a.groups() == [[0, 1], [2], [3], [4]]

    with pytest.raises(ValueError):
        dsu(-1)
    with pytest.raises(ValueError):
        a.merge(-1, -1)
    with pytest.raises(ValueError):
        a.same(-1, -1)
    with pytest.raises(ValueError):
        a.leader(-1)
