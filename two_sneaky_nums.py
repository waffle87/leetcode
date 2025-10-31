# 3289. The Two Sneaky Numbers of Digitville

"""
in the town of digitville, there was a list of numbers called 'nums'
containing integers from 0 to 'n - 1'. each number was supposed to appear
exactly once in the list, however two mischevious numbers snuck in an
additional time, making the list longer than usual. as the town detective,
your task is to find these two sneaky numbers. return an array of size 2
containing the two numbers, so peace can return to digitville.
"""


class Solution(object):
    def getSneakyNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n, x = len(nums) - 2, 0
        for i in nums:
            x ^= i
        for i in range(n):
            x ^= i
        diff = x & -x
        a, b = 0, 0
        for i in nums:
            if i & diff == 0:
                a ^= i
            else:
                b ^= i
        for i in range(n):
            if i & diff == 0:
                a ^= i
            else:
                b ^= i
        return [a, b]


if __name__ == "__main__":
    obj = Solution()
    print(obj.getSneakyNumbers(nums=[0, 1, 1, 0]))
    print(obj.getSneakyNumbers(nums=[0, 3, 2, 1, 3, 2]))
    print(obj.getSneakyNumbers(nums=[7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2]))
