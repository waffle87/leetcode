# 1137. N-th Tribonacci Number

"""
the tribonacci sequence t^n is defined as follows
t0 = 0, t1 = 1, t2 = 1, & tn+3 = tn + tn+1 + tn+2 for n >= 0
given n, return value of tn
eg.
n = 4, output: 4
t3 = 0 + 1 + 1 = 2
t4 = 1 + 1 + 2 = 4
"""


class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        a, b, c = 1, 0, 0
        for _ in range(n):
            a, b, c = b, c, a + b + c
        return c


if __name__ == "__main__":
    obj = Solution()
    print(obj.tribonacci(4))
    print(obj.tribonacci(25))
