# 461. Hamming Distance

"""
the hamming distance between two integers is the number of positions at which
the corresponding bits are different. given two integers 'x' and 'y', return
the hamming distance between them.
"""


class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        ans, n = 0, x ^ y
        while n:
            ans += 1
            n &= n - 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.hammingDistance(1, 4))
    print(obj.hammingDistance(3, 1))
