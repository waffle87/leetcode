# 1738. Find Kth Largest XOR Coordinate Value
import heapq

"""
you are given a 2d 'matrix' of size 'm x n' consisting of non-negative
integers. you are also given an integer 'k'. the value of coordinate '(a, b)'
of  the matrix is the xor of all 'matrix[i][j]' where '0 <= i <= a < m' and
'0 <= j <= b < n' (0-indexed). find the k'th largest value (1-indexed) of all
the coordinates of 'matrix'.
"""


class Solution(object):
    def kthLargestValue(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        m, n = len(matrix), len(matrix[0])
        pq = []
        for i in range(m):
            for j in range(n):
                if i > 0:
                    matrix[i][j] ^= matrix[i - 1][j]
                if j > 0:
                    matrix[i][j] ^= matrix[i][j - 1]
                if i > 0 and j > 0:
                    matrix[i][j] ^= matrix[i - 1][j - 1]
                if len(pq) < k:
                    heapq.heappush(pq, matrix[i][j])
                else:
                    heapq.heappushpop(pq, matrix[i][j])
        return pq[0]


if __name__ == "__main__":
    obj = Solution()
    print(obj.kthLargestValue(matrix=[[5, 2], [1, 6]], k=1))
    print(obj.kthLargestValue(matrix=[[5, 2], [1, 6]], k=2))
    print(obj.kthLargestValue(matrix=[[5, 2], [1, 6]], k=3))
