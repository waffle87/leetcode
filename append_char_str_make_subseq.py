# 2486. Append Characters to String to Make Subsequence

"""
given two strings 's' and 't' consisting of only lowercase english letters.
return the minimum number of characters that need to be appened to the end of
's' so that 't' becomes a subsequence of 's'. a subsequence is a string that
can be derived from another string by deleting some or no characters without
changing the order of the remaining characters.
"""


class Solution(object):
    def appendCharacters(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        n = iter(s)
        for i, c in enumerate(t):
            if c not in n:
                return len(t) - i
        return 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.appendCharacters("coaching", "coding"))
    print(obj.appendCharacters("abcde", "a"))
    print(obj.appendCharacters("z", "abcde"))
