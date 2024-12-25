class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def list_to_tree(input):
    if not input:
        return None
    root = TreeNode(input[0])
    q, i = [root], 1
    while i < len(input):
        curr = q.pop(0)
        if input[i] is not None:
            curr.left = TreeNode(input[i])
            q.append(curr.left)
        i += 1
        if i < len(input) and input[i] is not None:
            curr.right = TreeNode(input[i])
            q.append(curr.right)
        i += 1
    return root
