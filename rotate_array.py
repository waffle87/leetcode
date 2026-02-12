# 189. Rotate Array

"""
given an integer array 'nums', rotate the array to the right by 'k' stops,
where 'k' is non-negative.
"""


class Solution(object):
    def reverse(self, nums, start, end):
        while start < end:
            tmp = nums[start]
            nums[start] = nums[end]
            nums[end] = tmp
            start += 1
            end -= 1

    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        if k < 0:
            k += n
        self.reverse(nums, 0, n - k - 1)
        self.reverse(nums, n - k, n - 1)
        self.reverse(nums, 0, n - 1)


if __name__ == "__main__":
    obj = Solution()
    n1 = [1, 2, 3, 4, 5, 6, 7]
    n2 = [-1, -100, 3, 99]
    obj.rotate(n1, k=3)
    obj.rotate(n2, k=2)
    print(n1)
    print(n2)
