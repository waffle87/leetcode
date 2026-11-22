# 2124. Check if All A's Appears Before All B's
from itertools import islice
from operator import le


class Solution:
    def checkString(self, s: str) -> bool:
        return all(map(le, s, islice(s, 1, None)))


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkString(s="aaabbb"))
    print(obj.checkString(s="abab"))
    print(obj.checkString(s="bbb"))
