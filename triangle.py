# 120. Triangle

"""
given a 'triangle' array, return the minimum path sum from top to bottom. for
each step, you may move to an adjacent number of the row below. more
formally, if you are index 'i', on the current row, you may move to either
index 'i' or index 'i + 1' on the next row.
"""


class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """

        def dfs(r, c):
            if r == len(triangle):
                return 0
            l = triangle[r][c] + dfs(r + 1, c)
            r = triangle[r][c] + dfs(r + 1, c + 1)
            return min(l, r)

        return dfs(0, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumTotal(triangle=[[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]))
    print(obj.minimumTotal(triangle=[[-10]]))
