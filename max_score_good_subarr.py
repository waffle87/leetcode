# 1793. Maximum Score of a Good Subarray

"""
given an array of integers 'nums' (0-indexed) and an integer 'k'. the score
of a subarray '(i, j)' is defined as 'min(nums[i], nums[i + 1], ..., nums[j])
(j - i + 1)'. a good subarray is a subarray where 'i <= k <= j'. return the
maximum possible score of a good subarray.
"""


class Solution(object):
    def maximumScore(self, nums, k):
        ans = mini = nums[k]
        i, j, n = k, k, len(nums)
        while i > 0 or j < n - 1:
            if (nums[i - 1] if i else 0) < (nums[j + 1] if j < n - 1 else 0):
                j += 1
            else:
                i -= 1
            mini = min(mini, nums[i], nums[j])
            ans = max(ans, mini * (j - i + 1))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumScore(nums=[1, 4, 3, 7, 4, 5], k=3))  # expect: 15
    print(obj.maximumScore(nums=[5, 5, 4, 5, 4, 1, 1, 1], k=0))  # expect: 20
