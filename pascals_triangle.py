# 118. Pascal's Triangle

"""
given an integer 'num_rows', return the first numrows of pascal's triangle.
in pascal's triangle, each number is the sum of the two number direction
above it as show [gif]
"""


class Solution(object):
    def generate(self, num_rows):
        ans = [[1 for _ in range(row + 1)] for row in range(num_rows)]
        for row in range(num_rows):
            for col in range(1, row):
                ans[row][col] = ans[row - 1][col] + ans[row - 1][col - 1]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.generate(5))  # expect: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    print(obj.generate(1))  # expect: [[1]]
