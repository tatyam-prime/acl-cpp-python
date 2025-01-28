from acl_cpp.scc import scc_graph
import pytest

def test_fenwicktree():
    a = scc_graph()
    a = scc_graph(5)
    a.add_edge(0, 1)
    a.add_edge(1, 2)
    a.add_edge(2, 3)
    a.add_edge(3, 4)
    a.add_edge(1, 0)
    assert a.scc() == [[0, 1], [2], [3], [4]]

    with pytest.raises(ValueError):
        scc_graph(-1)
    with pytest.raises(ValueError):
        a.add_edge(-1, -1)

