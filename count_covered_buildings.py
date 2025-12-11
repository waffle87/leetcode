# 3531. Count Covered Buildings

"""
you are given a positive integer 'n', representing an 'n x n' city. you are
also given a 2d grid 'buildings' where 'buildings[i] = [x, y]' denotes a
unique building located at coordinates '[x, y]'. a building is covered if
there is at least one building in all four directions. return the number of
covered buildings.
"""


class Solution(object):
    def countCoveredBuildings(self, n, buildings):
        """
        :type n: int
        :type buildings: List[List[int]]
        :rtype: int
        """
        max_row = [0] * (n + 1)
        max_col = [0] * (n + 1)
        min_row = [n + 1] * (n + 1)
        min_col = [n + 1] * (n + 1)
        for x, y in buildings:
            min_col[x] = min(min_col[x], y)
            max_col[x] = max(max_col[x], y)
            min_row[y] = min(min_row[y], x)
            max_row[y] = max(max_row[y], x)
        ans = 0
        for x, y in buildings:
            if min_col[x] < y < max_col[x] and min_row[y] < x < max_row[y]:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countCoveredBuildings(
            n=3, buildings=[[1, 2], [2, 2], [3, 2], [2, 1], [2, 3]]
        )
    )
    print(obj.countCoveredBuildings(n=3, buildings=[[1, 1], [1, 2], [2, 1], [2, 2]]))
    print(
        obj.countCoveredBuildings(
            n=5, buildings=[[1, 3], [3, 2], [3, 3], [3, 5], [5, 3]]
        )
    )
