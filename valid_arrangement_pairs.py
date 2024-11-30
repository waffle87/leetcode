# 2097. Valid Arrangement of Pairs
from collections import defaultdict

"""
you are given a 0-indexed 2d integer array 'pairs' where 'pairs[i] =
[start_i, end_i]'. an arrangement of 'pairs' is valid for every index 'i'
where '1 <= i < pairs.length', we have 'end_i-1 == start_i'. return any valid
arrangement of 'pairs'. note, the inputs will be generated such that there
exists a valid arrangement of 'pairs'.
"""


class Solution(object):
    def validArrangement(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: List[List[int]]
        """
        graph, degree = defaultdict(list), defaultdict(int)
        for x, y in pairs:
            graph[x].append(y)
            degree[x] += 1
            degree[y] -= 1
        for k in degree:
            if degree[k] == 1:
                x = k
                break
        ans = []

        def euler(x):
            while graph[x]:
                euler(graph[x].pop())
            ans.append(x)

        euler(x)
        ans.reverse()
        return [[ans[i], ans[i + 1]] for i in range(len(ans) - 1)]


if __name__ == "__main__":
    obj = Solution()
    print(obj.validArrangement(pairs=[[5, 1], [4, 5], [11, 9], [9, 4]]))
    print(obj.validArrangement(pairs=[[1, 3], [3, 2], [2, 1]]))
    print(obj.validArrangement(pairs=[[1, 2], [1, 3], [2, 1]]))
