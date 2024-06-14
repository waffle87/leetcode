# 532. K-diff Pairs in an Array
from collections import Counter

"""
given an array of integers 'nums' and an integer 'k', return the number of
unique pair '(nums[i], nums[j])' where the following are true: '0 <= i, j <
nums.len', 'i != j', and '| nums[i] - nums[j] == k'.
"""


class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        ans = 0
        c = Counter(nums)
        for i in c:
            if k > 0 and i + k in c or k == 0 and c[i] > 1:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findPairs(nums=[3, 1, 4, 1, 5], k=2))
    print(obj.findPairs(nums=[1, 2, 3, 4, 5], k=1))
    print(obj.findPairs(nums=[1, 3, 1, 5, 4], k=0))
