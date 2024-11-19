import pytest

def f_modint(mint, typename):
    a = mint()
    assert a.val() == 0
    a += mint.raw(1)
    a -= mint.raw(2)
    a *= mint(-1)
    a /= mint(-1)
    a **= 1
    assert a.val() == a.mod() - 1
    assert a.pow(10) == mint(1)
    assert a.inv() == a
    assert mint(1) + mint(1) - mint(1) * mint(1) / mint(1) == mint(1) ** 1
    assert mint() != mint(1)
    assert str(mint()) == "0"
    assert repr(mint()) == f"{typename}(0)"

    with pytest.raises(ValueError):
        a.pow(-1)
    with pytest.raises(ValueError):
        mint().inv()

def f_dynamic_modint(mint, typename):
    mint.set_mod(998244353)
    f_modint(mint, typename)

    with pytest.raises(ValueError):
        mint.set_mod(0)

def test_modint998244353():
    from acl_cpp.modint import modint998244353
    f_modint(modint998244353, "modint998244353")
    
def test_modint1000000007():
    from acl_cpp.modint import modint1000000007
    f_modint(modint1000000007, "modint1000000007")

def test_dynamic_modint():
    from acl_cpp.modint import modint
    f_dynamic_modint(modint, "modint")
