# 2022. Convert 1D Array Into 2D Array

"""
you are given a 0-indexed 1 dimensional integer array 'original' and two
integers 'm' and 'n'. you are tasked with creating a 2 dimensional array with
'm' rows and 'n' columns using all the elements from 'original'. the elements
from indices 0 to 'n - 1' (inclusively) of 'original' should form the first
row of the constructed 2d array, the elments from indices 'n' to '2 * n - 1'
should form the second row of the constructed 2d array, and so on. return an
'm * n' 2d array constructed according to the above procedure, or an empty 2d
array if it is not possible
"""


class Solution(object):
    def construct2DArray(self, original, m, n):
        """
        :type original: List[int]
        :type m: int
        :type n: int
        :rtype: List[List[int]]
        """
        ans = []
        if len(original) == m * n:
            for i in range(0, len(original), n):
                ans.append(original[i : i + n])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.construct2DArray(original=[1, 2, 3, 4], m=2, n=2))
    print(obj.construct2DArray(original=[1, 2, 3], m=1, n=3))
    print(obj.construct2DArray(original=[1, 2], m=1, n=1))
