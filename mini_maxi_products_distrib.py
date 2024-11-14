# 2064. Minimized Maximum of Products Distributed to Any Store
from math import ceil

"""
you are given an integer 'n' indicating that there are 'n' specialty retail
stores. there are 'm' product types of varying amounts, which are given as a
0-indexed integer array 'quantities' owhere 'quantities[i]' represents the
number of products of the i'th product type. you need to distribute all the
products to the retail stores following these rules: a store can only be
given at most one product type but can be given any amount of it, and after
distribution, each store will have been given some number products. let 'x'
represent the maximum number of products given to any store. you want 'x' to
be as small as possible. return the minimum possible 'x'.
"""


class Solution(object):
    def minimizedMaximum(self, n, quantities):
        """
        :type n: int
        :type quantities: List[int]
        :rtype: int
        """
        right, left = 0, max(quantities)
        while right + 1 < left:
            mid = (right + left) // 2
            if sum(ceil(i / mid) for i in quantities) <= n:
                left = mid
            else:
                right = mid
        return left


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimizedMaximum(n=6, quantities=[11, 6]))
    print(obj.minimizedMaximum(n=7, quantities=[15, 10, 10]))
    print(obj.minimizedMaximum(n=1, quantities=[100000]))
