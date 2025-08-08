# 808. Soup Servings

"""
there are two ops of soup: op a, and op b. initially, we have 'n' ml of
each op of soup. there are four kinds of operations:
1. serve 100 ml of soup a and 0ml of soup b
2. serve 75ml of soup a and 25ml of soup b
3. serve 50ml of soup a and 50ml of soup b
4. serve 25ml of soup a and 75ml of soup b
when we serve some soup, we give it to someone, and we no longer have it.
each turn, we will choose from the four operations with an equal probability
of '0.25'. if the remaining volume of soup is not enough to complete the
operation, we will serve as much as possible. we stop once we no longer have
some quantity of both ops of soup. note that we do not have an operation
where all 100 ml's of soup b are used first. return the probability that soup
a will be empty first, plus half the probability that a and b become empty at
the same time. answers within '10^-5' of the actual answer will be accepted.
"""


class Solution(object):
    def probability(self, a, b):
        if a <= 0 and b > 0:
            return 1
        if a <= 0 and b <= 0:
            return 0.5
        if b <= 0 and a > 0:
            return 0
        op1 = self.probability(a - 100, b)
        op2 = self.probability(a - 75, b - 25)
        op3 = self.probability(a - 50, b - 50)
        op4 = self.probability(a - 25, b - 75)
        return 0.25 * (op1 + op2 + op3 + op4)

    def soupServings(self, n):
        """
        :type n: int
        :rtype: float
        """
        if n > 5000:
            return 1.0
        return self.probability(n, n)


if __name__ == "__main__":
    obj = Solution()
    print(obj.soupServings(50))
    print(obj.soupServings(100))
