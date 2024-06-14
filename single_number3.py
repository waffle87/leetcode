# 260. Single Number III

"""
given an integer array 'nums' in which exactly two elements appear only once
and all the otherelements appear exactly twice. find the two elements that
appear only once. you can return the answer in any order. you must write an
algorithm that runs linear runtime complexity and uses only constant extra
space.
"""


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        s = reduce(xor, nums)
        nz = s & (s - 1) ^ s
        n1 = reduce(xor, filter(lambda n: n & nz, nums))
        return (n1, s ^ n1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.singleNumber([1, 2, 1, 3, 2, 5]))
    print(obj.singleNumber([-1, 0]))
    print(obj.singleNumber([0, 1]))
