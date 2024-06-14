# 1704. Determine if String Halves Are Alike

"""
given a string 's' of even length. split this string into two halves of equal
lengths and let 'a' be the first half and 'b' be the second half. two strings
are alike if they have the same number of vowels (a e i o u, A E I O U)
notice that 's' contains uppercase and lowercase letters. return 'true' if a
and b are alike, otherwise return false.
"""


class Solution(object):
    def halvesAreAlike(self, s):
        vowels = set("aeiouAEIOU")
        a = b = 0
        i, j = 0, len(s) - 1
        while i < j:
            a += s[i] in vowels
            b += s[j] in vowels
            i += 1
            j -= 1
        return a == b


if __name__ == "__main__":
    obj = Solution()
    print(obj.halvesAreAlike("book"))  # expect: True
    print(obj.halvesAreAlike("textbook"))  # expect: false
