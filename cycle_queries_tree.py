# 2509. Cycle Length Queries in a Tree

"""
you are given an integer 'n'. there is a complete binary tree with '2^n - 1'
nodes. the root of that tree is the node with the value 1, and every node
with a value 'val' in the range '[1, 2^(n - 1) - 1]' has two children. you
are also given a 2d integer array 'queries' of length 'm' where 'queries[i] =
[a_i, b_i]'. for each query, add an edge between the nodes with values 'a_i'
and 'b_i', find the length of the cycle in the graph, and remove the added
edge between nodes with values 'a_i' and 'b_i'.
"""


class Solution(object):
    def cycleLengthQueries(self, n, queries):
        """
        :type n: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        ans = []
        for a, b in queries:
            ans.append(1)
            while a != b:
                a, b = min(a, b), max(a, b) // 2
                ans[-1] += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.cycleLengthQueries(n=3, queries=[[5, 3], [4, 7], [2, 3]]))
    print(obj.cycleLengthQueries(n=2, queries=[[1, 2]]))
