# 754. Reach a Number
import math

"""
you are standing at position zero on an infinite number line. there is a
destination at position 'target'. you can make some number of moves
'numMoves' so that on each move you can either go left or right, during the
i'th move starting from 'i == 1' to 'i == numMoves', you take 'i' steps in
the chosen direction. given the integer 'target', return the minimum number
of moves required to reach the destination
"""


class Solution(object):
    def reachNumber(self, target):
        """
        :type target: int
        :rtype: int
        """
        bound = math.ceil(math.sqrt(2 * abs(target) + 0.25) - 0.5)
        if target % 2 == 0:
            if bound % 4 == 1:
                bound += 2
            if bound % 4 == 2:
                bound += 1
        else:
            if bound % 4 == 3:
                bound += 2
            if bound % 4 == 0:
                bound += 1
        return bound


if __name__ == "__main__":
    obj = Solution()
    print(obj.reachNumber(2))
    print(obj.reachNumber(3))
