# 118. Pascal's Triangle

"""
given an integer 'numRows', return the first numrows of pascal's triangle.
in pascal's triangle, each number is the sum of the two number direction
above it as show [gif]
"""


class Solution(object):
    def generate(self, numRows):
        ans = [[1]]
        for i in range(1, numRows):
            ans += [map(lambda x, y: x + y, ans[-1] + [0], [0] + ans[-1])]
        return ans[:numRows]


if __name__ == "__main__":
    obj = Solution()
    print(obj.generate(5))  # expect: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    print(obj.generate(1))  # expect: [[1]]
