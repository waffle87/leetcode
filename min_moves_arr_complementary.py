# 1674. Minimum Moves to Make Array Complementary
from collections import Counter

"""
you are given an integer array 'nums' of even length 'n' and an integer
'limit'. in one move, you can replace any integer from 'nums' with another
integer between 1 and 'limit', inclusive. the array 'nums' is complementary
if for all indices 'i' (0-indexed), 'nums[i] + nums[n - i - 1]' equals the
same number. return the minimum number of moves required to make 'nums'
complementary.
"""


class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        delta = Counter()
        n = len(nums)
        for i in range(n // 2):
            a, b = nums[i], nums[n - 1 - i]
            delta[2] += 2
            delta[min(a, b) + 1] -= 1
            delta[a + b] -= 1
            delta[a + b + 1] += 1
            delta[max(a, b) + limit + 1] += 1
        curr = 0
        ans = float("inf")
        for i in range(2, 2 * limit + 1):
            curr += delta[i]
            ans = min(ans, curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMoves(nums=[1, 2, 4, 3], limit=4))
    print(obj.minMoves(nums=[1, 2, 2, 1], limit=2))
    print(obj.minMoves(nums=[1, 2, 1, 2], limit=2))
