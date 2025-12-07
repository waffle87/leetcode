# 1523. Count Odd Numbers in an Interval Range

"""
given two non-negative integers 'low' and 'high' return the
count of odd numbers  * between 'low' and 'high' (incusively)
"""


class Solution(object):
    def countOdds(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: int
        """
        return (high + 1) // 2 - low // 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.countOdds(low=3, high=7))
    print(obj.countOdds(low=8, high=10))
