# 1524. Number of Sub-arrays With Odd Sum

"""
given an array of integers 'arr', return the number of subarrays with an odd
sum. since the answer can be very large, return it modulo 10e9+7.
"""


class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        p = int(bytearray(arr).translate(b"01" * 128), 2)
        s = 1
        while s < len(arr):
            p ^= p >> s
            s <<= 1
        odd = p.bit_count()
        return odd * (len(arr) + 1 - odd) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfSubarrays(arr=[1, 3, 5]))
    print(obj.numOfSubarrays(arr=[2, 4, 6]))
    print(obj.numOfSubarrays(arr=[1, 2, 3, 4, 5, 6, 7]))
