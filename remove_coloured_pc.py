# 2038. Remove Colored Pieces if Both Neighbors are the Same Color

from collections import Counter


class Solution(object):
    def winnerOfGame(self, colours):
        c = collections.Counter()
        for x, t in groupby(colours):
            c[x] += max(len(list(t)) - 2, 0)
        if c["A"] > c["B"]:
            return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.winnerOfGame("AAABABB"))  # expect: 1
    print(obj.winnerOfGame("AA"))  # expect: 0
    print(obj.winnerOfGame("ABBBBBBBAAA"))  # expect: 0
