# 287. Find the Duplicate Number

"""
given an integer array 'nums' containing 'n + 1' integers where each integer
is in the range '[1, n]' inclusive. there is only one repeated number in
'nums', return this repeated number. you must solve the problem without
modifying the array 'nums' and uses only constant extra space.
"""


class Solution(object):
    def findDuplicate(self, nums):
        for n in nums:
            idx = abs(n)
            if nums[idx] < 0:
                return idx
            nums[idx] = -nums[idx]
        return len(nums)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findDuplicate([1, 3, 4, 2, 2]))  # expect: 2
    print(obj.findDuplicate([3, 1, 3, 4, 2]))  # expect: 3
