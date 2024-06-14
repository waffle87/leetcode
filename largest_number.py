# 179. Largest Number

"""
given a list of non-negative integers 'nums', arrange them such that they
form the larget number and return it. since the result may be very large, so
you need to return a string instead of an integer.
"""


class Solution(object):
    def largestNumber(self, nums):
        self.quickSort(nums, 0, len(nums) - 1)
        return str(int("".join(map(str, nums))))

    def quickSort(self, nums, l, r):
        if l >= r:
            return
        pos = self.partition(nums, l, r)
        self.quickSort(nums, l, pos - 1)
        self.quickSort(nums, pos + 1, r)

    def partition(self, nums, l, r):
        low = l
        while l < r:
            if self.compare(nums[l], nums[r]):
                nums[l], nums[low] = nums[low], nums[l]
                low += 1
            l += 1
        nums[low], nums[r] = nums[r], nums[low]
        return low


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestNumber([10, 2]))  # expect: 210
    print(obj.largestNumber([3, 30, 34, 5, 9]))  # expect: 9534330
