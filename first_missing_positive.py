# 41. First Missing Positive

"""
given an unsorted integer array 'nums', return the smallest missing positive
number. you must implement an algorithm that runs in O(n) time and uses O(1)
auxiliary space.
"""


class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.append(0)
        n = len(nums)
        for i in range(len(nums)):
            if nums[i] < 0 or nums[i] >= n:
                nums[i] = 0
        for i in range(len(nums)):
            nums[nums[i] % n] += n
        for i in range(1, len(nums)):
            if nums[i] / n == 0:
                return i
        return n


if __name__ == "__main__":
    obj = Solution()
    print(obj.firstMissingPositive([1, 2, 0]))
    print(obj.firstMissingPositive([3, 4, -1, 1]))
    print(obj.firstMissingPositive([7, 8, 9, 11, 12]))
