# 3066. Minimum Operations to Exceed Threshold Value II

"""
you are given a 0-indexed integer array 'nums', and an integer 'k'. in one
operation, you will take the two smallest integers 'x' and 'y' in 'nums',
remove 'x' and 'y' from 'nums', and add 'min(x, y)  2 + max(x, y)' anywhere
in the array. note that you can only apply the described operation if 'nums'
contains at least two elements. return the minimum number of operations
needed so that all elements of the array are greater than or equal to 'k'.
"""


class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        arr, i, j, cnt = [], 0, 0, 0
        while True:
            if i < len(nums) and (j >= len(arr) or nums[i] <= arr[j]):
                x = nums[i]
                i += 1
            else:
                x = arr[j]
                j += 1
            if x >= k:
                return cnt
            if i < len(nums) and (j >= len(arr) or nums[i] <= arr[j]):
                y = nums[i]
                i += 1
            else:
                y = arr[j]
                j += 1
            arr.append(2 * x + y)
            cnt += 1
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[2, 11, 10, 1, 3], k=10))
    print(obj.minOperations(nums=[1, 1, 2, 4, 9], k=20))
