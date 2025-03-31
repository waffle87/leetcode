# 2551. Put Marbles in Bags

"""
you have 'k' bags. you are given a 0-indexed integer array 'weights' where
'weights[i]' is the weight of the i'th marble. you are also given the integer
'k'. divide the marbles into the 'k' bags according to the following rules
- no bag is empty
- if the i'th marble and the j'th marble are in a bag, then all the marbles
with an index between the i'th and j'th indices should also be in that same
bag.
- if a bag onsists of all the marbles with an index from 'i' to 'j'
inclusively, then the cost of the bag is 'weights[i] + weights[j]' the score
after distributing the marbles is the sum of the costs of all the 'k' bags.
return the difference between the maximum and minimum scores among marble
distributions
"""


class Solution(object):
    def putMarbles(self, weights, k):
        """
        :type weights: List[int]
        :type k: int
        :rtype: int
        """
        pairs = sorted([weights[i] + weights[i + 1] for i in range(len(weights) - 1)])
        return sum(pairs[len(pairs) - k + 1 :]) - sum(pairs[: k - 1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.putMarbles(weights=[1, 3, 5, 1], k=2))
    print(obj.putMarbles(weights=[1, 3], k=2))
