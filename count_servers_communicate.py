# 1267. Count Servers that Communicate

"""
you are given a map of a server centre, represented as a 'm x n' integer
matrix 'grid', where 1 means that on that cell there is a server and 0 means
that it is no server. two servers are said to communicate if they are on the
same row or the same column. return the number of servers that communicate
with any other server.
"""


class Solution(object):
    def countServers(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows, cols = map(sum, grid), map(sum, zip(*grid))
        return sum(
            rows[i] + cols[j] > 2
            for i in range(len(grid))
            for j in range(len(grid[0]))
            if grid[i][j]
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.countServers(grid=[[1, 0], [0, 1]]))
    print(obj.countServers(grid=[[1, 0], [1, 1]]))
    print(
        obj.countServers(grid=[[1, 1, 0, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 1]])
    )
