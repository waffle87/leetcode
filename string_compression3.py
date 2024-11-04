# 3163. String Compression III

"""
given a string 'word', compress it using the following algorithm: begin with
an empty string 'comp'. while 'word' is not empty, use the following
operation: remove a maximum length prefix of 'word' made of a single
character 'c' repeating at most 9 times. append the length of the prefix
followed by 'c' to 'comp'. return the string 'comp'
"""


class Solution(object):
    def compressedString(self, word):
        """
        :type word: str
        :rtype: str
        """
        comp, c = "", word[0]
        cnt, n = 1, len(word)
        for i in range(1, n):
            if word[i] == c and cnt < 9:
                cnt += 1
            else:
                comp += str(cnt) + c
                c = word[i]
                cnt = 1
        comp += str(cnt) + c
        return comp


if __name__ == "__main__":
    obj = Solution()
    print(obj.compressedString(word="abcde"))
    print(obj.compressedString(word="aaaaaaaaaaaaaabb"))
