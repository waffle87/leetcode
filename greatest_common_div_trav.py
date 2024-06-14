# 2709. Greatest Common Divisor Traversal

"""
given a 0-indexed integer array 'nums' and you are allowed to traverse
between its indices, you can traverse between index 'i' and index 'j', 'i !=
j' if and only if 'gcd(nums[i], nums[j]) > 1' where 'gcd' is the greatest
common divisor. your task is to determine if for every pair of indices 'i'
and 'j' in 'nums' where 'i < j', there exists a sequence of traversals that
can take use from 'i' to 'j'. return true if it is possible to traverse
between all such pairs of indices or false otherwise.
"""


class Solution(object):
    def canTraverseAllPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if n == 1:
            return True
        f = [_ for _ in range(0, n)]
        num = [1] * n

        def getf(x: int) -> int:
            if f[x] == x:
                return x
            f[x] = getf(f[x])
            return f[x]

        def merge(x: int, y: int):
            x, y = getf(x), getf(y)
            if x == y:
                return
            if num[x] < num[y]:
                x, y = y, x
            f[y] = x
            num[x] += num[y]

        have = {}
        for i in range(0, n):
            x = nums[i]
            if x == 1:
                return False
            d = 2
            while d * d <= x:
                if x % d == 0:
                    if d in have:
                        merge(i, have[d])
                    else:
                        have[d] = i
                    while x % d == 0:
                        x //= d
                d += 1
            if x > 1:
                if x in have:
                    merge(i, have[x])
                else:
                    have[x] = i
        return num[getf(0)] == n


if __name__ == "__main__":
    obj = Solution()
    print(obj.canTraverseAllPairs([2, 3, 6]))
    print(obj.canTraverseAllPairs([3, 9, 5]))
    print(obj.canTraverseAllPairs([4, 3, 12, 8]))
