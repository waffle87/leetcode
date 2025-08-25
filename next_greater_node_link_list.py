# 1019. Next Greater Node In Linked List
from leetcode import listnode_build

"""
you are given the 'head' of a linked list with 'n' nodes. for each node in
the list, find the value of the next greater node. that is, for eachnode,
find the value of the first node that is next to it and has a stricty larger
value than it. return an integer array 'answer' where 'answer[i]' is the
value of the next greter node of the i'th node (1-indexed). if the i'th node
does not have a next greater node, set 'ans[i] = 0'.
"""


class Solution(object):
    def nextLargerNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        ans, stack = [], []
        while head:
            while stack and stack[-1][1] < head.val:
                ans[stack.pop()[0]] = head.val
            stack.append([len(ans), head.val])
            ans.append(0)
            head = head.next
        return ans


if __name__ == "__main__":
    obj = Solution()
    h1 = listnode_build(vals=[2, 1, 5])
    h2 = listnode_build(vals=[2, 7, 4, 3, 5])
    print(obj.nextLargerNodes(h1))
    print(obj.nextLargerNodes(h2))
