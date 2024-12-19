import acl_cpp.convolution as c
import acl_cpp.convolution.internal as ci
import pytest

def test_convolution():
    a = [1, 1]
    assert c.convolution(a, a, 998244353) == [1, 2, 1]
    assert c.convolution998244353(a, a) == [1, 2, 1]
    assert c.convolution_ll(a, a) == [1, 2, 1]

    with pytest.raises(ValueError):
        a = [0] * (2 ** 22 + 1)
        c.convolution(a, a, 998244353)
    with pytest.raises(ValueError):
        a = [0] * (2 ** 22 + 1)
        c.convolution998244353(a, a)
    with pytest.raises(ValueError):
        a = [0] * (2 ** 23 + 1)
        c.convolution_ll(a, a)
    with pytest.raises(ValueError):
        a = [1, 1]
        c.convolution(a, a, 1)

def test_convolution_internal():
    a = [0, 1, 0, 0]
    b = [1, 998244352, 911660635, 86583718]
    c = [0, 4, 0, 0]

    assert ci.butterfly998244353(a) == b
    assert ci.butterfly(a, 998244353) == b
    assert ci.butterfly_inv998244353(b) == c
    assert ci.butterfly_inv(b, 998244353) == c

    a = [0] * 3
    with pytest.raises(ValueError):
        ci.butterfly998244353(a)
    with pytest.raises(ValueError):
        ci.butterfly(a, 998244353)
    with pytest.raises(ValueError):
        ci.butterfly_inv998244353(a)
    with pytest.raises(ValueError):
        ci.butterfly_inv(a, 998244353)

    a = [0]
    with pytest.raises(ValueError):
        ci.butterfly(a, 1)
    with pytest.raises(ValueError):
        ci.butterfly_inv(a, 1)
    
    a = [0] * (2 ** 24)
    with pytest.raises(ValueError):
        ci.butterfly998244353(a)
    with pytest.raises(ValueError):
        ci.butterfly(a, 998244353)
    with pytest.raises(ValueError):
        ci.butterfly_inv998244353(a)
    with pytest.raises(ValueError):
        ci.butterfly_inv(a, 998244353)
