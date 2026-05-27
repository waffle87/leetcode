# 3121. Count the Number of Special Characters II
from string import ascii_lowercase

"""
you are given a string 'word'. a letter 'c' is called special if it appears
both in lowercase and uppercase in 'word', and every lowercase occurence of
'c' appears before the first uppercase occurence of 'c'. return the number of
special letters in 'word'.
"""


class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        d = {j: i for i, j in enumerate(word) if j.islower()}
        p = {j: len(word) - i for i, j in enumerate(reversed(word)) if j.isupper()}
        return sum(
            d.get(i, float("inf")) < p.get(i.upper(), 0) for i in ascii_lowercase
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfSpecialChars(word="aaAbcBC"))
    print(obj.numberOfSpecialChars(word="abc"))
    print(obj.numberOfSpecialChars(word="AbBCab"))
