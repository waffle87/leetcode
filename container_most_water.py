# 11. Container With Most Water

"""
you are given an integer array 'height' of length 'n'. there are 'n' vertical
lines drawn such that two endpoints of the i'th line are '(i, 0)' and '(i,
height[i])'. find two lines that together with the x-axis form a container
such that the container contains the most water. return the maximum amount of
water a container can store. notice that you may not slant the container.
"""


class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right, ans = 0, len(height) - 1, 0
        while left < right:
            curr = min(height[left], height[right]) * (right - left)
            ans = max(ans, curr)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxArea(height=[1, 8, 6, 2, 5, 4, 8, 3, 7]))
    print(obj.maxArea(height=[1, 1]))
