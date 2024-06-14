# 945. Minimum Increment to Make Array Unique

"""
given an integer array 'nums'. in one move you can pick an index i where 0 <=
i < nums.len and increment nums[i] by 1. return the minimum number of moves
to make every value in nums unique. the test cases are generated so that the
answer fits in a 32 bit integer.
"""


class Solution(object):
    def minIncrementForUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, need = 0, 0
        for i in sorted(nums):
            ans += max(need - i, 0)
            need = max(need + 1, i + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minIncrementForUnique([1, 2, 2]))
    print(obj.minIncrementForUnique([3, 2, 1, 2, 1, 7]))
