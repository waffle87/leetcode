# 868. Binary Gap

"""
given a positive integer 'n', find and return the longest distance between
any two adjacent 1's in the binary representation of 'n'. if there are no two
adjacent 1's, return 0. two 1's are adjacent if there are only 0's separating
them. the distance between two 1's is the absolute difference between their
bit positions.
"""


class Solution(object):
    def binaryGap(self, n):
        """
        :type n: int
        :rtype: int
        """
        idx = [i for i, j in enumerate(bin(n)) if j == "1"]
        return max([j - i for i, j in zip(idx, idx[1:])] or [0])


if __name__ == "__main__":
    obj = Solution()
    print(obj.binaryGap(n=22))
    print(obj.binaryGap(n=8))
    print(obj.binaryGap(n=5))
