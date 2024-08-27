# 1514. Path with Maximum Probability
import collections

"""
given an undirected weighted graph of 'n' nodes (0-indexed). represented by
an edge list where 'edges[i] = [a, b]' is an undirected edge connecting the
nodes 'a' and 'b' with a probability of success of traversing that edge
'succ_prob[i]'. given two nodes 'start, end', find the path with the maximum
probability of success to go from 'start' to 'end' and return its success
probability. if there is no path from 'start' to 'end', return 0. your answer
will be accepted if it differs from the correct answer by at most '1e-5'
"""


class Solution(object):
    def maxProbability(self, n, edges, succProb, start_node, end_node):
        """
        :type n: int
        :type edges: List[List[int]]
        :type succProb: List[float]
        :type start_node: int
        :type end_node: int
        :rtype: float
        """
        g, dq = collections.defaultdict(list), collections.deque([start_node])
        for i, (a, b) in enumerate(edges):
            g[a].append([b, i])
            g[b].append([a, i])
        p = [0.0] * n
        p[start_node] = 1.0
        while dq:
            curr = dq.popleft()
            for n, i in g[curr]:
                if p[curr] * succProb[i] > p[n]:
                    p[n] = p[curr] * succProb[i]
                    dq.append(n)
        return p[end_node]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxProbability(
            n=3,
            edges=[[0, 1], [1, 2], [0, 2]],
            succProb=[0.5, 0.5, 0.2],
            start_node=0,
            end_node=2,
        )
    )
    print(
        obj.maxProbability(
            n=3,
            edges=[[0, 1], [1, 2], [0, 2]],
            succProb=[0.5, 0.5, 0.3],
            start_node=0,
            end_node=2,
        )
    )
    print(
        obj.maxProbability(
            n=3, edges=[[0, 1]], succProb=[0.5], start_node=0, end_node=2
        )
    )
