# 2000. Reverse Prefix of Word

"""
given a 0-indexed string 'word' and a character 'ch', reverse the segment of
'word' that starts at index 0 and ends at the index of the first occurence of
'ch' (inclusively). if the character 'ch' does not exist in 'word', do
nothing. return the resulting string.
"""


class Solution(object):
    def reversePrefix(self, word, ch):
        """
        :type word: str
        :type ch: str
        :rtype: str
        """
        idx = word.find(ch)
        if idx:
            return word[: idx + 1][::-1] + word[idx + 1 :]
        return word


if __name__ == "__main__":
    obj = Solution()
    print(obj.reversePrefix("abcdefd", "d"))
    print(obj.reversePrefix("xyxzxe", "z"))
    print(obj.reversePrefix("abcd", "z"))
