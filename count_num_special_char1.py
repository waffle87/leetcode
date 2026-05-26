# 3120. Count the Number of Special Characters I

"""
you are given a string 'word'. a letter is called special if it appears both
in lowercase and uppercase in 'word'. return the number of special characters
in 'word'.
"""


class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        return (s := {*word}) and sum(chr(ord(c) + 32) in s for c in s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfSpecialChars(word="aaAbcBC"))
    print(obj.numberOfSpecialChars(word="abc"))
    print(obj.numberOfSpecialChars(word="abBCab"))
