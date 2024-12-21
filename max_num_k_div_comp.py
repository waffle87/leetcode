# 2872. Maximum Number of K-Divisible Components
from collections import defaultdict, deque

"""
there is an undirected tree with 'n' nodes labeled from 0 to 'n - 1'. you are
given the integer 'n' and a 2d integer array 'edges' of length 'n - 1', where
'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes 'a_i'
and 'b_i' in the tree. you are also given a 0-indexed integer array 'values'
of length 'n' where 'values[i]' is the value associated with the i'th node
and an integer 'k'. a valid split of the tree is obtained by removing any set
of edges, possibly empty, from the tree such that the resulting components
all have values thatare divisible by 'k', where the value of a connected
component is the sum of the values of its node. return the maximum number of
components in any valid split
"""


class Solution(object):
    def maxKDivisibleComponents(self, n, edges, values, k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type values: List[int]
        :type k: int
        :rtype: int
        """
        if n < 2:
            return 1
        graph, degree = defaultdict(list), [0] * n
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
            degree[a] += 1
            degree[b] += 1
        node_values, cnt = values[:], 0
        leaf = deque([i for i in range(n) if degree[i] == 1])
        while leaf:
            curr = leaf.popleft()
            degree[curr] -= 1
            carry = 0
            if node_values[curr] % k == 0:
                cnt += 1
            else:
                carry = node_values[curr]
            for n in graph[curr]:
                if degree[n] == 0:
                    continue
                degree[n] -= 1
                node_values[n] += carry
                if degree[n] == 1:
                    leaf.append(n)
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxKDivisibleComponents(
            n=5, edges=[[0, 2], [1, 2], [1, 3], [2, 4]], values=[1, 8, 1, 4, 4], k=6
        )
    )
    print(
        obj.maxKDivisibleComponents(
            n=7,
            edges=[[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [2, 6]],
            values=[3, 0, 6, 1, 5, 2, 1],
            k=3,
        )
    )
