# 1595. Minimum Cost to Connect Two Groups of Points
from functools import lru_cache

"""
you are given two groups of points where the first group has 'size_i' points,
the second group has 'size_j' points, and 'size_i >= size_j'. the 'cost' of
the connection between any two points are giveen in 'size_i  size_j' matrix
where 'cost[i][j]' is the cost of connecting point 'i' of the first group and
point 'j' of the second group. the groups are connected if each oint in both
groups is connected to one or more points in the opposite group. in other
words, each point in the first group must be connected to at least one pooint
in the second group. return the minimum cost it takes to connect the two
groups.
"""


class Solution(object):
    def connectTwoGroups(self, cost):
        """
        :type cost: List[List[int]]
        :rtype: int
        """
        n, m = len(cost), len(cost[0])
        smallest = [min([cost[i][j] for i in range(n)]) for j in range(m)]

        @lru_cache(None)
        def dfs(i, mask):
            res = 0 if i >= n else float("inf")
            if i >= n:
                for j in range(m):
                    if mask & (1 << j) == 0:
                        res += smallest[j]
            else:
                for j in range(m):
                    res = min(res, cost[i][j] + dfs(i + 1, mask | (1 << j)))
            return res

        return dfs(0, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.connectTwoGroups(cost=[[15, 96], [36, 2]]))
    print(obj.connectTwoGroups(cost=[[1, 3, 5], [4, 1, 1], [1, 5, 3]]))
    print(
        obj.connectTwoGroups(
            cost=[[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
        )
    )
