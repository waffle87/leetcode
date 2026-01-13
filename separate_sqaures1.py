# 3453. Separate Squares I

"""
you are given a 2d integer array 'squares'. each 'squares[i] = [xi, yi, zi]'
represents the coordinates of the bottom-left point and the side length of a
sqaure parallel to the x-axis. find the minimum y-coordinate value of a
horizontal line such that the total area of the squares above the line equals
the total area of the squares below the line. note: sqaures may overlap.
overlapping areas should be counted multiple times.
"""


class Solution(object):
    def separateSquares(self, squares):
        """
        :type squares: List[List[int]]
        :rtype: float
        """
        l, r, ans = 0.0, float("inf"), 0.0
        for _ in range(80):
            mid = l + (r - l) / 2.0
            la, ua = 0.0, 0.0
            for _, i, j in squares:
                ta = j * j
                if i + j <= mid:
                    la += ta
                elif i >= mid:
                    ua += ta
                else:
                    below = (mid - i) * j
                    la += below
                    ua += ta - below
            if la >= ua:
                ans = mid
                r = mid
            else:
                l = mid
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.separateSquares(squares=[[0, 0, 1], [2, 2, 1]]))
    print(obj.separateSquares(squares=[[0, 0, 2], [1, 1, 1]]))
