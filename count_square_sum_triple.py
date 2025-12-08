# 1925. Count Square Sum Triples
import math

"""
a square triple '(a, b, c)' is a triple where 'a', 'b', and 'c' are integers
and 'a^2 + b^2 = c^2'. given an integer 'n', return the number of square
triples such that '1 <= a, b, c <= n'.
"""


class Solution(object):
    def countTriples(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        for u in range(2, int(math.sqrt(n)) + 1):
            for v in range(1, u):
                if (u - v) & 1 == 0 or math.gcd(u, v) != 1:
                    continue
                c = u * u + v * v
                if c > n:
                    continue
                ans += 2 * (n // c)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countTriples(n=5))
    print(obj.countTriples(n=10))
