# 2240. Number of Ways to Buy Pens and Pencils

"""
given an integer 'total' indicating the amount of money you have. you are
also given two inegers 'cost1' and 'cost2' indicating the price of a pen and
pencil respectively. you can spend part or all of your money to buy multiple
quantities (or none) of each kind of writing utensil. return the number of
distinct ways you can buy some number of pens and pencils
"""


class Solution(object):
    def waysToBuyPensPencils(self, total, cost1, cost2):
        """
        :type total: int
        :type cost1: int
        :type cost2: int
        :rtype: int
        """
        ways, pen_cost = 0, 0
        while pen_cost <= total:
            remaining = total - pen_cost
            pencils = remaining // cost2 + 1
            ways += pencils
            pen_cost += cost1
        return ways


if __name__ == "__main__":
    obj = Solution()
    print(obj.waysToBuyPensPencils(20, 10, 5))
    print(obj.waysToBuyPensPencils(5, 10, 10))
