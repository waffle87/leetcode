# 2957. Remove Adjacent Almost-Equal Characters

"""
you are given a 0 indexed string 'word'. in one operation you can pick any
index 'i' of 'word' and change 'word[i]' to any lowercase english letter.
return the minimum number of operations needed to remove all adjacent almost
equal characters from 'word'. two characters 'a' and 'b' are almost equal if
'a == b' or 'a' and 'b' are adjacent in the alphabet
"""


class Solution(object):
    def removeAlmostEqualCharacters(self, word):
        """
        :type word: str
        :rtype: int
        """
        i, k = 1, 0
        while i + k < len(word):
            k += abs(ord(word[i + k]) - ord(word[i + k - 1])) < 2
            i += 1
        return k


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeAlmostEqualCharacters("aaaaa"))
    print(obj.removeAlmostEqualCharacters("abddez"))
    print(obj.removeAlmostEqualCharacters("zyxyxyz"))
