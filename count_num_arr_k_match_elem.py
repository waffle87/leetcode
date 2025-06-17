# 3405. Count the Number of Arrays with K Matching Adjacent Elements
from math import comb

"""
you are given three integers 'n', 'm', and 'k'. a good array 'arr' of size
'n' is defined as follows: each element in 'arr' is in inclusive range '[1,
m]', and exactly 'k' indices 'i' where '1 <= i < n' satisfy the condition
'arr[i - 1] == arr[i]'. return the number of good arrays that can be formed.
since the answer may be very large, return it modulo 10^9+7.
"""


class Solution(object):
    def countGoodArrays(self, n, m, k):
        """
        :type n: int
        :type m: int
        :type k: int
        :rtype: int
        """
        return m * pow(m - 1, n - k - 1, mod := 1**9 + 7) * comb(n - 1, k) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.countGoodArrays(n=3, m=2, k=1))
    print(obj.countGoodArrays(n=4, m=2, k=2))
    print(obj.countGoodArrays(n=5, m=2, k=0))
