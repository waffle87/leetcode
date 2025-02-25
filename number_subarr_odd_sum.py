# 1524. Number of Sub-arrays With Odd Sum

"""
given an array of integers 'arr', return the number of subarrays with an odd
sum. since the answer can be very large, return it modulo 10e9+7.
"""


class Solution(object):
    def numOfSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        cnt = [1, 0]
        curr, ans = 0, 0
        for i in arr:
            curr ^= i & 1
            ans += cnt[1 - curr]
            cnt[curr] += 1
        return ans % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfSubarrays(arr=[1, 3, 5]))
    print(obj.numOfSubarrays(arr=[2, 4, 6]))
    print(obj.numOfSubarrays(arr=[1, 2, 3, 4, 5, 6, 7]))
