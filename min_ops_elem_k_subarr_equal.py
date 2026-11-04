# 3505. Minimum Operations to Make Elements Within K Subarrays Equal

"""
you are given an integer array 'nums' and two integers 'x' and 'k'. you can
perform the following operation any number of times (including zero):
increase or decrease any elements of 'nums' by 1. return the minimum number
of operations needed to have at least 'k' non-overlapping subarrays of size
exactly 'x' in 'nums', where all elements within each subarray are eqeual.
"""

from sortedcontainers import SortedList


class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        n = len(nums)
        left, right = SortedList(), SortedList()
        sum_l = sum_r = 0
        ops = [0] * n

        for i, value in enumerate(nums):
            if not left or value <= left[-1]:
                left.add(value)
                sum_l += value
            else:
                right.add(value)
                sum_r += value
            if i >= x:
                value = nums[i - x]
                if value in left:
                    left.remove(value)
                    sum_l -= value
                else:
                    right.remove(value)
                    sum_r -= value
            if len(left) > len(right) + 1:
                value = left.pop()
                right.add(value)
                sum_l -= value
                sum_r += value
            elif len(left) < len(right):
                value = right.pop(0)
                left.add(value)
                sum_l += value
                sum_r -= value
            if i >= x - 1:
                mid = left[-1]
                ops[i] = mid * len(left) - sum_l + sum_r - mid * len(right)

        pre = [0] * (n + 1)
        curr = [float("inf")] * (n + 1)
        for j in range(1, k + 1):
            for i in range(n + 1):
                curr[i] = float("inf")
            for i in range(j * x, n + 1):
                curr[i] = min(curr[i - 1], pre[i - x] + ops[i - 1])
            pre, curr = curr, pre
        return pre[n]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[5, -2, 1, 3, 7, 3, 6, 4, -1], x=3, k=2))
    print(obj.minOperations(nums=[9, -2, -2, -2, 1, 5], x=2, k=2))
