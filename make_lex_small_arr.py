# 2948. Make Lexicographically Smallest Array by Swapping Elements

"""
you are given a 0-indexed array of positive integers 'nums' and a positive
integer 'limit'. in one operation, you can choose any two indices 'i' and 'j'
and swap 'nums[i]' and 'nums[j]' if '|nums[i] - nums[j]| <= limit'. return
the lexicographically smallest array that can be obtained by performingthe
operation any number of times.
"""


class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: List[int]
        """
        arr = sorted((v, i) for i, v in enumerate(nums))
        i = 0
        while i < len(nums):
            j = i + 1
            while j < len(nums) and arr[j][0] - arr[j - 1][0] <= limit:
                j += 1
            idx = sorted(x[1] for x in arr[i:j])
            for k in range(len(idx)):
                nums[idx[k]] = arr[i + k][0]
            i = j
        return nums


if __name__ == "__main__":
    obj = Solution()
    print(obj.lexicographicallySmallestArray(nums=[1, 5, 3, 9, 8], limit=2))
    print(obj.lexicographicallySmallestArray(nums=[1, 7, 6, 18, 2, 1], limit=3))
    print(obj.lexicographicallySmallestArray(nums=[1, 7, 28, 19, 10], limit=3))
