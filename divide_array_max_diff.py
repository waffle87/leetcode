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
        nums.sort()
        ans = []
        for i in range(2, len(nums), 3):
            if nums[i] - nums[i - 2] > k:
                return []
            ans.append([nums[i - 2], nums[i - 1], nums[i]])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.divideArray(nums=[1, 3, 4, 8, 7, 9, 3, 5, 1], k=2))
    print(obj.divideArray(nums=[1, 3, 3, 2, 7, 3], k=3))
    print(
        obj.divideArray(
            nums=[4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11], k=14
        )
    )
