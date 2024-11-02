# 2490. Circular Sentence

"""
a sentence is a list of words that are separated by a single space with no
leading or trailing spaces. words consist of only uppercase and lowercase
english letters. uppercase and lowercase english letters are considered
different. a sentence is circular if the last character of a word is equal to
the first character of the next word, the last chracter of the last word is
equal to the first character of the first word. given a string 'sentence',
return 'true' if it is a circular sentence, and 'false' otherwise.
"""


class Solution(object):
    def isCircularSentence(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        n = len(sentence)
        if sentence[0] != sentence[n - 1]:
            return False
        for i in range(1, n - 1):
            if sentence[i] == " ":
                if sentence[i - 1] != sentence[i + 1]:
                    return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.isCircularSentence(sentence="leetcode exercises sound delightful"))
    print(obj.isCircularSentence(sentence="eetcode"))
    print(obj.isCircularSentence(sentence="Leetcode is cool"))
