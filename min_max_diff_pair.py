# 2616. Minimize the Maximum Difference of Pairs

"""
given a 0-indexed integer array 'nums' and an integer 'p'. find 'p' pairs of
indices of 'nums' such that the maximum difference amongst all the pairs is
minimised. also, ensure no index appears more than once amongst that 'p'
pairs. note that for a pair of elements at the index 'i' and 'j'. the
difference of this pair is '|nums[i] - nums[j]|', where '|x|' represents the
absolute value of 'x'. return the minimum maximum difference among all 'p'
pairs. we define the maximum of an empty set to be zero.
"""


class Solution(object):
    def minimizeMax(self, nums, p):
        """
        :type nums: List[int]
        :type p: int
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        left, right = 0, nums[-1] - nums[0]
        while left < right:
            mid = (left + right) // 2
            i, j = 1, 0
            while i < n:
                if nums[i] - nums[i - 1] <= mid:
                    i += 1
                    j += 1
                i += 1
            if j >= p:
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimizeMax(nums=[10, 1, 2, 7, 1, 3], p=2))
    print(obj.minimizeMax(nums=[4, 2, 1, 2], p=1))
