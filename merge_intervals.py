# 56. Merge Intervals

"""
given an array of 'intervals' where 'intervals[i] = [start_i, end_i]', merge
all overlapping intervals, and return an array of the non-overlapping
intervals that cover all the intervals in the input.
"""


class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        stack = []
        for i in sorted(intervals, key=lambda i: i[0]):
            if stack and i[0] <= stack[-1][1]:
                stack[-1][1] = max(stack[-1][1], i[1])
            else:
                stack += [i]
        return stack


if __name__ == "__main__":
    obj = Solution()
    print(obj.merge(intervals=[[1, 3], [2, 6], [8, 10], [15, 18]]))
    print(obj.merge(intervals=[[1, 4], [4, 5]]))
