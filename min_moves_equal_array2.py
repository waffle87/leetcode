# 462. Minimum Moves to Equal Array Elements II

"""
given an integer array 'nums' of size 'n', return the minimum number of moves
required to make all array elements equal. in one move, you can increment or
decrement an element of the array by 1.
"""


class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        median = nums[len(nums) // 2]
        return sum(abs(i - median) for i in nums)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMoves2(nums=[1, 2, 3]))
    print(obj.minMoves2(nums=[1, 10, 2, 9]))
