# 1286. Iterator for Combination

"""
design the 'CombinationIterator' class:
- 'CombinationIterator(string characters, int combinationLength)' initialises
the object with a string 'characters' of sorted distinct lowercase english
letters and a number 'combinationLength' as arguments
- 'next()' returns the next combination of length 'combinationLength' in
lexicographical order
- 'hasNext()' returns 'true' iff there exists a next combination
"""


class CombinationIterator(object):
    def __init__(self, characters, combinationLength):
        """
        :type characters: str
        :type combinationLength: int
        """
        self.characters = characters
        self.n = len(characters)
        self.combinations = self.get_comb(self.n, combinationLength)
        self.idx = len(self.combinations) - 1

    def next(self):
        """
        :rtype: str
        """
        s = ""
        for i in range(self.n):
            if self.combinations[self.idx][i] != "0":
                s += self.characters[i]
        self.idx -= 1
        return s

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.idx > -1

    def get_comb(self, l, n):
        end = int("1" * l, 2)
        res = []
        for i in range(end + 1):
            b = bin(i)[2:]
            if b.count("1") == n:
                res.append(b.zfill(l))
        return res


if __name__ == "__main__":
    obj = CombinationIterator("abc", 2)
    print(obj.next())
    print(obj.hasNext())
    print(obj.next())
    print(obj.hasNext())
    print(obj.next())
    print(obj.hasNext())
