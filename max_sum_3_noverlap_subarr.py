# 689. Maximum Sum of 3 Non-Overlapping Subarrays

"""
given an integer array 'nums' and an integer 'k', find three non-overlapping
subarrays of length 'k' with maximum sum and return them. return the result
as a list of indices representing the starting position of each interval
(0-indexed). if there are multiple answers, return the lexicographcially
smallest one
"""


class Solution(object):
    def max_sumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n = len(nums)
        max_sum = 0
        sum = [0]
        left = [0] * n
        right = [n - k] * n
        ans = [0, 0, 0]
        for i in nums:
            sum.append(sum[-1] + i)
        tot = sum[k] - sum[0]
        for i in range(k, n):
            if sum[i + 1] - sum[i + 1 - k] > tot:
                left[i] = i + 1 - k
                tot = sum[i + 1] - sum[i + 1 - k]
            else:
                left[i] = left[i - 1]
        tot = sum[n] - sum[n - k]
        for i in range(n - k - 1, -1, -1):
            if sum[i + k] - sum[i] > tot:
                right[i] = i
                tot = sum[i + k] - sum[i]
            else:
                right[i] = right[i + 1]
        for i in range(k, n - 2 * k + 1):
            l, r = left[i - 1], right[i + k]
            tot = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r])
            if tot > max_sum:
                max_sum = tot
                ans = [l, i, r]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.max_sumOfThreeSubarrays(nums=[1, 2, 1, 2, 6, 7, 5, 1], k=2))
    print(obj.max_sumOfThreeSubarrays(nums=[1, 2, 1, 2, 1, 2, 1, 2, 1], k=2))
