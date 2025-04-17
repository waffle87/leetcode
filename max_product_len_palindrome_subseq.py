# 2002. Maximum Product of the Length of Two Palindromic Subsequences

"""
given a string 's', find two disjoint palindromic subsequences of 's' such
that the product of their lengths is maximised. the two subsequences are
disjoint if they do not both pick a character at the same index. return the
maximum possible product of the lengths of the two palindromic subsequences.
a subsequence is a string that can be derived from another string by deleting
some or none of its characters without changing the ordering of the remaining
characters. a string is palindromic if it reads the same forward and backward
"""


class Solution(object):
    def maxProduct(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        first, last = [0] * (1 << n), [0] * (1 << n)
        for i in range(n):
            for j in range(1 << i, 1 << (i + 1)):
                first[j] = i
        for i in range(n):
            for j in range(1 << i, 1 << n, 1 << (i + 1)):
                last[j] = i

        def dp(m):
            if m & (m - 1) == 0:
                return m != 0
            f, l = first[m], last[m]
            fb, lb = 1 << f, 1 << l
            return max(dp(m - lb), dp(m - fb), dp(m - lb - fb) + (s[l] == s[f]) * 2)

        ans = 0
        for i in range(1, 1 << n):
            ans = max(ans, dp(i) * dp((1 << n) - 1 - i))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxProduct(s="leetcodecom"))
    print(obj.maxProduct(s="bb"))
    print(obj.maxProduct(s="accbcaxxcxx"))
