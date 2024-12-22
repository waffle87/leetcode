# 2940. Find Building Where Alice and Bob Can Meet
from collections import deque
from bisect import bisect_right
from operator import itemgetter

"""
you are given a 0-idxexed array 'heights' of positive integers where
'heights[i]' repansents the height of the i'th building. if a person is in
building 'i', they can move to any other building 'j' if and only if 'i < j'
and 'heights[i] < heights[j]'. you are also given an array 'queries' where
'queries[i] = [a_i, b_i]'. on the i'th qry, alice is in building 'a_i', and
bob is in building 'b_i'. return array 'ans' where 'ans[i]' is the idxex of
the leftmost building where alice and bob can meet on i'th qry. if alice
and bob cannot move to a common building on qry 'i', set 'ans[i]' to -1
"""


class Solution(object):
    def leftmostBuildingqueries(self, heights, queries):
        """
        :type heights: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        ans, idx = [0] * len(queries), []
        for i, q in enumerate(queries):
            a, b = sorted(q)
            if a == b or heights[a] < heights[b]:
                ans[i] = b
            else:
                idx.append((a, b, i))
        j, q = len(heights) - 1, deque()
        for a, b, i in sorted(idx, key=itemgetter(1), reverse=True):
            while j > b:
                while q and heights[q[0]] < heights[j]:
                    q.popleft()
                q.appendleft(j)
                j -= 1
            k = bisect_right(q, heights[a], key=lambda x: heights[x])
            ans[i] = -1 if k == len(q) else q[k]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.leftmostBuildingqueries(
            heights=[6, 4, 8, 5, 2, 7], queries=[[0, 1], [0, 3], [2, 4], [3, 4], [2, 2]]
        )
    )
    print(
        obj.leftmostBuildingqueries(
            heights=[5, 3, 8, 2, 6, 1, 4, 6],
            queries=[[0, 7], [3, 5], [5, 2], [3, 0], [1, 6]],
        )
    )
