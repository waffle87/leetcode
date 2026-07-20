# 1260. Shift 2D Grid

"""
given a 2d 'grid' of size 'm x n' and an integer 'k'. you need to shift the
'grid' 'k' times. in one shift operation, element at 'grid[i][j]' moves to
'grid[i][j + 1]', element at 'grid[i][n - 1]' moves to 'grid[i + 1][0]',
element at 'grid[m - 1][n - 1]' moves to 'grid[0][0]'. return the 2d grid
after applying shift operation 'k' times.
"""


class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        f1 = lambda col, nums: [nums[i : i + col] for i in range(0, len(nums), col)]
        f2 = lambda nums, k: nums[-k % len(nums) :] + nums[: -k % len(nums)]
        return f1(len(grid[0]), f2(sum(grid, []), k))


if __name__ == "__main__":
    obj = Solution()
    print(obj.shiftGrid(grid=[[1, 2, 3], [4, 5, 6], [7, 8, 9]], k=1))
    print(
        obj.shiftGrid(
            grid=[[3, 8, 1, 9], [19, 7, 2, 5], [4, 6, 11, 10], [12, 0, 21, 13]], k=4
        )
    )
    print(obj.shiftGrid(grid=[[1, 2, 3], [4, 5, 6], [7, 8, 9]], k=9))
