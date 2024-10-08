# 84. Largest Rectangle in Histogram

"""
given an array of integers 'heights' representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle
"""


class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights.append(0)
        stack, ans = [-1], 0
        for i in range(len(heights)):
            while heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i - stack[-1] - 1
                ans = max(ans, h * w)
            stack.append(i)
        heights.pop()
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.largestRectangleArea(heights=[2, 1, 5, 6, 2, 3]))
    print(obj.largestRectangleArea(heights=[2, 4]))
