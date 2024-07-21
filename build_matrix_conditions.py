# 2392. Build a Matrix With Conditions
from collections import deque

"""
you are givne a positive integer 'k'. you are also given a 2d integer array
'rowConditions' of size 'n' where 'rowConditions[i] = [above_i, below_i]' and
a 2d integer array 'colConditions' of size 'm' where 'colConditions[i] =
[left_i, right_i]'. the two arrays contain integers from 1 to 'k'. you have
to build a 'k  k' matrix that contains each of the numbers from 1 to 'k'
exactly once. the remaining cells should satisfy the following conditions.
the number 'above_i' should appear in a row that is strictly above the row at
which the number 'below_i' appears for all 'i'. the number 'left_i' should
appear in a column that is strictly left of the column at which the number
'right_i' appears for all 'i'. return any matrix that satisfies these
conditions.
"""


class Solution(object):
    def buildMatrix(self, k, rowConditions, colConditions):
        """
        :type k: int
        :type rowConditions: List[List[int]]
        :type colConditions: List[List[int]]
        :rtype: List[List[int]]
        """

        def helper(a):
            next, in_deg = [set() for _ in range(k)], [0] * k
            dq, res = deque(), []
            a = set([tuple(i) for i in a])
            for i, j in a:
                next[i - 1].add(j - 1)
                in_deg[j - 1] += 1
            for i in range(k):
                if in_deg[i] == 0:
                    dq.append(i)
            while dq:
                curr = dq.popleft()
                res.append(curr)
                for candidate in next[curr]:
                    in_deg[candidate] -= 1
                    if in_deg[candidate] == 0:
                        dq.append(candidate)
            return res if len(res) == k else []

        a1, a2 = helper(rowConditions), helper(colConditions)
        if not a1 or not a2:
            return []
        ans = [[0] * k for _ in range(k)]
        for i in range(k):
            ans[a1.index(i)][a2.index(i)] = i + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.buildMatrix(
            k=3, rowConditions=[[1, 2], [3, 2]], colConditions=[[2, 1], [3, 2]]
        )
    )
    print(
        obj.buildMatrix(
            k=3, rowConditions=[[1, 2], [2, 3], [3, 1], [2, 3]], colConditions=[[2, 1]]
        )
    )
