# 2033. Minimum Operations to Make a Uni-Value Grid

"""
you are given a 2d integer 'grid' of size 'm x n' and an integer 'x'. in one
operation, you can add 'x' to or subtract 'x' from any element in the 'grid'.
a uni-value grid is a grid where all the elements of it are equal. return the
minimum number of operations to make the grid uni-valued. if it is not
possible, return -1.
"""


class Solution(object):
    def minOperations(self, grid, x):
        """
        :type grid: List[List[int]]
        :type x: int
        :rtype: int
        """
        vals = sorted([i for j in grid for i in j])
        diff = [abs(i - vals[0]) % x for i in vals]
        if any(i != 0 for i in diff):
            return -1
        med = vals[len(vals) // 2]
        ans = sum(abs(i - med) // x for i in vals)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(grid=[[2, 4], [6, 8]], x=2))
    print(obj.minOperations(grid=[[1, 5], [2, 3]], x=1))
    print(obj.minOperations(grid=[[1, 2], [3, 4]], x=2))
