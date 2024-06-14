# 42. Trapping Rain Water

"""
given 'n' non-negative integers representing an elevation map where the width
of each bar is 1, compute how much water it can trap after raining.
"""


class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        left, right = [0] * n, [0] * n
        for i in range(1, n):
            left[i] = max(height[i - 1], left[i - 1])
        for i in range(n - 2, -1, -1):
            right[i] = max(height[i + 1], right[i + 1])
        ans = 0
        for i in range(n):
            level = min(left[i], right[i])
            if level >= height[i]:
                ans += level - height[i]
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.trap(height=[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
    print(obj.trap(height=[4, 2, 0, 3, 2, 5]))
