# 1415. The k-th Lexicographical String of All Happy Strings of Length n
from collections import deque

"""
a happy string is a string that consists only of letters of the set '[a, b,
c]', 's[i] != s[i + 1]' for all values of 'i' from 1 to 's.length - 1'. given
two integers 'n' and 'k', consider a list of all happy strings of length 'n'
sorted in lexicographical order. return the k'th string of this list or
return an empty string if there are less than 'k' strings of length 'n'.
"""


class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        q = deque(["a", "b", "c"])
        s = []
        while q:
            curr = q.popleft()
            if len(curr) == n:
                s.append(curr)
                continue
            for i in "abc":
                if curr[-1] != i:
                    q.append(curr + i)
        return "" if k > len(s) else s[k - 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.getHappyString(1, 3))
    print(obj.getHappyString(1, 4))
    print(obj.getHappyString(3, 9))
