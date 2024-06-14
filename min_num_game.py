# 2974. Minimum Number Game
from functools import reduce
from pandas import concat

"""
given a 0-indexed array 'ums' of even length and there is also an empty array
'arr'. alice and bob decided to play a game where in every round alice and
bob will do one move. the rules of the game are as follows: every round,
first alice will remove the minimum element from 'nums', and then bob does
the same. now, first bob will append the removed element in the array 'arr'
and alice does the same. the game continues until 'nums' becomes empty.
return the resulting array 'arr'.
"""


class Solution(object):
    def numberGame(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = iter(sorted(nums))
        return reduce(concat, [(b, a) for a, b in zip(n, n)])


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberGame(nums=[5, 4, 2, 3]))
    print(obj.numberGame(nums=[2, 5]))
