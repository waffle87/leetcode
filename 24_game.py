# 679. 24 Game
from itertools import permutations
from math import isclose

"""
given an integer array 'cards' of length 4. you have four cards, each
containing a number in the range '[1,9]'. you should arrange the numbers on
these cards in a mathematical expression using the operators '[+,-,*,/]' and
the parenthesis '(' and ')' to get value 24. you are restricted to the
following rules:
- the division operation represents real division, not integer division
- every operation done is between two numbers. in particular, we cannot use
'-' as a unary operator
- you cannot concatenate numbers together
return true if you can get such expression that evaluates to 24 and false
otherwise.
"""


class Solution(object):
    def judgePoint24(self, cards):
        """
        :type cards: List[int]
        :rtype: bool
        """
        if len(cards) == 1:
            return isclose(cards[0], 24)
        return any(
            self.judgePoint24([x] + rest)
            for a, b, *rest in permutations(cards)
            for x in {a + b, a - b, a * b, b and a / b}
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.judgePoint24([4, 1, 8, 7]))
    print(obj.judgePoint24([1, 2, 1, 2]))
