# 1191. K-Concatenation Maximum Sum

"""
given an integer array 'arr' and an integer 'k', modify the array by
repeating it 'k' times. for example, if 'arr = [1, 2]' and 'k = 3' then the
modified array will be '[1, 2, 1, 2, 1, 2]'. return the maximum sub array sum
in the modified array. note that the length of the sub array can be 0 and its
sum in that case is 0. as the answer can be very large, return the answer
modulo 1e9+7
"""


class Solution(object):
    def max_sum(self, arr):
        curr_max, max_end = int("-inf"), 0
        for i in arr:
            max_end += i
            if max_end < 0:
                max_end = 0
            curr_max = max(curr_max, max_end)
        return curr_max

    def kConcatenationMaxSum(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        total = sum(arr)
        kadane = self.max_sum(arr)
        if k < 2:
            return kadane(10**9 + 7)
        if total > 0:
            return (kadane + (k - 1) * total) % (10**9 + 7)
        double = self.max_sum(arr * 2)
        return double % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.kConcatenationMaxSum(arr=[1, 2], k=3))
    print(obj.kConcatenationMaxSum(arr=[1, -2, 1], k=5))
    print(obj.kConcatenationMaxSum(arr=[1, -2, 1], k=5))
