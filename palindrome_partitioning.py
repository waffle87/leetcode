# 131. Palindrome Partitioning
from collections import defaultdict

"""
given: string 's', parition 's' such that every substring of the parition
is a palindrome. return all possible palindrome paritioning of 's'.
"""


class Solution(object):
    def __init__(self):
        self.memory = defaultdict(list)

    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        if not s:
            return [[]]
        if s in self.memory:
            return self.memory[s]
        ans = []
        for i in range(1, len(s) + 1):
            if s[:i] == s[:i][::-1]:
                for suf in self.partition(s[i:]):
                    ans.append([s[:i]] + suf)
        self.memory[s] = ans
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.partition(s="aab"))
    print(obj.partition(s="a"))
