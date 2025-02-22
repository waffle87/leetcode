# 733. Flood Fill

"""
you are given an image represented by an 'm x n' grid of integers 'image',
where 'image[i][j]' represents the pixel value of the image. you are also
given three integers 'sr', 'sc', and 'color'. your task is to perform a flood
fill on the image starting from the pixel 'image[sr][sc]'. return the
modified image after performing the flood fill
"""


class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        n, m, old = len(image), len(image[0]), image[sr][sc]

        def dfs(r, c):
            if (not (0 <= r < n and 0 <= c < m)) or image[r][c] != old:
                return
            image[r][c] = color
            [dfs(r + x, c + y) for (x, y) in ((0, 1), (1, 0), (0, -1), (-1, 0))]

        if old != color:
            dfs(sr, sc)
        return image


if __name__ == "__main__":
    obj = Solution()
    print(obj.floodFill(image=[[1, 1, 1], [1, 1, 0], [1, 0, 1]], sr=1, sc=1, color=2))
    print(obj.floodFill(image=[[0, 0, 0], [0, 0, 0]], sr=0, sc=0, color=0))
