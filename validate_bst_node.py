# 1361. Validate Binary Tree Nodes
from collections import defaultdict

"""
you have n binary trees nodes numbered from 0 to n - 1 where node i has two
children left_child and right_child. return true if any only if all the given
nodes from exactly one valid binary tree. if node i has no left children,
then left_child[i] will equal -1. note that the nodes have no values and that
we only use the node numbers in this problem.
"""


class Solution:
    def validateBinaryTreeNodes(self, n, left_child, right_child):
        graph = defaultdict(list)
        in_degree = [0] * n

        for node in range(n):
            left, right = left_child[node], right_child[node]
            if left != -1:
                graph[node].append(left)
                in_degree[left] += 1
            if right != -1:
                graph[node].append(right)
                in_degree[right] += 1

        root_candidates = [node for node in range(n) if in_degree[node] == 0]

        if len(root_candidates) != 1:
            return False
        root = root_candidates[0]

        queue = [root]
        seen = set([root])

        while queue:
            node = queue.pop(0)
            if node in graph:
                for child in graph[node]:
                    if child in seen:
                        return False
                    seen.add(child)
                    queue.append(child)

        return len(seen) == n


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.validateBinaryTreeNodes(
            n=4, left_child=[1, -1, 3, -1], right_child=[2, -1, -1, -1]
        )
    )  # expect: True
    print(
        obj.validateBinaryTreeNodes(
            n=4, left_child=[1, -1, 3, -1], right_child=[2, 3, -1, -1]
        )
    )  # expect: False
    print(
        obj.validateBinaryTreeNodes(n=2, left_child=[1, 0], right_child=[-1, -1])
    )  # expect: True
