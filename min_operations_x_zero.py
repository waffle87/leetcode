# 1658. Minimum Operations to Reduce X to Zero

"""
given an integer array 'nums' and an integer 'x'. in one operation, you can
either remove the leftmost or the rightmost element from the array 'nums' and
subtract its value from 'x'. note that this modifies the array for future
operations. return the minimum number of operations to reduce 'x' to exactly
0. if it is possible, otherwise return -1
"""


class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target = sum(nums) - x
        curr_sum, max_len, start = 0, 0, 0
        found = False
        for end in range(len(nums)):
            curr_sum += nums[end]
            while start <= end and curr_sum > target:
                curr_sum -= nums[start]
                start += 1
            if curr_sum == target:
                found = True
                max_len = max(max_len, end - start + 1)

        return len(nums) - max_len if found else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations([1, 1, 4, 2, 3], 5))  # expect: 2
    print(obj.minOperations([5, 6, 7, 8, 9], 4))  # expect: -1
    print(obj.minOperations([3, 2, 20, 1, 1, 3], 10))  # expect: 5
