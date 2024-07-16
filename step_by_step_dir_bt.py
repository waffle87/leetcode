# 2096. Step-By-Step Directions From a Binary Tree Node to Another

"""
you are given the 'root' of a binary tree with 'n' nodes. each node is
uniquely assigned a value from 1 to 'n'. you are also given an integer
'startValue' representing the value of the stat node 's', nd a different
integer 'destValue' representing the value of the destination node 't', find
the shortest path from node 's' to node 't'. generate step by step directions
of such path as a string consisting only of upper case letters L R and U,
return the step by step directions of the shortest path.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def getDirections(self, root, startValue, destValue):
        """
        :type root: Optional[TreeNode]
        :type startValue: int
        :type destValue: int
        :rtype: str
        """
        q = list[TreeNode] = [root]
        while q:
            curr_node: TreeNode = q.pop()
            if curr_node.val == startValue:
                start_node = curr_node
                break
            if curr_node.left:
                q.append(curr_node.left)
            if curr_node.right:
                q.append(curr_node.right)
        nodes_parents: dict[int, TreeNode] = {}
        q = [root]
        while q:
            curr_node = q.pop()
            if curr_node.left:
                nodes_parents[curr_node.left.val] = curr_node
                q.append(curr_node.left)
            if curr_node.right:
                nodes_parents[curr_node.right.val] = curr_node
                q.append(curr_node.right)
        visited = set()
        q = [start_node]
        tracked_path: dict[TreeNode, tuple(TreeNode, str)] = {}
        while q:
            curr_node = q.pop()
            visited.add(curr_node)
            if curr_node.val == destValue:
                destination_node = curr_node
                break
            if (
                curr_node.val in nodes_parents
                and nodes_parents[curr_node.val] not in visited
            ):
                parent = nodes_parents[curr_node.val]
                q.append(parent)
                tracked_path[parent] = (curr_node, "U")
            if curr_node.left and curr_node.left not in visited:
                q.append(curr_node.left)
                tracked_path[curr_node.left] = (curr_node, "L")
            if curr_node.right and curr_node.right not in visited:
                q.append(curr_node.right)
                tracked_path[curr_node.right] = (curr_node, "R")
        ans = list[str] = []
        curr_node = destination_node
        while curr_node != start_node:
            source_node, direction = tracked_path[curr_node]
            ans.append(direction)
            curr_node = source_node
        ans.reverse()
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.getDirections(root=[5, 1, 2, 3, null, 6, 4], startValue=3, destValue=6))
    print(obj.getDirections(root=[2, 1], startValue=2, destValue=1))
