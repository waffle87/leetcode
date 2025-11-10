# 784. Letter Case Permutation
from itertools import product

"""
given a string 's', you can transform every letter individually to be
lowercase or uppercase. return a list of all possible strings we could
create. return the output in any order.
"""


class Solution(object):
    def letterCasePermutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        return map("".join, product(*[set([i.lower(), i.upper()]) for i in s]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.letterCasePermutation(s="a1b2"))
    print(obj.letterCasePermutation(s="3z4"))
