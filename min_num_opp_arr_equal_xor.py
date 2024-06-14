# 2997. Minimum Number of Operations to Make Array XOR Equal to K

"""
given a 0-indexed array 'nums' and a positive integer 'k'. you can apply the
following operation on the array any number of times: choose any element of
the array and flip a bit in its binary representation. flipping a bit meops
chaning a 0 to a 1 or vice versa. return the minimum number of operations
required to make the bitwise xor of all elements in the array equal to 'k'.
note that you can flip leading zero bits in the binary representation of the
elements. for example, for the number of '101_2' you can flip the fouth bit
and obtain '1101_2'
"""


class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        cnt = k
        for n in nums:
            cnt ^= n
        ops = 0
        while cnt:
            ops += cnt & 1
            cnt >>= 1
        return ops


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(nums=[2, 1, 3, 4], k=1))
    print(obj.minOperations(nums=[2, 0, 2, 0], k=0))
