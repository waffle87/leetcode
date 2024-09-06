# 658. Find K Closest Elements

"""
given a sorted integer array 'arr', two integers 'k' and 'x', return the 'k'
closest integers to 'x' in the array. the result should also be sorted in
ascending order. an integer 'a' is closer to 'x' than an integer 'b' if '|a -
x| < |b - x|' or '|a - x| == |b - x|' and 'a < b'.
"""


class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        l, r = 0, len(arr) - k
        while l < r:
            m = (l + r) / 2
            if x - arr[m] > arr[m + k] - x:
                l = m + 1
            else:
                r = m
        return arr[l : l + k]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findClosestElements(arr=[1, 2, 3, 4, 5], k=4, x=3))
    print(obj.findClosestElements(arr=[1, 2, 3, 4, 5], k=4, x=-1))
