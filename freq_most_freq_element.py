# 1838. Frequency of the Most Frequent Element

"""
the frequency of an element is the number of times it occurs in an array. you
are given an integer array 'nums' and an integer 'k'. in one operation, you
can shoose an index of 'nums' and increment the element at the index by 1.
return the maximum possible frequency of an element after performing at most
'k' operations
"""


class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        i = 0
        nums.sort()
        for j in range(len(nums)):
            k += nums[j]
            if k < nums[j] * (j - i + 1):
                k -= nums[i]
                i += 1
        return j - i + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxFrequency([1, 2, 4], 5))
    print(obj.maxFrequency([1, 4, 8, 13], 5))
    print(obj.maxFrequency([3, 9, 6], 2))
