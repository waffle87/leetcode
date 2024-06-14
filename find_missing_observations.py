# 2028. Find Missing Observations

"""
you have observations of n + m 6 sided dice rolls withh each face numbered
from 1 to 6. n of the observations went missing and you only have the
observations of m rolls. fortunately, you have also calculated thhe average
value of the n + m rolls. you are given an integer array rolls of length m
where rolls[i] is the value of the i'th observation. you are also given the
two integers mean and n. return an array of length n containing thhe missing
observations such that the average value of the n + m rolls is exactly mean.
if there are multiple valid answers, return any of them. if no such array
exists, return an empty array. thhe average value of a set of k numbers is
the sum of the numbers divided by k. note that mean is an integer so the sum
of the n + m rolls should be divisble by n + m.
"""


class Solution(object):
    def missingRolls(self, rolls, mean, n):
        """
        :type rolls: List[int]
        :type mean: int
        :type n: int
        :rtype: List[int]
        """
        m = len(rolls)
        curr = sum(rolls)
        missing = mean * (n + m) - curr
        if missing < n or missing > 6 * n:
            return []

        part, rem = divmod(missing, n)
        ans = [part] * n
        for i in range(rem):
            ans[i] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.missingRolls(rolls=[3, 2, 4, 3], mean=4, n=2))
    print(obj.missingRolls(rolls=[1, 5, 6], mean=3, n=4))
    print(obj.missingRolls(rolls=[1, 2, 3, 4], mean=6, n=4))
