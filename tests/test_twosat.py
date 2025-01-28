from acl_cpp.twosat import two_sat
import pytest

def test_twosat():
    g = two_sat()
    g = two_sat(2)
    g.add_clause(0, True, 1, False)
    g.add_clause(0, False, 1, True)
    g.add_clause(0, True, 1, True)
    assert g.satisfiable() == True
    assert g.answer() == [True, True]
    g.add_clause(0, False, 1, False)
    assert g.satisfiable() == False

    with pytest.raises(ValueError):
        two_sat(-1)
    with pytest.raises(ValueError):
        g.add_clause(-1, False, -1, True)
