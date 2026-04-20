# 2078. Two Furthest Houses With Different Colors

"""
there are 'n' houses evenly lined up on the street, and each house is
beautifully painted. you are given a 0-indexed integer array 'colors' of
length 'n' where 'colors[i]' represents the color of the i'th house. return
the maximum distance between two houses with different colors. the distance
between the i'th and the j'th house is 'abs(i - j)'.
"""


class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        ans = 0
        for x, y in enumerate(colors):
            if y != colors[0]:
                ans = max(ans, x)
            if y != colors[-1]:
                ans = max(ans, len(colors) - 1 - x)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDistance(colors=[1, 1, 1, 6, 1, 1, 1]))
    print(obj.maxDistance(colors=[1, 8, 3, 8, 3]))
    print(obj.maxDistance(colors=[0, 1]))
