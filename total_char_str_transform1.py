# 3335. Total Characters in String After Transformations I

"""
you are given a string 's' and an integer 't' representing the number of
transformations to perform. in one transformation, every character in 's' is
replaced according to the following rules: if the character is 'z', replace
it with the string 'ab'. otherwise, replace it with the next character in the
alphabet. return the length of the resulting string after exactly 't'
transformations. since the answer may be very large, return it modulo 10^9
+ 7.
"""


class Solution(object):
    def lengthAfterTransformations(self, s, t):
        """
        :type s: str
        :type t: int
        :rtype: int
        """
        mod = 10**9 + 7
        dp = [1] * 26 + [0] * 100100
        for i in range(26, 100100):
            dp[i] = (dp[i - 26] + dp[i - 26 + 1]) % mod
        return sum(dp[ord(c) - ord("a") + t] for c in s) % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.lengthAfterTransformations(s="abcyy", t=2))
    print(obj.lengthAfterTransformations(s="azbk", t=1))
