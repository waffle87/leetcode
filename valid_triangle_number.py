# 611. Valid Triangle Number

"""
given an integer array 'nums', return the number of triplets chosen from the
array that can make triangles if we take them as side lengths of a triangle
"""


class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        n, ans = len(nums), 0
        for k in range(2, n):
            i, j = 0, k - 1
            while i < j:
                if nums[i] + nums[j] > nums[k]:
                    ans += j - i
                    j -= 1
                else:
                    i += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.triangleNumber(nums=[2, 2, 3, 4]))
    print(obj.triangleNumber(nums=[4, 2, 3, 4]))
