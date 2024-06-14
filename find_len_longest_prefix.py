# 3043. Find the Length of the Longest Common Prefix
from bisect import bisect_left

"""
given two arrays with positive integers 'arr1' and 'arr2'. a prefix of a
positive integer is an integer formed by one or more of its digits, starting
from its leftmost digit. a common prefix of two integers 'a' and 'b' is an
integer 'c' such that is a prefix of both a and b. for example 6555359 and
56554 have a common prefix 565 while q223 and 43456 do not have a common
prefix. return the length of the longest common prefix among all pairs. if no
common prefix exists among them, return 0.
"""


class Solution(object):
    def longestCommonPrefix(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: int
        """

        def findCommonPrefixLength(x, y):
            common_prefix_length = 0
            min_length = min(len(x), len(y))

            for i in range(min_length):
                if x[i] == y[i]:
                    common_prefix_length += 1
                else:
                    break

            return common_prefix_length

        a = [str(x) for x in arr1]
        b = [str(x) for x in arr2]

        a.sort()
        b.sort()

        ans = 0
        n = len(a)
        for i in range(len(b)):
            idx = bisect_left(a, b[i])
            if idx < n:
                ans = max(ans, findCommonPrefixLength(a[idx], b[i]))
            if idx > 0:
                ans = max(ans, findCommonPrefixLength(a[idx - 1], b[i]))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestCommonPrefix(arr1=[1, 10, 100], arr2=[1000]))
    print(obj.longestCommonPrefix(arr1=[1, 2, 3], arr2=[4, 4, 4]))
