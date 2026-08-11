# 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

"""
you are given a 0-indexed array of integers 'nums'. a prefix 'nums[0 ... i]'
is sequence if f or all '1 <= j <= i', 'nums[j] = nums[j - 1] + 1'. in
particular, the prefix consisting only of 'nums[0]' is sequential. return the
smallest integer 'x' missing from 'nums' such that 'x' is greater than or
equal to the sum of the longest sequential prefix.
"""


class Solution:
    def missingInteger(self, nums: list[int]) -> int:
        n = len(nums)
        vis = set(nums)
        sum = nums[0]
        for i in range(1, n):
            if nums[i] == nums[i - 1] + 1:
                sum += nums[i]
            else:
                break
        while sum in vis:
            sum += 1
        return sum


if __name__ == "__main__":
    obj = Solution()
    print(obj.missingInteger(nums=[1, 2, 3, 2, 5]))
    print(obj.missingInteger(nums=[3, 4, 5, 1, 12, 14, 13]))
