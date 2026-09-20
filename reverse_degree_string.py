# 3498. Reverse Degree of a String

"""
given a string 's', calculate its reverse degree. the reverse degree is
calculated as follows: for each character, multiply its position in the
reversed alphabet with its position in the string (1-indexed). sum these
products for all characters in the string. return the reverse degree of 's'.
"""


class Solution:
    def reverseDegree(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            ans += (i + 1) * (ord("z") - ord(s[i]) + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.reverseDegree(s="abc"))
    print(obj.reverseDegree(s="zaza"))
