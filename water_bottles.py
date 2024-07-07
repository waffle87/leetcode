# 1518. Water Bottles

"""
there are 'numBottles' water bottles that are initially full of water. you
can exchange 'numExchange' empty water botls from the market with one full
water bottle. the operation of drinking a full water bottle turns into an
empty bottle. given the two integers 'numBottles' and 'numExchange', return
the maximum number of water bottles you can drink
"""


class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        return (numBottles * numExchange - 1) // (numExchange - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numWaterBottles(9, 3))
    print(obj.numWaterBottles(15, 4))
