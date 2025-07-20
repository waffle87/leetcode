# 1948. Delete Duplicate Folders in System
from collections import defaultdict

"""
due to a bug, there are many duplicate folders in a file system. you are
given a 2d array 'paths', where 'paths[i]' is an array representing an
absolute path to the i'th folder in the file system. two folders are
identical if they contain the same non-empty set of identical subfolders and
underlying subfolder structure. the folders do not need to be at the root
level to be identical. if two or more folders are identical, then make the
folders as well as their subfolders. return the 2d array 'ans' containing the
paths of the remaining folders after deleting all the marked folders. the
paths may be returned in any order.
"""


class Node:
    def __init__(self):
        self.child = defaultdict(Node)
        self.dl = False


class Solution(object):
    def deleteDuplicateFolder(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: List[List[str]]
        """

        pattern, root, ans = defaultdict(list), Node(), []

        def dfs1(node):
            key = "(" + "".join(i + dfs1(node.child[i]) for i in node.child) + ")"
            if key != "()":
                pattern[key].append(node)
            return key

        def dfs2(node, path):
            for i in node.child:
                if not node.child[i].dl:
                    dfs2(node.child[i], path + [i])
            if path:
                ans.append(path[:])

        for i in sorted(paths):
            node = root
            for j in i:
                node = node.child[j]
        dfs1(root)
        for i in pattern.values():
            if len(i) > 1:
                for j in i:
                    j.dl = True

        dfs2(root, [])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.deleteDuplicateFolder(
            paths=[["a"], ["c"], ["d"], ["a", "b"], ["c", "b"], ["d", "a"]]
        )
    )
    print(
        obj.deleteDuplicateFolder(
            paths=[
                ["a"],
                ["c"],
                ["a", "b"],
                ["c", "b"],
                ["a", "b", "x"],
                ["a", "b", "x", "y"],
                ["w"],
                ["w", "y"],
            ]
        )
    )
    print(obj.deleteDuplicateFolder(paths=[["a", "b"], ["c", "d"], ["c"], ["a"]]))
