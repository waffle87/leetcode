# 3161. Block Placement Queries
from sortedcontainers import SortedList
from itertools import pairwise
from bisect import bisect_right

"""
there exists an infinite number line, with its origin at 0 and extending
towards the positive x-axis. you are given a 2d array 'qeuries', which
contains two types of queries: for a query of type 1, 'queries{i} = {1, x}'.
build an obstacle at distance 'x' from the origin. it is guaranteed that
there is no obstacle at distance 'x' when the query is asked. for query type
2, 'queries{i} = {2, x, sz}'. check if it is possible to place a block of
size 'sz' anywhere in the range '{0, x}' on the line, such that the block
entirely lies in the range '{0, x}'. a block cannot be placed if it
intersects with any obstacle, but it may touch it. note that you do not
actually place the block. queries are separate. return a boolean array
'results' where 'results{i}' is true if you can place a block specified in
the i'th query of type 2, and false otherwise.
"""


class tree:
    def __init__(self, n):
        self.n = n
        self.l = [0] * (n + 1)

    def add(self, i, x):
        i += 1
        while i <= self.n:
            self.l[i] = max(self.l[i], x)
            i += i & -i

    def query(self, i):
        i += 1
        ans = 0
        while i:
            ans = max(ans, self.l[i])
            i -= i & -i
        return ans


class Solution(object):
    def getResults(self, queries):
        """
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        list = SortedList()
        n = min(5 * 10**4, len(queries) * 3)
        list.add(0)
        list.add(n)
        for i in queries:
            if i[0] == 1:
                curr = i[1]
                list.add(curr)
        bit, ans = tree(n + 1), []
        for i, j in pairwise(list):
            bit.add(j, j - i)
        for i in reversed(queries):
            if i[0] == 1:
                curr = i[1]
                idx = list.index(curr)
                post = list[idx + 1]
                prev = list[idx - 1]
                list.remove(curr)
                bit.add(post, post - prev)
            else:
                _, curr, size = i
                idx = list.bisect_right(curr)
                prev = list[idx - 1]
                ans.append(bit.query(prev) >= size or (curr - prev) >= size)
        ans.reverse()
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.getResults(queries=[[1, 2], [2, 3, 3], [2, 3, 1], [2, 2, 2]]))
    print(obj.getResults(queries=[[1, 7], [2, 7, 6], [1, 2], [2, 7, 5], [2, 7, 6]]))
