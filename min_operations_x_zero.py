# 1658. Minimum Operations to Reduce X to Zero

"""
given an integer array 'nums' and an integer 'x'. in one operation, you can
either remove the leftmost or the rightmost element from the array 'nums' and
subtract its value from 'x'. note that this modifies the array for future
operations. return the minimum number of operations to reduce 'x' to exactly
0. if it is possible, otherwise return -1
"""


class Solution(object):
    def minOperations(self, nums, x):
        target, n = sum(nums) - x, len(nums)

        if target == 0:
            return n

        max_len = cur_sum = left = 0

        for right, val in enumerate(nums):
            cur_sum += val
            while left <= right and cur_sum > target:
                cur_sum -= nums[left]
                left += 1
            if cur_sum == target:
                max_len = max(max_len, right - left + 1)

        return n - max_len if max_len else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations([1, 1, 4, 2, 3], 5))  # expect: 2
    print(obj.minOperations([5, 6, 7, 8, 9], 4))  # expect: -1
    print(obj.minOperations([3, 2, 20, 1, 1, 3], 10))  # expect: 5
