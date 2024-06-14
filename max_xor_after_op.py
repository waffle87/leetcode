# 2317. Maximum XOR After Operations

"""
given a 0-indexed integer array 'nums'. in one operations, select any
non-negative integer 'x' and an index 'i' then update 'nums[i]' to be equal
to 'nums[i] & (nums[i] ^ x)'. return the maximum possible bitwsie xor of all
elements after applying the operation any number of times.
"""

class Solution(object):
    def maximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for i in range(len(nums)):
            ans |= nums[i]
        return ans
        

if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumXOR([3,2,4,6])) # expect: 7
    print(obj.maximumXOR([1,2,3,9,2])) # expect: 11
