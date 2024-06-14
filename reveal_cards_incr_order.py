# 950. Reveal Cards In Increasing Order
from collections import deque

"""
given an integer array 'deck'. there is a deck of cards where every card has
a unique integer. the integer on the i'th card is 'deck[i]'. you can order
the deck in any order you want. initially, all the cards start face down
(unrevealed) in one deck. you will do the following steps repeatedly until
all cards are revealed. take the top card of the deck, reveal it, and take it
out of the deck. if there are still cards in the deck, then put the next top
card of the deck at the bottom of the deck. if there are still unrevealed
cards, go back to step 1, otherwise stop. return an ordering of the deck that
would reveal the cards in increasing order.
"""


class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        d = deque()
        for i in sorted(deck)[::-1]:
            d.rotate()
            d.appendleft(i)
        return list(d)


if __name__ == "__main__":
    obj = Solution()
    print(obj.deckRevealedIncreasing(deck=[17, 13, 11, 2, 3, 5, 7]))
    print(obj.deckRevealedIncreasing(deck=[1, 1000]))
