# 297. Serialize and Deserialize Binary Tree

"""
serialisation is the process of converting a data structure or object into a
sequence of bits so that it can be stored in a file or memory buffer, or
transmitted acorss a network connection link to be reconstructed later in the
same or another computer environment. design an algorithm to serialise and
deserialise a binary tree. there is no restriction on how your serialisation
and deserialisation algorithm shouldd work. you just need to ensure that a
binary tree can be serialised to a string and this string can be deserialised
to the original tree structure.
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        vals = []

        def ser(node):
            if node:
                vals.append(str(node.val))
                ser(node.left)
                ser(node.right)

        ser(root)
        return "".join(vals)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        vals = iter(data.split())

        def deser():
            val = next(vals)
            if val == "#":
                return None
            node = TreeNode(int(val))
            node.left = deser()
            node.right = deser()
            return node

        return deser()


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))

if __name__ == "__main__":
    ser = Codec()
    deser = Codec()
    root = [1, 2, 3, None, None, 4, 5]
    print(deser.deserialize(ser.serialize(root)))
