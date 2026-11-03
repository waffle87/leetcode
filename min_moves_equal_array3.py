# 3736. Minimum Moves to Equal Array Elements III

"""
you are given an integer array 'nums'. in one move, you may increase the
value of any single element 'nums[i]' by 1. return the minimum total number
of moves required so that all elements in 'nums' become equal.
"""


class Solution:
    def minMoves(self, nums: list[int]) -> int:
        max_num, ans = max(nums), 0
        for i in range(len(nums)):
            ans += max_num - nums[i]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMoves(nums=[2, 1, 3]))
    print(obj.minMoves(nums=[4, 4, 5]))
