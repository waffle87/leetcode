# 1018. Binary Prefix Divisible By 5

"""
you are given a binary array 'nums'. we define 'x_i' as the number whose
binary representation is the subarray 'nums[0..i]' from (msb to lsb). return
an array of booleans 'answer' where 'answer[i]' is 'true' if 'x_i' is divible
by 5
"""


class Solution(object):
    def prefixesDivBy5(self, nums):
        """
        :type nums: List[int]
        :rtype: List[bool]
        """
        return (msb := 0) or [((msb := ((msb << 1) + i) % 5) == 0) for i in nums]


if __name__ == "__main__":
    obj = Solution()
    print(obj.prefixesDivBy5(nums=[0, 1, 1]))
    print(obj.prefixesDivBy5(nums=[1, 1, 1]))
