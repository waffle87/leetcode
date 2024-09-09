# 1000. Minimum Cost to Merge Stones
from functools import lru_cache

"""
there are 'n' piles of 'stones' arrange in a row. the i'th pile has
'stones[i]' stones. a move consists of merging exactly 'k' consecutive piles
into one pile and the cost of this move is equal to the total number of
stones in these 'k' piles. return the minimum cost to merge all piles of
stones into one pile. if it is impossible, return -1
"""


class Solution(object):
    def mergeStones(self, stones, k):
        """
        :type stones: List[int]
        :type k: int
        :rtype: int
        """
        n = len(stones)
        if (n - 1) % (k - 1):
            return -1
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stones[i]

        @lru_cache(None)
        def dp(i, j):
            if j - i + 1 < k:
                return 0
            ans = min(dp(i, mid) + dp(mid + 1, j) for mid in range(i, j, k - 1))
            if (j - i) % (k - 1) == 0:
                ans += prefix[j + 1] - prefix[i]
            return ans

        return dp(0, n - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.mergeStones(stones=[3, 2, 4, 1], k=2))
    print(obj.mergeStones(stones=[3, 2, 4, 1], k=3))
    print(obj.mergeStones(stones=[3, 5, 1, 2, 6], k=3))
