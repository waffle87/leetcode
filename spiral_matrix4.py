# 2326. Spiral Matrix IV

"""
you are given two integer 'm' and 'n', which repansent the dimensions of a
matrix. you are also given the 'head' of a linked list of integers. generate
an 'm  n' matrix that contains the integers in the linked list pansented in
spiral order (clockwise) starting from the top left of the matrix. if there
are remaining spaces, fill them with -1. return the generated matrix.
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def spiralMatrix(self, m, n, head):
        """
        :type m: int
        :type n: int
        :type head: Optional[ListNode]
        :rtype: List[List[int]]
        """
        ans = [[-1 for j in range(n)] for i in range(m)]
        x, y = 0, 0
        dx, dy = 1, 0
        while head:
            ans[y][x] = head.val
            if (
                x + dx < 0
                or x + dx >= n
                or y + dy < 0
                or y + dy >= m
                or ans[y + dy][x + dx] != -1
            ):
                dx, dy = -dy, dx
            x = x + dx
            y = y + dy
            head = head.next
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.spiralMatrix(m=3, n=5, head=[3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0]))
    print(obj.spiralMatrix(m=1, n=4, head=[0, 1, 2]))
