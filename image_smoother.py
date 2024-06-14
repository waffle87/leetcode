# 661. Image Smoother
from copy import deepcopy

"""
an image smoother is a filter of the size 3 x 3 that can be applied to each
cell of an image by rounding down the average of the cell and the eight
surrounding cells (ie. the average of the nine cells in the blue smoother).
if one or more of the surrounding cells of a cell is not present, we do not
consider it in the average (ie. the average of the four cells in the red
smoother). given an m x n integer matrix 'img' representing the grayscale of
an image, return the image after applying the smoother on each cell of it
"""


class Solution(object):
    def imageSmoother(self, img):
        """
        :type img: List[List[int]]
        :rtype: List[List[int]]
        """
        x_len = len(img)
        y_len = len(img[0]) if x_len else 0
        ans = deepcopy(img)
        for x in range(x_len):
            for y in range(y_len):
                neighbours = [
                    img[_x][_y]
                    for _x in (x - 1, x, x + 1)
                    for _y in (y - 1, y, y + 1)
                    if 0 <= _x < x_len and 0 <= _y < y_len
                ]
                ans[x][y] = sum(neighbours) // len(neighbours)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.imageSmoother(img=[[1, 1, 1], [1, 0, 1], [1, 1, 1]]))
    print(obj.imageSmoother(img=[[100, 200, 100], [200, 50, 200], [100, 200, 100]]))
