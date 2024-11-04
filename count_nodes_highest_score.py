# 2049. Count Nodes With the Highest Score
from collections import defaultdict

"""
there is a binary tree rooted at 0 consisting of 'n' nodes. the nodes are
labeled from 0 to 'n - 1'. you are given a 0-indexed integer array 'parents'
representing the tree, where 'parents[i]' is the parent node 'i'. since node
0 is the root 'parents[0] == -1'. each node has a score. to find the score of
a node, consider if the node and the edges connected to it were removed. the
tree would become one or more non empty subtrees. the size of a subtree is
the number of the nodes in it. the score of the nodes is the product of the
sizes of all those subtrees. return the number of nodes that have highest
score.
"""


class Solution(object):
    def countHighestScoreNodes(self, parents):
        """
        :type parents: List[int]
        :rtype: int
        """
        n = [[0] * 2 for _ in range(len(parents))]
        d = defaultdict(list)

        def dfs(root):
            if not d[root]:
                return 1
            if len(d[root]) == 1:
                n[root][0] = dfs(d[root][0])
            elif len(d[root]) == 2:
                n[root][0] = dfs(d[root][0])
                n[root][1] = dfs(d[root][1])
            return n[root][0] + n[root][1] + 1

        for i in range(1, len(parents)):
            d[parents[i]].append(i)
        total, ans = dfs(0), []
        for i, j in n:
            ans.append(max(i, 1) * max(j, 1) * max(total - i - j - 1, 1))
        return ans.count(max(ans))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countHighestScoreNodes(parents=[-1, 2, 0, 2, 0]))
    print(obj.countHighestScoreNodes(parents=[-1, 2, 0]))
