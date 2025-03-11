# 397. Integer Replacement

"""
given a positive integer 'n', you can apply one of the following operations:
if 'n' is even, replace 'n' witn 'n / 2'. if 'n' is odd, replace 'n' with
either 'n + 1' or 'n - 1'. return the minimum number of operations needed for
'n' to become 1
"""


class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        while n > 1:
            ans += 1
            if n % 2 == 0:
                n //= 2
            elif n % 4 == 1 or n == 3:
                n -= 1
            else:
                n += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.integerReplacement(n=8))
    print(obj.integerReplacement(n=7))
    print(obj.integerReplacement(n=4))
