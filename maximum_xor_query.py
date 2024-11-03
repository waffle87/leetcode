# 1829. Maximum XOR for Each Query

"""
you are given a sorted array 'nums' of 'n' non negative integers and an
integer 'maximumBit'. you want to perform the following query 'n' times: find
a non-negative integer 'k < 2^maximumBit' such that 'nums[0] ^ nums[1] ^ ...
^ nums[n]' is maximised. 'k' is the answer to the i'th query. remove the last
element from the current array 'nums'. return an array 'answer' where
'answer[i]' is the answer to the i'th query.
"""


class Solution(object):
    def getMaximumXor(self, nums, maximumBit):
        """
        :type nums: List[int]
        :type maximumBit: int
        :rtype: List[int]
        """
        max_xor, arr_xor, ans = (1 << maximumBit) - 1, reduce(ixor, nums), []
        for i in range(len(nums) - 1, -1, -1):
            ans.append(arr_xor ^ max_xor)
            arr_xor ^= nums[i]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.getMaximumXor(nums=[0, 1, 1, 3], maximumBit=2))
    print(obj.getMaximumXor(nums=[2, 3, 4, 7], maximumBit=3))
    print(obj.getMaximumXor(nums=[0, 1, 2, 2, 5, 7], maximumBit=3))
