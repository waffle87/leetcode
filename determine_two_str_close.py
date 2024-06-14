# 1657. Determine if Two Strings Are Close

"""
two strings are considered close if you can attain one from the other using
the following operations. operation 1:swap any two existing characters.
operation 2: transform every occurence of one exiting character into another
existing character, and do the same with the other character. you can use the
operations on either string as many times as necessary.given two strings 'w1'
and 'w2', return true if 'w1' and 'w2' are close and false otherwise.
"""


class Solution(object):
    def closeStrings(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: bool
        """
        freq1 = [0] * 26
        freq2 = [0] * 26
        for char in word1:
            freq1[ord(char) - ord("a")] += 1
        for char in word2:
            freq2[ord(char) - ord("a")] += 1
        for i in range(26):
            if (freq1[i] == 0 and freq2[i] != 0) or (freq2[i] == 0 and freq1[i] != 0):
                return False
        freq1.sort()
        freq2.sort()
        for i in range(26):
            if freq1[i] != freq2[i]:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.closeStrings(word1="abc", word2="bca"))
    print(obj.closeStrings(word1="a", word2="aa"))
    print(obj.closeStrings(word1="cabbba", word2="abbccc"))
