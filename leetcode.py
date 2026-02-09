from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def treenode_build(vals):
    if not vals:
        return None
    root = TreeNode(vals[0])
    q, i = deque([root]), 1
    while q and i < len(vals):
        curr = q.popleft()
        if vals[i] is not None:
            curr.left = TreeNode(vals[i])
            q.append(curr.left)
        i += 1
        if i < len(vals) and vals[i] is not None:
            curr.right = TreeNode(vals[i])
            q.append(curr.right)
        i += 1
    return root


def treenode_print(root):
    if not root:
        return
    q, res = deque([root]), []
    while q:
        curr = q.popleft()
        if curr:
            res.append(str(curr.val))
            q.append(curr.left)
            q.append(curr.right)
        else:
            res.append("null")
    while res and res[-1] == "null":
        res.pop()
    print(res)


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def listnode_build(vals):
    if not vals or vals[0] is None:
        return None
    head = ListNode(vals[0])
    curr = head
    for i in vals[1:]:
        curr.next = ListNode(i)
        curr = curr.next
    return head


def listnode_print(head):
    if not head:
        return
    res, curr = [], head
    while curr:
        res.append(str(curr.val))
        curr = curr.next
    print(res)
