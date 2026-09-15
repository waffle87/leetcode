# 2472. Maximum Number of Non-overlapping Palindrome Substrings

"""
you are given a string 's' and a positive integer 'k'. select a set of
non-overlapping substrings from the string 's' that satisfy the following
conditions: the length of each substring is at least 'k', and each substring
is a palindrome. return the maximum number of substrings in an optimal
selection.
"""


class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        if k == 1:
            return n
        ans, i = 0, 0
        while i <= n - k:
            for d in (k, k + 1):
                if i + d <= n and s[i : i + d] == s[i : i + d][::-1]:
                    ans += 1
                    i += d
                    break
                else:
                    i += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxPalindromes(s="abaccdbbd", k=3))
    print(obj.maxPalindromes(s="adbcda", k=2))
