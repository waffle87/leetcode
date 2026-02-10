# 3719. Longest Balanced Subarray I

"""
you are given an integer array 'nums'. a subarray is called balance if the
number of distinct even numbers in the subarray is equal to the number of
distinct odd numbers. return the length of the longest balanced subarray.
"""


class Solution(object):
    def longestBalanced(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, ans = len(nums), 0
        vis = [0] * (max(nums) + 1)
        for i in range(n):
            arr = [0, 0]
            for j in range(i, n):
                val = nums[j]
                if vis[val] != i + 1:
                    vis[val] = i + 1
                    arr[val & 1] += 1
                if arr[0] == arr[1]:
                    ans = max(ans, j - i + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestBalanced(nums=[2, 5, 4, 3]))
    print(obj.longestBalanced(nums=[3, 2, 2, 5, 4]))
    print(obj.longestBalanced(nums=[1, 2, 3, 2]))
