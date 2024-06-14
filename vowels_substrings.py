# 2063. Vowels of All Substrings

"""
given a string 'word, return thesum of the number of vowels (a, e, i, o, u)
in every substring of 'word'. a substringis a contiguous (non-empty) sequence
of characters within a string. note, due to the large constraints, the answer
may not fit in a signed 32-bit integer. please be careful during
calculates...
"""


class Solution(object):
    def countVowels(self, word):
        ans, n = 0, len(word)
        d = {"a": 1, "e": 1, "i": 1, "o": 1, "u": 1}
        for i in range(n):
            if word[i] in d:
                ans += (n - i) * (i + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countVowels("aba"))  # expect: 6
    print(obj.countVowels("abc"))  # expect: 3
    print(obj.countVowels("ltcd"))  # expect: 0
