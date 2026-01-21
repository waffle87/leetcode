# 3315. Construct the Minimum Bitwise Array II

"""
you are given an array 'nums' consisting of 'n' prime integers. you need to
construct an array 'ans' of length 'n' such that for each index 'i', the
bitwise or of 'ans[i]' and 'ans[i + 1]' is equal to 'nums[i]'. additionally,
you must minimize each value 'ans[i]' in the resulting array. if it is not
possible to find such a value for 'ans[i]' that satisfies the condition, then
set 'ans[i] = -1'.
"""


class Solution(object):
    def minBitwiseArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for i in nums:
            if i != 2:
                ans.append(i - ((i + 1) & (-i - 1)) // 2)
            else:
                ans.append(-1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minBitwiseArray(nums=[2, 3, 5, 7]))
    print(obj.minBitwiseArray(nums=[11, 13, 31]))
