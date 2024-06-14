# 1356. Sort Integers by The Number of 1 Bits

"""
given an integer array 'arr', sort the integers in the array in ascending
order by the number of 1's in their binary representation and in case of two
or more integers have the same number of 1's, you have to sort them in
ascending order. return the array after sorting it.
"""


class Solution(object):
    def sortByBits(self, arr):
        n = len(arr)
        ans = [0] * n
        for i in range(n):
            ans[i] = self.count_bit(arr[i]) * 10001 + arr[i]
        ans.sort()
        for i in range(n):
            ans[i] %= 10001
        return ans

    def count_bit(self, n):
        res = 0
        while n != 0:
            res += n & 1
            n >>= 1
        return res


if __name__ == "__main__":
    obj = Solution()
    print(obj.sortByBits([0, 1, 2, 3, 4, 5, 6, 7, 8]))
    print(obj.sortByBits([1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1]))
