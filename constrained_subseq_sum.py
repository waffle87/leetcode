# 1425. Constrained Subsequence Sum
import collections

"""
given an integer array 'nums' and an integer 'k', return the maximum sum of a
non-empty subsequnce of that array for every two consecutive integers in the
subsequence 'nums[i] and 'nums[j] where 'i < j', the condition 'j - i <= k'
is satisfied. a subsequence of an array is obtained by deleting some number
of elements (can be zero) from the array, leaving the remaining elements in
their original order.
"""


class Solution(object):
    def constrainedSubsetSum(self, nums, k):
        dq = collections.deque
        for i in range(len(nums)):
            nums[i] += dq[0] if dq else 0
            while len(dq) and nums[i] > dq[-1]:
                dp.pop()
            if nums[i] > 0:
                dq.append(nums[i])
            if i >= k and dq and dq[0] == nums[i - k]:
                dq.popleft()
        return max(nums)


if __name__ == "__main__":
    obj = Solution()
    print(obj.constrainedSubsetSum(nums=[10, 2, -10, 5, 20], k=2))  # expect: 37
    print(obj.constrainedSubsetSum(nums=[-1, -2, -3], k=1))  # expect: -1
    print(obj.constrainedSubsetSum(nums=[10, -2, -10, -5, 20], k=2))  # expect: 23
