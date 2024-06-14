# 2376. Count Special Integers
from math import perm

"""
we call a positive integer special if all of its digits are distinct. given a
positive integer 'n', return the number of special integers that belong to
the interval '[1, n]'
"""


class Solution(object):
    def countSpecialNumbers(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = list(map(int, str(n + 1)))
        m = len(l)
        ans = sum(9 * perm(9, i) for i in range(m - 1))
        s = set()
        for i, x in enumerate(l):
            for y in range(i == 0, x):
                if y not in s:
                    ans += perm(9 - i, m - i - 1)
            if x in s:
                break
            s.add(x)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countSpecialNumbers(20))
    print(obj.countSpecialNumbers(5))
    print(obj.countSpecialNumbers(135))
