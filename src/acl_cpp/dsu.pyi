class dsu:
    def __init__(self, n: int = 0) -> None: ...
    def merge(self, a: int, b: int) -> None: ...
    def same(self, a: int, b: int) -> bool: ...
    def leader(self, a: int) -> int: ...
    def size(self, a: int) -> int: ...
    def groups(self) -> list[list[int]]: ...

