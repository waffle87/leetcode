# 3634. Minimum Removals to Balance Array

"""
you are given an integer array 'nums' and an integer 'k'. an array is
considered balance if the value of its maximum element is at most 'k' times
the minimum element. you may remove any number of elements from 'nums'
without making it empty. return the minimum number of elements so that the
remaining array is balanced. note an array of size 1 is considered to be
balance as its maximum and minimum are equal, and the condition always holds
true.
"""


class Solution(object):
    def minRemoval(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        n, ans, left = len(nums), 0, 0
        for right in range(n):
            while nums[right] > k * nums[left]:
                left += 1
            ans = max(ans, right - left + 1)
        return n - ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minRemoval(nums=[2, 1, 5], k=2))
    print(obj.minRemoval(nums=[1, 6, 2, 9], k=3))
    print(obj.minRemoval(nums=[4, 6], k=2))
