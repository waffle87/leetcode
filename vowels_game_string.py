# 3227. Vowels Game in a String

"""
alice and bob are playing a game on a string. you are given a string 's',
alice and bob will take turns playing the following game where alice starts
first. on alice's turn, she has to remove any non-empty substring from 's'
that contains an odd number of vowels. on bob's turn, he has to remove any
non-empty substring from 's' that contains an even number of vowels. the
first player who cannot make a move on their turn loses the game. we assume
that both bob and alice play optimally. return true if alice wins, and false
"""


class Solution(object):
    def doesAliceWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for i in s:
            if i in "aeiou":
                return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.doesAliceWin(s="leetcoder"))
    print(obj.doesAliceWin(s="bbcd"))
