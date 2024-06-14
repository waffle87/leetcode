# 2707. Extra Characters in a String

"""
you are given a 0-indexed string 's' and a dictionary of words 'dictionary'.
you have to break 's' into one or more non-overlapping substrings that each
substring is present in 'dictionary'. there may be some extra characters in
's' which are not present in any of the substrings. return the minimum number
of extra characters left over if you break up 's' optimally
"""


class Solution(object):
    def func(self, idx, s, st, dp):
        if idx == len(s):
            return 0
        if dp[idx] != -1:
            return dp[idx]
        res = float("inf")
        for j in range(idx, len(s)):
            substr = s[idx : j + 1]
            if substr in st:
                res = min(res, 0 + self.func(j + 1, s, st, dp))
            else:
                res = min(res, j - idx + 1 + self.func(j + 1, s, st, dp))
        dp[idx] = res
        return res

    def minExtraChar(self, s, dictionary):
        dp = [-1] * (len(s) + 1)
        st = set(dictionary)
        return self.func(0, s, st, dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minExtraChar("leetscode", ["leet", "code", "leetcode"]))  # expect: 1
    print(obj.minExtraChar("sayhelloworld", ["hello", "world"]))  # expect: 3
