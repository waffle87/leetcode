# 739. Daily Temperatures

"""
given an array of integers 'temperatures' represents the daily temperatures
return an array 'answer' such that 'answer[i]' is the number of days you have
to wait after the i'th day to get a warmer temperature. if there is no future
day for which this is possible, keep 'answer[i] == 0' instead.
"""


class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        ans = [0] * len(temperatures)
        stack = []
        for i, t in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < t:
                curr = stack.pop()
                ans[curr] = i - curr
            stack.append(i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.dailyTemperatures(temperatures=[73, 74, 75, 71, 69, 72, 76, 73]))
    print(obj.dailyTemperatures(temperatures=[30, 40, 50, 60]))
    print(obj.dailyTemperatures(temperatures=[30, 60, 90]))
