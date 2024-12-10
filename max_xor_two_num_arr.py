# 421. Maximum XOR of Two Numbers in an Array

"""
given an integer array 'nums', return the maximum result of 'nums[i] ^
nums[j]' where '0 <= i <= j < n'
"""


class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, mask = 0, 0
        for i in range(31, -1, -1):
            mask |= 1 << i
            found = set([n & mask for n in nums])
            start = ans | 1 << i
            for pref in found:
                if start ^ pref in found:
                    ans = start
                    break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMaximumXOR(nums=[3, 10, 5, 25, 2, 8]))
    print(obj.findMaximumXOR(nums=[14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70]))
