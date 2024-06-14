# 900. RLE Iterator

"""
we can use run length encoding to encode a sequence of integers. in a run
length encoded array of even length encoding, for all even 'i', 'encoding[i]'
tells us the number of times that the non negative integer value 'encoding[i
+ 1]' is repeated in the sequence. given that a run length encoded array,
design an iterator that iterates through it.
"""


class RLEIterator(object):

    def __init__(self, encoding):
        """
        :type encoding: List[int]
        """
        self.vals = encoding
        self.i = 0

    def next(self, n):
        """
        :type n: int
        :rtype: int
        """
        while n > 0 and self.i < len(self.vals):
            if n > self.vals[self.i]:
                n -= self.vals[self.i]
                self.i += 2
            else:
                self.vals[self.i] -= n
                return self.vals[self.i + 1]
        return -1


if __name__ == "__main__":
    obj = RLEIterator([3, 8, 0, 9, 2, 5])
    print(obj.next(2))
    print(obj.next(1))
    print(obj.next(1))
    print(obj.next(2))
