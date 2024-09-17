# 565. Array Nesting

"""
you are given an integer array 'nums' of length 'n' where 'nums' is a
permutation of the numbers in the range '[0, n - 1]'. you should bild a set
's[k] = {nums[k], nums[nums[k]], ... }' subjected to the following rules: the
first element in 's[k]' starts with the selection of the element 'nums[k]' of
'index = k'. the next element in 's[k]' should be 'nums[nums[k]]', and so on.
we stop adding right before a duplication element occurs in 's[k]'. return
the longest set of 's[k]'
"""


class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        seen, ans = [0] * len(nums), 0
        for i in nums:
            cnt = 0
            while not seen[i]:
                seen[i], cnt, i = 1, cnt + 1, nums[i]
            ans = max(ans, cnt)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.arrayNesting(nums=[5, 4, 0, 3, 1, 6, 2]))
    print(obj.arrayNesting(nums=[0, 1, 2]))
