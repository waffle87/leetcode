# 786. K-th Smallest Prime Fraction
from bisect import bisect

"""
given a sorted integer array 'arr' containing '1' and  prime numbers where
all the integers of 'arr' are unique. you are also given an integer 'k'. for
every 'i' and 'j' where '0 <= i < j < arr.len', we consider the fraction
'arr[i] / arr[j]'. return the k'th smallest fraction considered. return your
answer as an array of integers of size '2'.
"""


class Solution(object):
    def kthSmallestPrimeFraction(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        left, right, n = 0, 1, len(arr)
        while True:
            mid = (left + right) / 2
            border = [bisect(arr, arr[i] / mid) for i in range(n)]
            curr = sum(n - i for i in border)
            if curr > k:
                right = mid
            elif curr < k:
                left = mid
            else:
                return max(
                    [(arr[i], arr[j]) for i, j in enumerate(border) if j < n],
                    key=lambda x: x[0] / x[1],
                )


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthSmallestPrimeFraction(arr=[1, 2, 3, 5], k=3))
    print(obj.kthSmallestPrimeFraction(arr=[1, 7], k=1))
