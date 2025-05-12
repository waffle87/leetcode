# 2094. Finding 3-Digit Even Numbers
from itertools import permutations

"""
you are given an integer 'digits' where each element is a digit. the array
may contain duplicates. you need to find all the unique integers that follow
the given requirements: the integer consists of the concatenation of three
elements from 'digits' in any arbitrary order, the integer does not have
leading zeros, and the integer is even. for example, if the given 'digits'
were '[1, 2, 3]' integers '132' and '312' follow the requirments. return a
sorted array of the unique integers.
"""


class Solution(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        return sorted(
            100 * v + 10 * u + w
            for v, u, w in {*permutations(digits, 3)}
            if v > 0 == w & 1
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.findEvenNumbers(digits=[2, 1, 3, 0]))
    print(obj.findEvenNumbers(digits=[2, 2, 8, 8, 2]))
    print(obj.findEvenNumbers(digits=[3, 7, 5]))
