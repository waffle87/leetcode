# 3017. Count the Number of Houses at a Certain Distance II
from itertools import accumulate

"""
you are given three positive integers 'n', 'x', and 'y'. in a city, there
exists houses numbered 1 to 'n' connected by 'n' streets. there is a street
cnnecting the house numbered 'i' with the house numbered 'i + 1' for all '1
<= i <= n - 1'. an additional street connects the house numbered 'x' with the
house numbered 'y'. for each 'k' such that '1 <= k <= n', you need to find
the number of pairs of houses '(house_i, house_j)' such that the minimum
number of streets that need to be traveled to reach 'house_i' from 'house_j'
is 'k'. return a 1-indexed array of length 'n' where 'ans[k]' represents the
total number of pairs of houses such that the minimum streets required to
reach one house from the other is 'k'.
"""


class Solution(object):
    def countOfPairs(self, n, x, y):
        """
        :type n: int
        :type x: int
        :type y: int
        :rtype: List[int]
        """
        x, y = min(x, y), max(x, y)
        ans = [0] * n
        for i in range(1, n + 1):
            ans[0] += 2
            ans[min(i - 1, abs(i - y) + x)] -= 1
            ans[min(n - i, abs(i - x) + 1 + n - y)] -= 1
            ans[min(abs(i - x), abs(y - i) + 1)] += 1
            ans[min(abs(i - x) + 1, abs(y - i))] += 1
            r = max(x - i, 0) + max(i - y, 0)
            ans[r + (y - x + 0) // 2] -= 1
            ans[r + (y - x + 1) // 2] -= 1
        return list(accumulate(ans))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countOfPairs(n=3, x=1, y=3))
    print(obj.countOfPairs(n=5, x=2, y=4))
    print(obj.countOfPairs(n=4, x=1, y=1))
