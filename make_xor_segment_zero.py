# 1787. Make the XOR of All Segments Equal to Zero
import collections

"""
given an array 'nums' and an integer 'k'. the xor of a segment '[left,
right]' where 'left <= right' is the xor of all the elements with indices
between 'left' and 'right', inclusive 'nums[left] xor nums[left + 1] xor ...
xor nums[right]'. return the minimum number of elements to change in the
array such that the 'xor' of all segments of size 'k' is equal to zero
"""


class Solution(object):
    def minChanges(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        m = 1 << 10
        freq = collections.defaultdict(collections.Counter)
        for i, n in enumerate(nums):
            freq[i % k][n] += 1
        dp = [[0] * m for _ in range(k + 1)]
        for i in range(1, m):
            dp[0][i] = -float("inf")
        for i in range(1, k + 1):
            max_row = max(dp[i - 1])
            for j in range(m):
                for mask in freq[i - 1]:
                    dp[i][j] = max(
                        dp[i][j], max_row, dp[i - 1][j ^ mask] + freq[i - 1][mask]
                    )
        return len(nums) - dp[-1][0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minChanges(nums=[1, 2, 0, 3, 0], k=1))
    print(obj.minChanges(nums=[3, 4, 5, 2, 1, 7, 3, 4, 7], k=3))
    print(obj.minChanges(nums=[1, 2, 4, 1, 2, 5, 1, 2, 6], k=3))
