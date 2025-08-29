# 3021. Alice and Bob Playing Flower Game

"""
alice and bob are playing a turn-based game on a field with two lanes of
flowers bet=een them. there are 'x' flowers in the first lane between alice
and bob, and 'y' flowers in the second lane between them. return the number
of possible pairs '(x, y)' that satisyf the conditions mentioned in the
statement.
"""


class Solution(object):
    def flowerGame(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        return n * m // 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.flowerGame(3, 2))
    print(obj.flowerGame(1, 1))
