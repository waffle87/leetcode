# 2385. Amount of Time for Binary Tree to Be Infected

"""
given the 'root' of a binary tree with unique values, and an integer 'start'.
at minute 0, an infection starts from the node with value 'start' each
minute, a node becomes infected if the node is currently uninfected, or the
node is adjacent to an infected node. return the number of minutes needed for
the entire tree to be infected.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def amountOfTime(self, root, start):
        """
        :type root: Optional[TreeNode]
        :type start: int
        :rtype: int
        """

        def dfs(node):
            if node is None:
                return
            if node.left:
                graph[node.val].append(node.left.val)
                graph[node.left.val].append(node.val)
            if node.right:
                graph[node.val].append(node.right.val)
                graph[node.right.val].append(node.val)
            dfs(node.left)
            dfs(node.right)

        graph = defaultdict(list)
        dfs(root)
        visited = set()
        queue = deque([start])
        time = -1
        while queue:
            time += 1
            for _ in range(len(queue)):
                current_node = queue.popleft()
                visited.add(current_node)
                for neighbor in graph[current_node]:
                    if neighbor not in visited:
                        queue.append(neighbor)
        return time


if __name__ == "__main__":
    obj = Solution()
    print(obj.amountOfTime(root=[1, 5, 3, null, 4, 10, 6, 9, 2], start=3))
    print(obj.amountOfTime(root=[1], start=1))
