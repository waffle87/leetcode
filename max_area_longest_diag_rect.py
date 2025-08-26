# 3000. Maximum Area of Longest Diagonal Rectangle

"""
you are given a 2d 0-indexed integer array 'dimensions'. for all indices 'i',
'0 <= i < dimensions.size', 'dimensions[i][0]' represents the length and
'dimensions[i][1]' represents the width of the rectangle 'i'. return the area
of the rectangle having the longest diagonal, return the area of the
rectangle having the maximum area.
"""


class Solution(object):
    def areaOfMaxDiagonal(self, dimensions):
        """
        :type dimensions: List[List[int]]
        :rtype: int
        """
        ans, area = 0, 0
        for l, w in dimensions:
            curr = l * l + w * w
            if curr > area or (curr == area and l * w > ans):
                area = curr
                ans = l * w
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.areaOfMaxDiagonal(dimensions=[[9, 3], [8, 6]]))
    print(obj.areaOfMaxDiagonal(dimensions=[[3, 4], [4, 3]]))
