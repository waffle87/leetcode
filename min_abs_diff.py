# 1200. Minimum Absolute Difference

"""
given an array of distinct integers 'arr', find all pairs of elements with
the minimum absolute difference of any two elements. return a list of pairs
in ascending order (with respect to pairs), each pair '[a, b]' follows: 'a,
b' are from 'arr', 'a < b', and 'b - a' equals to the minimum absolute
difference of any two elements in 'arr'.
"""


class Solution(object):
    def minimumAbsDifference(self, arr):
        """
        :type arr: List[int]
        :rtype: List[List[int]]
        """
        arr.sort()
        m = min(b - a for a, b in zip(arr, arr[1:]))
        return [[a, b] for a, b in zip(arr, arr[1:]) if b - a == m]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumAbsDifference(arr=[4, 2, 1, 3]))
    print(obj.minimumAbsDifference(arr=[1, 3, 6, 10, 15]))
    print(obj.minimumAbsDifference(arr=[3, 8, -10, 23, 19, -4, -14, 27]))
