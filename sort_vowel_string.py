# 2785. Sort Vowels in a String

"""
 given a 0-indexed string 's', permute 's' to get a new string 't'.
 - All consonants remain in their original places. More formally, if there is
an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] =
s[i].
- The vowels must be sorted in the nondecreasing order of their ASCII
values. More formally, for pairs of indices i, j with 0 <= i < j < s.length
such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII
value than t[j].
  return the resulting string. consonants comprise all letter that are not
vowels.
"""


class Solution(object):
    def sortVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowel_map = set("AEIOUaeiou")
        vowels = [i for i in s if i in vowel_map]
        vowels.sort()
        ans, i = [], iter(vowels)
        for j in s:
            ans.append(next(i) if j in vowel_map else j)
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortVowels("lEetcOde"))
    print(obj.sortVowels("lYmpH"))
