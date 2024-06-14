# 823. Binary Trees With Factors

"""
given an array of unique integers 'arr' where each integer 'arr[i]' is
strictly greater than 1. we make a binary tree using these integers and each
number may be used for any number of times. each non-leaf node's value should
be equal to the product of the values of its children. return the number of
binary trees we can make. the answer may be too large to fit in a signed 32
bit integer, so return the answer modulo 10e9+7
"""


class Solution(object):
    def numFactoredBinaryTrees(self, arr):
        dp = {}
        for i in sorted(arr):
            dp[i] = sum(dp[b] * dp.get(i / b, 0) for b in dp if i % b == 0) + 1
        return sum(dp.values()) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numFactoredBinaryTrees([2, 4]))  # expect: 3
    print(obj.numFactoredBinaryTrees([2, 4, 5, 10]))  # expect: 7
