# 2966. Divide Array Into Arrays With Max Difference

"""
given an integer array 'nums' of size 'n' and a positive integer 'k'. divide
the array into one or more arrays of size 3 satisfying the following
conditions. each element of 'nums' should be in exactly one array. the
different between any two elements in one array is less than or equal to 'k'.
return a 2d array containing all the arrays if it is impossible to satisfy
the conditions, return an empty array. and if there are multiple answers,
return any of them
"""


class Solution(object):
    def divideArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        size = len(nums)
        if size % 3 != 0:
            return []
        nums.sort()
        ans = []
        group_idx = 0
        for i in range(0, size, 3):
            if i + 2 < size and nums[i + 2] - nums[i] <= k:
                ans.append([nums[i], nums[i + 1], nums[i + 2]])
                group_idx += 1
            else:
                return []
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.divideArray(nums=[1, 3, 4, 8, 7, 9, 3, 5, 1], k=2))
    print(obj.divideArray(nums=[1, 3, 3, 2, 7, 3], k=3))
