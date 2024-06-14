# 1043. Partition Array for Maximum Sum

"""
given an integeer array 'arr', partition the array into contiguous subarrays
of length at most 'k'. after partitioning, each subarray has their values
changed to become the maximum value of that subarray. return the largest sum
of the given array after partitioning. test cases are generated so that
answer fits in a 32-bit integer
"""


class Solution(object):
    def maxSumAfterPartitioning(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        n = len(arr)
        m = k + 1
        dp = [0] * m
        for start in range(n - 1, -1, -1):
            curr_max = 0
            end = min(n, start + m)
            for i in range(start, end):
                curr_max = max(curr_max, arr[i])
                dp[start % m] = max(
                    dp[start % m], dp[(i + 1) % m] + curr_max * (i - start + 1)
                )
        return dp[0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxSumAfterPartitioning(arr=[1, 15, 7, 9, 2, 5, 10], k=3))
    print(obj.maxSumAfterPartitioning(arr=[1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3], k=4))
    print(obj.maxSumAfterPartitioning(arr=[1], k=1))
