from acl_cpp.maxflow import mf_graph
import pytest

def test_math():
    g = mf_graph()
    g = mf_graph(5)
    g.add_edge(0, 1, 1)
    assert str(g.get_edge(0)) == "<edge from=0 to=1 cap=1 flow=0>"
    assert str(g.edges()) == "[<edge from=0 to=1 cap=1 flow=0>]"
    e = mf_graph.edge(0, 1, 1, 0)

    g.change_edge(0, 2, 1)
    assert g.flow(0, 1) == 1
    assert g.flow(1, 0, 10) == 2
    assert g.min_cut(1) == [False, True, False, False, False]

    with pytest.raises(ValueError):
        g.add_edge(0, 0, -1)
    with pytest.raises(ValueError):
        g.get_edge(-1)
    with pytest.raises(ValueError):
        g.change_edge(0, 1, 2)
    with pytest.raises(ValueError):
        g.flow(0, 0)
