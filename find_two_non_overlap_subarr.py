# 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

"""
you are given an array of integers 'arr' and an integer 'target'. you have to
find two non overlapping subarrays of 'arr' each with a sum equal to
'target'. there can be multiple answers so you have to finmd an answer where
the sum of the lengths of the two subarrays is minimum. return the minimum
sum of the lengths of the two required subarrays or return -1 if you cannot
find such two subarrays.
"""


class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        i, window, ans = 0, 0, float("inf")
        dp = [float("inf")] * len(arr)
        for j, num in enumerate(arr):
            window += num
            while window > target:
                window -= arr[i]
                i += 1
            if window == target:
                curr = j - i + 1
                ans = min(ans, curr + dp[i - 1])
                dp[j] = min(curr, dp[j - 1])
            else:
                dp[j] = dp[j - 1]
        return ans if ans < float("inf") else -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSumOfLengths(arr=[3, 2, 2, 4, 3], target=3))
    print(obj.minSumOfLengths(arr=[7, 3, 4, 7], target=7))
    print(obj.minSumOfLengths(arr=[4, 3, 2, 6, 2, 3, 4], target=6))
