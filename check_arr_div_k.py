# 1497. Check If Array Pairs Are Divisible by k

"""
given an array of integers 'arr' of even length 'n' and an integer 'k'. we
want to divide the array into exactly 'n / 2' pairs such that the sum of each
pair is divisible by 'k'. return 'true' if you can find a way to to that or
'false' otherwise.
"""


class Solution(object):
    def canArrange(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: bool
        """
        cnt = [0] * k
        for i in arr:
            cnt[i % k] += 1
        i, j = 1, k - 1
        pairs = 0
        while i < j:
            if cnt[i] != cnt[j]:
                return False
            pairs += cnt[i]
            i += 1
            j -= 1
        if pairs > 0 and i == j:
            pairs += cnt[i] / 2
        pairs += cnt[0] / 2
        n = len(arr)
        return pairs == n // 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.canArrange(arr=[1, 2, 3, 4, 5, 10, 6, 7, 8, 9], k=5))
    print(obj.canArrange(arr=[1, 2, 3, 4, 5, 6], k=7))
    print(obj.canArrange(arr=[1, 2, 3, 4, 5, 6], k=10))
