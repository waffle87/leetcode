# 1566. Detect Pattern of Length M Repeated K or More Times

"""
given an array of positive integers 'arr', find a pattern of length 'm' that
is repeated 'k' or more times. a pattern is a subarray (consecutive
subsequence) that consists of one or more values repeated multiple times
consecutively without overlapping. a pattern is defined by its length and the
number of repetitions. return true if there exists a pattern of length 'm'
that is repeated 'k' or more times, otherwise return false
"""


class Solution(object):
    def containsPattern(self, arr, m, k):
        """
        :type arr: List[int]
        :type m: int
        :type k: int
        :rtype: bool
        """
        n = 0
        for i in range(len(arr) - m):
            n = n + 1 if arr[i] == arr[i + m] else 0
            if n == (k - 1) * m:
                return True
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.containsPattern(arr=[1, 2, 4, 4, 4, 4], m=1, k=3))
    print(obj.containsPattern(arr=[1, 2, 1, 2, 1, 1, 1, 3], m=2, k=2))
    print(obj.containsPattern(arr=[1, 2, 1, 2, 1, 3], m=2, k=3))
