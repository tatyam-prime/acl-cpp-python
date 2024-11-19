import acl_cpp.string as s
import pytest

def test_string():
    assert s.suffix_array([0, 1, 0], 2) == [2, 0, 1]
    assert s.suffix_array([0, 1, 0]) == [2, 0, 1]
    assert s.suffix_array("010") == [2, 0, 1]
    assert s.lcp_array([0, 1, 0], [2, 0, 1]) == [1, 0]
    assert s.lcp_array("010", [2, 0, 1]) == [1, 0]
    assert s.z_algorithm([0, 1, 0]) == [3, 0, 1]
    assert s.z_algorithm("010") == [3, 0, 1]

