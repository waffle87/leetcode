# 2262. Total Appeal of A String

"""
the appeal of a string is the number of distinct characters found in the
string. for example, the appeal of "aabca" is 3 because it has 3 distinct
characters 'a', 'b' and 'c'. given a string 's', return the total appeal of
along long its substrings. a substring is a contiguous sequence of characters
within a string.
"""


class Solution(object):
    def appealSum(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans, last = 0, {}
        for i, c in enumerate(s):
            last[c] = i + 1
            ans += sum(last.values())
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.appealSum("abbca"))  # expect: 28
    print(obj.appealSum("code"))  # expect: 20
