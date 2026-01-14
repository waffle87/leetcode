# 3454. Separate Squares II

"""
you are given a 2d integer array 'squares'. each 'squares[i] = [xi, yi, zi]'
represents the coordinates of the bottom left point and the side length of a
square parallel to the x-axis. find the minimum y-coordinate value of a
horizontal line such that the total area covered by squares above the line
equal the total area covered by squares below the line. answers within 10^-5
of the actual answer will be accepted. note: squares may overlap. overlapping
areas should be counted only once in this version.
"""


class Solution(object):
    def separateSquares(self, squares):
        """
        :type squares: List[List[int]]
        :rtype: float
        """
        events = []
        for x, y, l in squares:
            events.append((y, 1, x, x + l))
            events.append((y + l, -1, x, x + l))
        events.sort()
        active_intervals = []
        prev_y = events[0][0]
        total_area = 0
        horizontal_slices = []

        def union_width(intervals):
            intervals.sort()
            total_width = 0
            rightmost = float("-inf")
            for left, right in intervals:
                if left > rightmost:
                    total_width += right - left
                    rightmost = right
                elif right > rightmost:
                    total_width += right - rightmost
                    rightmost = right
            return total_width

        for y, event_type, x_left, x_right in events:
            if y > prev_y and active_intervals:
                height = y - prev_y
                width = union_width(active_intervals)
                horizontal_slices.append((prev_y, height, width))
                total_area += height * width
            if event_type == 1:
                active_intervals.append((x_left, x_right))
            else:
                active_intervals.remove((x_left, x_right))
            prev_y = y
        half_area = total_area / 2
        accumulated = 0
        for start_y, height, width in horizontal_slices:
            slice_area = height * width
            if accumulated + slice_area >= half_area:
                return start_y + (half_area - accumulated) / width
            accumulated += slice_area
        return float(prev_y)


if __name__ == "__main__":
    obj = Solution()
    print(obj.separateSquares(squares=[[0, 0, 1], [2, 2, 1]]))
    print(obj.separateSquares(squares=[[0, 0, 2], [1, 1, 1]]))
