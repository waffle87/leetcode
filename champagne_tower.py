# 799. Champagne Tower

"""
we stack glasses in a pyramid, where the first row has 1 glass, the second
row has 2 glasses, and so on until the 100th row. each glass holds one cup of
champagne. then, some champagne is poured into the first glass at the top.
when the topmost glass is full, any excess liquid poured will fall equally to
the glass immediately to the right and left of it. when those glasses become
full, any excess champange will fall equally to the left and right of those
glasses, and so on. (a glass at the bottom row has its excess champagne fall
on the floor). for example, after one cup of champagne is poured, the top
most glass is full. after cups of champagne is poured, the two glasses on the
second row are half full. after three cups are poured, those two cups become
full - there are three glasses total full now. now after pouring some
non-negative integer cups of champagne, return how full the j'th glass in the
i'th row is.
"""


class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        tower = [[0] * (i + 1) for i in range(query_row + 1)]
        tower[0][0] = poured
        for row in range(query_row):
            for glass in range(len(tower[row])):
                execess = (tower[row][glass] - 1) / 2.0
                if execess > 0:
                    tower[row + 1][glass] += execess
                    tower[row + 1][glass + 1] += execess
        return min(1.0, tower[query_row][query_glass])


if __name__ == "__main__":
    obj = Solution()
    print(obj.champagneTower(1, 1, 1))  # expect: 0.00000
    print(obj.champagneTower(2, 1, 1))  # expect: 0.50000
    print(obj.champagneTower(100000009, 33, 17))  # expect: 1.00000
