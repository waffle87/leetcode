# 1104. Path In Zigzag Labelled Binary Tree

"""
in an infinite binary ree where every node has two children, the nodes are
labelled in row order. in the odd numbered rows, the labelling is left to
right, while in the even numbered rows, the labelling is right to left. given
the 'label' of a node in this tree, return the labels in the path from the
root of the tree to the node with that 'label'
"""


class Solution(object):
    def pathInZigZagTree(self, label):
        """
        :type label: int
        :rtype: List[int]
        """
        ans = []
        node_cnt, level = 1, 1
        while label >= node_cnt * 2:
            node_cnt *= 2
            level += 1
        while label != 0:
            ans.append(label)
            level_max = 2 ** (level) - 1
            level_min = 2 ** (level - 1)
            label = int((level_max + level_min - label) / 2)
            level -= 1
        return ans[::-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.pathInZigZagTree(14))
    print(obj.pathInZigZagTree(26))
