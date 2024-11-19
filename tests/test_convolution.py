from acl_cpp.convolution import convolution, convolution_ll
import acl_cpp.convolution.internal as ci
import pytest

def test_convolution():
    a = [1, 1]
    assert convolution(a, a, 998244353) == [1, 2, 1]
    assert convolution_ll(a, a) == [1, 2, 1]

    with pytest.raises(ValueError):
        a = [0] * (2 ** 22 + 1)
        convolution(a, a, 998244353)
    with pytest.raises(ValueError):
        a = [0] * (2 ** 23 + 1)
        convolution_ll(a, a)

def test_convolution_998244353():
    from acl_cpp.modint import modint998244353 as mint
    a = [mint(1)] * 2
    assert convolution(a, a) == [mint(1), mint(2), mint(1)]
    a = ci.butterfly(a)
    assert a == [mint(2), mint(0)]
    a[0] *= a[0]
    a[1] *= a[1]
    a = ci.butterfly_inv(a)
    assert a == [mint(4), mint(4)]

    with pytest.raises(ValueError):
        a = [mint(0)] * (2 ** 22 + 1)
        convolution(a, a)
    
def test_convolution_dynamic():
    from acl_cpp.modint import modint as mint
    mint.set_mod(998244353)
    a = [mint(1)] * 2
    assert convolution(a, a) == [mint(1), mint(2), mint(1)]
    a = ci.butterfly(a)
    assert a == [mint(2), mint(0)]
    a[0] *= a[0]
    a[1] *= a[1]
    a = ci.butterfly_inv(a)
    assert a == [mint(4), mint(4)]

    with pytest.raises(ValueError):
        a = [mint(0)] * (2 ** 22 + 1)
        convolution(a, a)
