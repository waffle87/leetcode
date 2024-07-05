# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

"""
a critical point in a linked list is defined as either a local maxima or a
local minima. anode is a local maxima if the current node has a value
strictly greater than the previous node and the next node. a node is a minima
if the current node has a value strictly smaller than the previous node and
the next node. note that a node can only be a local maxima/minima if there
exists both a previous node and a next node. given a linked list 'head',
return an array of length 2 container '[min_distance, max_distance]' where
'min_distance' is the minimum distance between any two distinct nodes and
oppositely true for 'max_distance'. if there are fewer than two critical
points, return '[-1, -1]'
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        crit, crit_pt, prev = 0, [], head.val
        while head.next:
            if (prev - head.val) * (head.val - head.next.val) < 0:
                crit_pt.append(crit)
            prev, head = head.val, head.next
            crit += 1
        n = len(crit_pt)
        if n < 2:
            return [-1, -1]
        mn = min((crit_pt[i] - crit_pt[i - 1] for i in range(1, n)))
        mx = crit_pt[-1] - crit_pt[0]
        return [mn, mx]
