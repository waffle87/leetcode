# 2166. Design Bitset

"""
a bitset is a data structure that compactly stores bits. implement the
'Bitset' class. 'Bitset(int size)' initialises the bitsetwith 'size' bits,
all of which are '0' 'void fix(int idx)' updates the value of the bit at the
index 'idx' to 1 if the value was already 1, no change occurs 'void unfix(int
idx)' updates the value of the bit at the index 'idx' to 0 if the value was
already 0, no change occurs 'void flip()' flips the values of each bit in the
biset. in other words, all bits with value 0 will now have value 1 and vice
versa 'boolean all()' checks if the value of each bit in the bitset is 1.
returns true if it satisfies the condition, false otherwise 'boolean one()'
checks if there is at least one bit in the bitset withvalue 1. returns true
if it satisfies the condition, false otherwise 'int count()' returns the
total number of bits in the bitset which have value 1 'string toString()'
returns the current composition of the bitset. note that in the resultant
string, the character at the i'th index should coincide with the value at the
i'th bit of the bitset
"""


class Bitset(object):
    def __init__(self, size):
        """
        :type size: int
        """
        self.arr = [0] * size
        self.ones = 0
        self.rev = False

    def fix(self, idx):
        """
        :type idx: int
        :rtype: None
        """
        if self.rev:
            if self.arr[idx] == 1:
                self.ones += 1
            self.arr[idx] = 0
        else:
            if self.arr[idx] == 0:
                self.ones += 1
            self.arr[idx] = 1

    def unfix(self, idx):
        """
        :type idx: int
        :rtype: None
        """
        if self.rev:
            if self.arr[idx] == 0:
                self.ones -= 1
            self.arr[idx] = 1
        else:
            if self.arr[idx] == 1:
                self.ones -= 1
            self.arr[idx] = 0

    def flip(self):
        """
        :rtype: None
        """
        self.rev = not self.rev
        self.ones = len(self.arr) - self.ones

    def all(self):
        """
        :rtype: bool
        """
        return self.ones == len(self.arr)

    def one(self):
        """
        :rtype: bool
        """
        return self.ones > 0

    def count(self):
        """
        :rtype: int
        """
        return self.ones

    def toString(self):
        """
        :rtype: str
        """
        return (
            "".join([str(0 if i else 1) for i in self.arr])
            if self.rev
            else "".join([str(i) for i in self.arr])
        )


if __name__ == "__main__":
    obj = Bitset(5)
    obj.fix(3)
    obj.fix(1)
    obj.flip()
    print(obj.all())
    obj.unfix(0)
    obj.flip()
    print(obj.one())
    obj.unfix(0)
    print(obj.count())
    print(obj.toString())
