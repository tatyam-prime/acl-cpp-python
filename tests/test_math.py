import acl_cpp.math as m
import acl_cpp.math.internal as mi
from acl_cpp.math.internal import barrett
import pytest

def test_math():
    assert m.crt([3, 4], [4, 5]) == (19, 20)
    assert m.floor_sum(6, 5, 4, 3) == 13

    with pytest.raises(ValueError):
        m.crt([1], [2, 3])
    with pytest.raises(ValueError):
        m.crt([1], [0])
    with pytest.raises(ValueError):
        m.floor_sum(1 << 32, 1 << 32, 1 << 32, 1 << 32)

    bt = barrett(998244353)
    assert bt.umod() == 998244353
    assert bt.mul(998244352, 998244352) == 1

    assert mi.is_prime(2) == True
    assert mi.inv_gcd(4, 6) == (2, 2)
    assert mi.primitive_root(998244353) == 3
