# 2698. Find the Punishment Number of an Integer
from bisect import bisect_right
from itertools import accumulate

"""
given a positive integer 'n', return the punishment number of 'n'. the
punishment number of 'n' is defined as the sum of the squares of all integers
'i' such that '1 <= i <= n' and the decimal representation of 'i * i' can be
partitioned into contiguous substrings such that the sum of the integer
values of the substrings equals 'i'.
"""

sqr = lambda x: x * x
f = lambda x: x % 9 < 2 and valid(x)
nums = tuple(filter(f, tuple(range(1, 1001))))
punish = tuple(accumulate(map(sqr, nums), initial=0))


class Solution:
    def valid(self, n):
        sq = str(sqr(n))
        for i in range(1 << (len(sq) - 1)):
            s = [str()]

            for j, ch in enumerate(sq):
                s[-1] += ch
                if i & (1 << j):
                    s.append(str())

            if sum(map(int, s)) == n:
                return True

        return False

    def punishmentNumber(self, n):
        return punish[bisect_right(nums, n)]


if __name__ == "__main__":
    obj = Solution()
    print(obj.punishmentNumber(10))
    print(obj.punishmentNumber(37))
