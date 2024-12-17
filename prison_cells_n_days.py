# 957. Prison Cells After N Days

"""
there are 8 prison cells in a row and each cell is either occupied or vacant.
each day, whether the cell is occupied or vacant changes according to the
following rules: if a cell has two adjacent neighbours that are both occupied
or both vacant, then the cell becomes occupied, otherwise it becomes vacant.
note that because the prison is a row, the first and the last cells in the
row can't have two adjacent neighbours. you are given an integer array
'cells' where 'cells[i] == 1' if the i'th cell is occupied and 'cells[i] ==
0' if the i'th cell is vacant, and you are given an integer 'n'. return the
state of the prison after 'n' days (ie. 'n' such changes desribed above)
"""


class Solution(object):
    def prisonAfterNDays(self, cells, n):
        """
        :type cells: List[int]
        :type n: int
        :rtype: List[int]
        """
        vis = {str(cells): n}
        while n:
            vis.setdefault(str(cells), n)
            n -= 1
            cells = [0] + [cells[i - 1] ^ cells[i + 1] ^ 1 for i in range(1, 7)] + [0]
            if str(cells) in vis:
                n %= vis[str(cells)] - n
        return cells


if __name__ == "__main__":
    obj = Solution()
    print(obj.prisonAfterNDays(cells=[0, 1, 0, 1, 1, 0, 0, 1], n=7))
    print(obj.prisonAfterNDays(cells=[1, 0, 0, 1, 0, 0, 1, 0], n=1000000000))
