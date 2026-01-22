# 3507. Minimum Pair Removal to Sort Array I

"""
given an array 'nums', you can perform the following operation any number of
times. select the adjacent pair with the minimum sum in 'nums'. if multiple
such pairs exist, choose the leftmost one. replace the pair with their sum.
return the minimum number of operations needed o make the array
non-decreasing. an array is said to be non-decreasing if each element is
great than or equal to its previous element (if it exists).
"""


class Solution(object):
    def sorted(self, nums, n):
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                return False
        return True

    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, n = 0, len(nums)
        while not self.sorted(nums, n):
            ans += 1
            min_sum, pos = float("inf"), -1
            for i in range(1, n):
                total = nums[i - 1] + nums[i]
                if total < min_sum:
                    min_sum = total
                    pos = i
            nums[pos - 1] = min_sum
            for i in range(pos, n - 1):
                nums[i] = nums[i + 1]
            n -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumPairRemoval(nums=[5, 2, 3, 1]))
    print(obj.minimumPairRemoval(nums=[1, 2, 2]))
