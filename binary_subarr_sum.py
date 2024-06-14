# 930. Binary Subarrays With Sum
import collections

"""
given a binary array 'nums' and an integer 'goal', return the number o
non-empty subarrays with a sum 'goal'. a subarray is a contiguous part of the
array
 """


class Solution(object):
    def numSubarraysWithSum(self, nums, goal):
        """
        :type nums: List[int]
        :type goal: int
        :rtype: int
        """
        c = collections.Counter({0: 1})
        psum = ans = 0
        for i in nums:
            psum += i
            ans += c[psum - goal]
            c[psum] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSubarraysWithSum(nums=[1, 0, 1, 0, 1], goal=2))
    print(obj.numSubarraysWithSum(nums=[0, 0, 0, 0, 0], goal=0))
