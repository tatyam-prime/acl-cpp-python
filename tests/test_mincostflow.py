from acl_cpp.mincostflow import mcf_graph
import pytest

def test_math():
    g = mcf_graph()
    g = mcf_graph(5)
    g.add_edge(0, 1, 1, 1)
    assert str(g.get_edge(0)) == "<edge from=0 to=1 cap=1 flow=0 cost=1>"
    assert str(g.edges()) == "[<edge from=0 to=1 cap=1 flow=0 cost=1>]"
    e = mcf_graph.edge(0, 1, 1, 0, 1)

    assert g.flow(0, 1) == (1, 1)
    g.flow(0, 1, 2)
    g.slope(0, 1)
    g.slope(0, 1, 2)

    with pytest.raises(ValueError):
        g.add_edge(-1, -1, -1, -1)
    with pytest.raises(ValueError):
        g.get_edge(-1)
    with pytest.raises(ValueError):
        g.flow(0, 0)
