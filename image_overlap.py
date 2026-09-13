# 835. Image Overlap

"""
you are given two images 'img1' and 'img2', represented as binary square
matrices of size 'n x n'. a binary matrix has only 0s and 1s as values. we
translate one image however we choose by sliding all the 1 bits left, right,
up and down any number of units. we then place it on top of the other image
.we can then calcluate the overlap by counting the number of positions that
have a 1 in both images. return the largest possible overlap.
"""

from collections import defaultdict


class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        d = defaultdict(int)
        a, b = [], []
        for i in range(len(img1)):
            for j in range(len(img1[0])):
                if img1[i][j] == 1:
                    a.append((i, j))
                if img2[i][j] == 1:
                    b.append((i, j))
        for r1, c1 in img1:
            for r2, c2 in img2:
                d[(r2 - r1, c2 - c1)] += 1
        return max(d.values() or [0])


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.largestOverlap(
            img1=[[1, 1, 0], [0, 1, 0], [0, 1, 0]],
            img2=[[0, 0, 0], [0, 1, 1], [0, 0, 1]],
        )
    )
    print(obj.largestOverlap(img1=[[1]], img2=[[1]]))
    print(obj.largestOverlap(img1=[[0]], img2=[[0]]))
