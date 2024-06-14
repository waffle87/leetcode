# 1442. Count Triplets That Can Form Two Arrays of Equal XOR

"""
given an array of integers 'arr'. we want to select three indices 'i', 'j',
and 'k' where '(0 <= i < j <= k < arr.length)'. lets define 'a' and 'b' as
follows. 'a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]', 'b = arr[j] ^ arr[j +
1] ^ ... ^ arr[k]'. note that '^' denotes the bitwise xor operation. return
the number of triplets (i, j, and k) where 'a == b'
"""


class Solution(object):
    def countTriplets(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        arr.insert(0, 0)
        n, ans = len(arr), 0
        for i in range(n - 1):
            arr[i + 1] ^= arr[i]
        for i in range(n):
            for j in range(i + 1, n):
                if arr[i] == arr[j]:
                    ans += j - i - 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countTriplets([2, 3, 1, 6, 7]))
    print(obj.countTriplets([1, 1, 1, 1, 1]))
