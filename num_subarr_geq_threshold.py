# 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to
# Threshold

"""
given an array of integers 'arr' and two integers 'k' and 'threshold', return
the numberof subarrays of size 'k' and average greater than or equal to
'threshold'
"""


class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        n, total = len(arr), sum(arr[:k])
        cnt = 1 if total / k >= threshold else 0
        for i in range(k, n):
            total += arr[i] - arr[i - k]
            if total / k >= threshold:
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfSubarrays(arr=[2, 2, 2, 2, 5, 5, 5, 8], k=3, threshold=4))
    print(
        obj.numOfSubarrays(arr=[11, 13, 17, 23, 29, 31, 7, 5, 2, 3], k=3, threshold=5)
    )
