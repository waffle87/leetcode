# 868. Binary Gap

"""
given a positive integer 'n', find and return the longest distance between
any two adjacent 1's in the binary representation of 'n'. if there are no two
adjacent 1's, return 0. two 1's are adjacent if there are only 0's separating
them. the distance between two 1's is the absolute difference between their
bit positions.
"""


class Solution:
    def binaryGap(self, n: int) -> int:
        if (n & (n - 1)) == 0:
            return 0
        n //= n & -n
        max_gap, gap = 0, 0
        while n:
            if n & 1:
                max_gap = max(max_gap, gap)
                gap = 0
            else:
                gap += 1
            n >>= 1
        return max_gap + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.binaryGap(n=22))
    print(obj.binaryGap(n=8))
    print(obj.binaryGap(n=5))
