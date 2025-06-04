# 3403. Find the Lexicographically Largest String From the Box I

"""
you are given a string 'word', and an integer 'numFriends'. alice is
organising a game for her 'numFriends' friends. there are multiple rounds in
the game, where each round: 'word' is split into 'numFriends' non-empty
strings such that no previous round has the exact same split, and all the
split words are put into a box. find the lexicographically largest string
from the box after all rounds are finished.
"""


class Solution(object):
    def answerString(self, word, numFriends):
        """
        :type word: str
        :type numFriends: int
        :rtype: str
        """
        n = len(word)
        m = n - numFriends + 1
        if numFriends == 1:
            return word
        return max(word[i : i + m] for i in range(n))


if __name__ == "__main__":
    obj = Solution()
    print(obj.answerString(word="dbca", numFriends=2))
    print(obj.answerString(word="gggg", numFriends=4))
