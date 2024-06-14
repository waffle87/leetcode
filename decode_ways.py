# 91. Decode Ways

"""
a message containing letters from a - z can be encoded into numbers using the
following mapping: a -> 1, b -> 2, ..., z -> 26. to decode an encoded
message, all the digits must be grouped then mapped back into letters using
the reverse of the mapping above (there may be multiple ways). for example,
"11106" can be mapped into: "aajf" with the grouping ' 1 1 10 6', "kjf" with
the grouping '11 10 6'. note that the grouping '(1 11 06)' because '06'
cannot be mapped into "f" because '6' is different from '06'. given a string
's' containing only digits, return the number of ways to decode it. the test
cases are generated so that the answer fits in a 32-bit integer
"""


class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == "0":
            return 0
        dp1 = int(s[-1] != "0")
        dp2 = 1
        i = len(s) - 2
        while i >= 0:
            if s[i] == "0":
                dp0 = 0
            else:
                dp0 = dp1
                if (s[i] == "1") or (s[i] == "2" and eval(s[i + 1]) < 7):
                    dp0 += dp2
            i -= 1
            dp0, dp1, dp2 = 0, dp0, dp1
        return dp1


if __name__ == "__main__":
    obj = Solution()
    print(obj.numDecodings("12"))
    print(obj.numDecodings("226"))
    print(obj.numDecodings("06"))
