# 846. Hand of Straights
from collections import Counter

"""
alice has some number of cards and she wants to rearrange the cards into
groups so that each group is of size 'groupSize' and consists of 'groupSize'
consecutive cards. given an integer array 'hand' where 'hand[i]' is the value
written on the i'th card and an integer 'groupSize', return true if she can
rearrange the cards or false otherwise.
"""


class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        """
        :type hand: List[int]
        :type groupSize: int
        :rtype: bool
        """
        c = Counter(hand)
        for i in sorted(c):
            if c[i] > 0:
                for j in range(groupSize)[::-1]:
                    c[i + j] -= c[i]
                    if c[i + j] < 0:
                        return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.isNStraightHand(hand=[1, 2, 3, 6, 2, 3, 4, 7, 8], groupSize=3))
    print(obj.isNStraightHand(hand=[1, 2, 3, 4, 5], groupSize=4))
