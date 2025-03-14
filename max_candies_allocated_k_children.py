# 2226. Maximum Candies Allocated to K Children

"""
you are given a 0-indexed integer array 'candies'. each element in the array
denotes a pile of candies of size 'candies[i]'. you can divide each pile into
any number of sub piles, but you cannot merge two piles together. you are
also given an integer 'k'. you should allocate piles of candies to 'k'
children such that each child gets the same number of candies. each child can
be allocated candies from only one pile of candies, and some piles of candies
may go unused. return the maximum number of candies each child can get
"""


class Solution(object):
    def maximumCandies(self, candies, k):
        """
        :type candies: List[int]
        :type k: int
        :rtype: int
        """
        l, r = 0, sum(candies) / k
        while l < r:
            mid = (l + r + 1) / 2
            if k > sum(i / mid for i in candies):
                r = mid - 1
            else:
                l = mid
        return l


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumCandies(candies=[5, 8, 6], k=3))
    print(obj.maximumCandies(candies=[2, 5], k=11))
