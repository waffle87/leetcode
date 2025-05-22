# 3211. Generate Binary Strings Without Adjacent Zeros

"""
you are given a positive integer 'n'. a binary string 'x' is valid if all
substrings of 'x' of length 2 contain at least one 1. return all valid
strings with length 'n' in any order.
"""


class Solution(object):
    def __init__(self):
        self.ans = []

    def dfs(self, prev, str, n):
        if len(str) == n:
            self.ans.append(str)
            return
        self.dfs(1, str + "1", n)
        if prev == 1:
            self.dfs(0, str + "0", n)

    def validStrings(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.ans = []
        self.dfs(0, "0", n)
        self.dfs(1, "1", n)
        return self.ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.validStrings(n=3))
    print(obj.validStrings(n=1))
