# 1394. Find Lucky Integer in an Array
from collections import Counter

"""
given an array of integers 'arr', a lucky integer is an integer equal that
has a frequency in the array equal to its value. return the largest lucky
integer in the array. if there is no lucky integer, return -, a lucky integer
is an integer equal that has a frequency in the array equal to its value.
return the largest lucky integer in the array. if there is no lucky integer,
return -1
"""


class Solution(object):
    def findLucky(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        cnt = Counter(arr)
        return max([i for i, j in cnt.items() if i == j] + [-1])


if __name__ == "__main__":
    obj = Solution()
    print(obj.findLucky(arr=[2, 2, 3, 4]))
    print(obj.findLucky(arr=[1, 2, 2, 3, 3, 3]))
    print(obj.findLucky(arr=[2, 2, 2, 3, 3]))
