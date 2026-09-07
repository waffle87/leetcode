# 940. Distinct Subsequences II

"""
given a string 's', return the number of distinct non-empty subsequences of
's'. since the answer may be very large, return it modulo 10^9 + 7.
"""


class Solution:
    def distinctSubseqII(self, s: str) -> int:
        end = [0] * 26
        for i in s:
            end[ord(i) - ord("a")] = sum(end) + 1
        return sum(end) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.distinctSubseqII(s="abc"))
    print(obj.distinctSubseqII(s="aba"))
    print(obj.distinctSubseqII(s="aaa"))
