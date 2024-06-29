# 3022. Minimize OR of Remaining Elements Using Operations

"""
given a 0 indexed integer array 'nums' and an integer 'k'. in one operation,
you can pick any index 'i' of 'nums' such that '0 <= i < nums.len - 1' and
replace 'nums[i]' and 'nums[i + 1]' with a single occurence of 'nums[i] &
nums[i + 1]' where & represents the bitwise and operation. return the minimum
possible value of the bitwise or of the remaining elements of 'nums' after
applying at most 'k' operations.
"""


class Solution(object):
    def minOrAfterOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        mask = 0
        for bit in range(29, -1, -1):
            mask |= 1 << bit
            ops_needed, and_res = 0, 0
            for i in nums:
                if and_res != 0:
                    and_res &= i
                    ops_needed += 1
                elif i & mask != 0:
                    and_res = i & mask
            if and_res != 0:
                ops_needed += 1
            if ops_needed > k:
                mask -= 1 << bit
        return (1 << 30) - mask - 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOrAfterOperations(nums=[3, 5, 3, 2, 7], k=2))
    print(obj.minOrAfterOperations(nums=[7, 3, 15, 14, 2, 8], k=4))
