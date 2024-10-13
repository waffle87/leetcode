# 1659. Maximize Grid Happiness

"""
you are given four integers 'm', 'n', 'introvertsCount', and
'extrovertsCount'. you have an 'm * n' grid and there are two types of
people: introverts and extroverts. there are 'introvertsCount' introverts and
'extrovertsCount' extroverts. you should decide how many people ou want to
live in the grid and assign each of them one grid cell. note that you do not
have to have all the people living in the grid. neighbours live directly
adjacent cells, north, east, south, and west of a person's cell. the grid
happiness is the sum of each person's happiness. return the maximum possible
grid happiness
"""


class Solution(object):
    def getMaxGridHappiness(self, m, n, introvertsCount, extrovertsCount):
        """
        :type m: int
        :type n: int
        :type introvertsCount: int
        :type extrovertsCount: int
        :rtype: int
        """
        ing, exg, inl, exl = 120, 40, -30, 20
        valid = [[0, 0, 0], [0, 2 * inl, inl + exl], [0, inl + exl, 2 * exl]]

        def dp(idx, row, i, e):
            if idx == -1:
                return 0
            r, c, res = idx // n, idx % n, []
            n = [(1, i - 1, e, ing), (2, i, e - 1, exg), (0, i, e, 0)]
            for val, dx, dy, gain in n:
                tmp = 0
                if dx >= 0 and dy >= 0:
                    tmp = dp(idx - 1, (val,) + row[:-1], dx, dy) + gain
                    if c < n - 1:
                        tmp += valid[val][row[0]]
                    if r < m - 1:
                        tmp += valid[val][row[-1]]
                res.append(tmp)
            return max(res)

        if m < n:
            n = n, m
        return dp(m * n - 1, tuple([0] * n), introvertsCount, extrovertsCount)


if __name__ == "__main__":
    obj = Solution()
    print(obj.getMaxGridHappiness(m=2, n=3, introvertsCount=1, extrovertsCount=2))
    print(obj.getMaxGridHappiness(m=3, n=1, introvertsCount=2, extrovertsCount=1))
