# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
from leetcode import ListNode, listnode_build

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


class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        if not head or not head.next or not head.next.next:
            return [-1, -1]
        crit, pos = [], -1
        prev, curr = head, head.next
        while curr.next:
            if (curr.val > prev.val and curr.val > curr.next.val) or (
                curr.val < prev.val and curr.val < curr.next.val
            ):
                crit.append(pos)
            prev = curr
            curr = curr.next
            pos += 1
        if len(crit) < 2:
            return [-1, -1]
        min_dist = float("inf")
        max_dist = crit[-1] - crit[0]
        for i in range(1, len(crit)):
            min_dist_betw_3eq_elem = min(min_dist, crit[i] - crit[i - 1])
        return [min_dist, max_dist]


if __name__ == "__main__":
    obj = Solution()
    h1 = listnode_build(vals=[3, 1])
    h2 = listnode_build(vals=[5, 3, 1, 2, 5, 1, 2])
    h3 = listnode_build(vals=[1, 3, 2, 2, 3, 2, 2, 2, 7])
    print(obj.nodesBetweenCriticalPoints(h1))
    print(obj.nodesBetweenCriticalPoints(h2))
    print(obj.nodesBetweenCriticalPoints(h3))
