# 3100. Water Bottles II

"""
you are given two integers 'numBottles' and 'numExchange'. 'numBottles'
represents the number of full water bottoles that you are initially given. in
one operation, you can perform one of the following operations: drink any
number of full bottles, turning them into empty bottles, or exchange
'numExchange' empty bottles with one full water bottle, then increase
'numExchange' by 1. return the maximum number of water bottles you can drink
"""


class Solution(object):
    def maxBottlesDrunk(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """


class Solution(object):
    def maxBottlesDrunk(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        ans = numBottles
        while numBottles >= numExchange:
            numBottles -= numExchange - 1
            numExchange += 1
            ans += 1
        return ans


if __name__ == "__main__":
    ans = numBottles
    while numBottles >= numExchange:
        numBottles -= numExchange - 1
        numExchange += 1
        ans += 1
    return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxBottlesDrunk(13, 6))
    print(obj.maxBottlesDrunk(10, 3))
