# 1295. Find Numbers with Even Number of Digits

"""
given an array 'nums' of integers, return how many of them contain an even
number of digits.
"""


class Solution(object):
    def findNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(1 for i in nums if (len(str(i)) & 1) == 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findNumbers(nums=[12, 345, 2, 6, 7896]))
    print(obj.findNumbers(nums=[555, 901, 482, 1771]))
