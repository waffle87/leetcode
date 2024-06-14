# 442. Find All Duplicates in an Array

"""
given an integer array 'nums' of length 'n' where all the integers of 'nums'
are in the range '[1, n]' and each integer appears once or twice, return an
array of all the integers that appear twice. you must write an algorithm that
runs in 'O(n)' time and uses only constant extra space.
"""


class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for i in nums:
            if nums[abs(i) - 1] < 0:
                ans.append(abs(i))
            else:
                nums[abs(i) - 1] *= -1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findDuplicates(nums=[4, 3, 2, 7, 8, 2, 3, 1]))
    print(obj.findDuplicates(nums=[1, 1, 2]))
    print(obj.findDuplicates(nums=[1]))
