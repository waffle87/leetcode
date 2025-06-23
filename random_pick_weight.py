# 528. Random Pick with Weight
from itertools import accumulate
from bisect import bisect_left
from random import randint

"""
you are given a 0-indexed array of positive integers 'w' where 'w[i]'
describes the weight of the i'th index. you need to implement the function
'pickIndex()' which randomly picks an index in the range '[0, w.len - 1]' and
returns it. the probability of picking an index 'i' is 'w[i] / sum(w)'.
"""


class Solution(object):
    def __init__(self, w):
        """
        :type w: List[int]
        """
        self.w = list(accumulate(w))

    def pickIndex(self):
        """
        :rtype: int
        """
        return bisect_left(self.w, randint(1, self.w[-1]))


if __name__ == "__main__":
    obj1 = Solution([1])
    obj2 = Solution([1, 3])
    print(obj1.pickIndex())
    print(obj1.pickIndex())
    print(obj1.pickIndex())
    print(obj1.pickIndex())
    print(obj1.pickIndex())
    print(obj1.pickIndex())
