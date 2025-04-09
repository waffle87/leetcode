# 3375. Minimum Operations to Make Array Values Equal to K

"""
you are given an integer array 'nums' and an integer 'k'. an integer 'h' is
called valid if all values in the array that are strictly greater than 'h'
are identical. for example, if 'nums = [10, 8, 10, 8]', a valid integer is 'h
= 9' because all 'nums[i] > 9' are equal to 10, but 5 is not a valid integer.
you are allowed to perform the following operation on 'nums': select an
integer 'h' that is valid for the current value in 'nums', for each index 'i'
where 'nums[i] > h', set 'nums[i]' to 'h'. return the minimum number of
operations required to make every element in 'nums' equal to 'k'. if it is
impossible, return -1
"""


class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        distinct, bits = 0, 101
        for i in nums:
            distinct |= 1 << i
            bits = min(bits, i)
        if bits < k:
            return -1
        cnt = distinct.bit_count()
        return cnt - 1 if bits == k else cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[5, 2, 5, 4, 5], k=2))
    print(obj.minOperations(nums=[2, 1, 2], k=2))
    print(obj.minOperations(nums=[9, 7, 5, 3], k=1))
