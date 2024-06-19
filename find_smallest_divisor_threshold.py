# 1283. Find the Smallest Divisor Given a Threshold

"""
given an array of integers 'nums' and an integer 'threshold', we will choose
a positive integer 'divisor', divide all the array by it and sum the
divisions result. find the smallest divisor such that the result mentioned
above is less than or equal to 'threshold'. each result of the division is
rounded to the nearest integer greater than or equal to that element. the
test cases are generated so that there will be an answer
"""


class Solution(object):
    def smallestDivisor(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        l, r = 1, max(nums)
        while l < r:
            m = (l + r) / 2
            if sum((i + m - 1) / m for i in nums) > threshold:
                l = m + 1
            else:
                r = m
        return l


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestDivisor(nums=[1, 2, 5, 9], threshold=6))
    print(obj.smallestDivisor(nums=[44, 22, 33, 11, 1], threshold=5))
