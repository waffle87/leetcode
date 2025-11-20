# 832. Flipping an Image

"""
given an 'n x n' binary matrix 'image', flip the image horizontally, then
invert it and return the resulting image. to flip an image horizontally means
that each row of the image is reversed. to invert an image means that each 0
is replaced by 1, and each 1 is replaced by 0.
"""


class Solution(object):
    def flipAndInvertImage(self, image):
        """
        :type image: List[List[int]]
        :rtype: List[List[int]]
        """
        return [[1 ^ i for i in j[::-1]] for j in image]


if __name__ == "__main__":
    obj = Solution()
    print(obj.flipAndInvertImage(image=[[1, 1, 0], [1, 0, 1], [0, 0, 0]]))
    print(
        obj.flipAndInvertImage(
            image=[[1, 1, 0, 0], [1, 0, 0, 1], [0, 1, 1, 1], [1, 0, 1, 0]]
        )
    )
