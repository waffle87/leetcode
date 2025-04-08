# 3396. Minimum Number of Operations to Make Elements in Array Distinct

"""
you are given an integer array 'nums'. you need to ensure that the elements
in the array are distinct. to achieve this, you can remove 3 elements from
the beginning of the array. if the array has fewer than 3 elements, remove
all remaining elements. note that an empty array is considered to have
distinct elements. return the minimum number of operations needed to make the
elements in the array distinct.
"""


class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prev = [0] * 101
        for i in range(len(nums) - 1, -1, -1):
            prev[nums[i]] += 1
            if prev[nums[i]] == 2:
                return (i + 3) // 3
        return 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumOperations(nums=[1, 2, 3, 4, 2, 3, 3, 5, 7]))
    print(obj.minimumOperations(nums=[4, 5, 6, 4, 4]))
    print(obj.minimumOperations(nums=[6, 7, 8, 9]))
