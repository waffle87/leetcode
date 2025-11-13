# 3228. Maximum Number of Operations to Move Ones to the End
from itertools import groupby

"""
you are given a binary string 's'. you can perform the followiong operation
on the string any number of timees: choose any index 'i' from the string
where 'i + 1 < s.length' such that 's[i] == 1' and 's[i + 1] == 0'. move the
character 's[i]' to the right until it reaches the end of the string or
another 1. return the maximum number of operations that you can perform.
"""


class Solution(object):
    def maxOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans, ones = 0, 0
        for i, j in groupby(s):
            if i == "1":
                ones += len(list(j))
            else:
                ans += ones
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxOperations(s="1001101"))
    print(obj.maxOperations(s="00111"))
