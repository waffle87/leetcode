# 397. Integer Replacement

"""
given a positive integer 'n', you can apply one of the following operations:
if 'n' is even, replace 'n' witn 'n / 2'. if 'n' is odd, replace 'n' with
either 'n + 1' or 'n - 1'. return the minimum number of operations needed for
'n' to become 1
"""


class Solution(object):
    def helper(self, x, y=0):
        if x == 1:
            return y
        if x % 2 == 0:
            return self.helper(x >> 1, y + 1)
        else:
            if x == 3 or not ((x >> 1) & 1):
                return self.helper(x - 1, y + 1)
            else:
                return self.helper(x + 1, y + 1)

    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.helper(n)


if __name__ == "__main__":
    obj = Solution()
    print(obj.integerReplacement(n=8))
    print(obj.integerReplacement(n=7))
    print(obj.integerReplacement(n=4))
