# 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

"""
given three integers 'n, m, k'. consider the following algorithm to find the
maximum element of an array of positive integers [image] you should build the
array 'arr' which has the following properties:
- 'arr' has exactly 'n' integers
- '1 <= arr[i] < m' where '(0 <= i < n)'
- after applying the mentioned algorithm to 'arr', the value 'search_cost' is
equal to 'k' return the number of ways to build the array 'arr' under the
mentioned conditions. as the answer may grow larger than a signed 32-bit
integer, the answer must be computed modulo 10^9+7
"""


class Solution(object):
    def numOfArrays(self, n, m, k):
        dp = [[[0 for _ in range(m + 1)] for _ in range(k + 1)] for _ in range(n + 1)]
        for k in range(1, m + 1):
            dp[1][1][k] = 1
        for i, j, l in itertools.product(
            range(1, n + 1), range(1, k + 1), range(m + 1)
        ):
            dp[i][j][l] += dp[i - 1][j][l] * l
            dp[i][j][l] += sum(dp[i - 1][j - 1][1:k])
        return sum(dp[n][k][1:]) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfArrays(2, 3, 1))  # expect: 6
    print(obj.numOfArrays(5, 2, 3))  # expect: 0
    print(obj.numOfArrays(9, 1, 1))  # expect: 1
