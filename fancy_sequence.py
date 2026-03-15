# 1622. Fancy Sequence

"""
write an api that generates fancy sequences using the 'append', 'addAll', and
'multAll' operations.
"""


class Fancy:
    def __init__(self):
        self.a = []
        self.add = [0]
        self.mult = [1]
        self.mod = 10**9 + 7

    def append(self, val: int) -> None:
        self.a.append(val)
        self.add.append(self.add[-1])
        self.mult.append(self.mult[-1])

    def addAll(self, inc: int) -> None:
        self.add[-1] += inc

    def multAll(self, m: int) -> None:
        self.add[-1] = self.add[-1] * m % self.mod
        self.mult[-1] = self.mult[-1] * m % self.mod

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.a):
            return -1
        m = self.mult[-1] * pow(self.mult[idx], self.mod - 2, self.mod)
        inc = self.add[-1] - self.add[idx] * m
        return (self.a[idx] * m + inc) % self.mod


if __name__ == "__main__":
    obj = Fancy()
    obj.append(2)
    obj.addAll(3)
    obj.append(7)
    obj.multAll(2)
    print(obj.getIndex(0))
    obj.addAll(3)
    obj.append(10)
    obj.multAll(2)
    print(obj.getIndex(0))
    print(obj.getIndex(1))
    print(obj.getIndex(2))
