# 2924. Find Champion II

"""
there are 'n' teams numbered from 0 to 'n - 1' in a tournament; each team is
also a node in DAG. you are given the integer 'n' and a 0-indexed 2d integer
array 'edges' of length 'm' representing the DAG, where 'edges[i] = [u_i,
v_i]' indicates that is a directed edge from team 'u_i' to team 'v_i' in the
graph. a directed edge from 'a' to 'b' in the graph means that team 'a' is
strong than team 'b' and team 'b' is weaker than team 'a'. return the team
that will be the champion of the tournament if there is a unique champion,
otherwise return -1.
"""


class Solution(object):
    def findChampion(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        weak = {b for a, b in edges}
        return -1 if len(weak) < n - 1 else n * (n - 1) // 2 - sum(weak)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findChampion(n=3, edges=[[0, 1], [1, 2]]))
    print(obj.findChampion(n=4, edges=[[0, 2], [1, 3], [1, 2]]))
