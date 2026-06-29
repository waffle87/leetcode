# 1967. Number of Strings That Appear as Substrings in Word

"""
given an array of strings 'patterns' and a string 'word', return the number
of strings in 'patterns' that exist as a substring in 'word'. a substring is
a contiguous sequence of characters within a string.
"""


class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ans = 0
        for i in patterns:
            if i in word:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfStrings(patterns=["a", "abc", "bc", "d"], word="abc"))
    print(obj.numOfStrings(patterns=["a", "b", "c"], word="aaaaabbbbb"))
    print(obj.numOfStrings(patterns=["a", "a", "a"], word="ab"))
