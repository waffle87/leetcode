# 1886. Determine Whether Matrix Can Be Obtained By Rotation
from typing import List

"""
given two 'n x n' binary matrices 'mat' and 'target', return 'true' if it is
possible to make 'mat' equal to 'target' by rotating 'mat' in 90-degree
increments, or 'false' otherwise.
"""


class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        for _ in range(4):
            if mat == target:
                return True
            mat = [list(x) for x in zip(*mat[::-1])]
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.findRotation(mat=[[0, 1], [1, 0]], target=[[1, 0], [0, 1]]))
    print(obj.findRotation(mat=[[0, 1], [1, 1]], target=[[1, 0], [0, 1]]))
    print(
        obj.findRotation(
            mat=[[0, 0, 0], [0, 1, 0], [1, 1, 1]],
            target=[[1, 1, 1], [0, 1, 0], [0, 0, 0]],
        )
    )
