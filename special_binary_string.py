# 761. Special Binary String

"""
special binary strings are binary strings with the following two properties:
the number of 0's is equal to the number of 1's, and every prefix of the
binary tring has at least as many 1's as 0's. you are given a special binary
string 's'. a move consists of choosing two consecutive non-empty special
substrings of 's', and swapping them. two strings are consecutive if the last
character of the first string is exactly one index before the first character
of the second string. return the lexicographically largest resulting string
possible after applying the mentioned operations on the string.
"""


class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        ans, cnt, i, j = [], 0, 0, 0
        while i < len(s):
            cnt += 1 if s[i] == "1" else -1
            if cnt == 0:
                ans.append("1" + self.makeLargestSpecial(s[j + 1 : i]) + "0")
                j = i + 1
            i += 1
        ans.sort(reverse=True)
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.makeLargestSpecial(s="11011000"))
    print(obj.makeLargestSpecial(s="10"))
