# 757. Set Intersection Size At Least Two

"""
you are given a 2d integer array 'intervals' where 'intervals[i] = [start_i,
end_i]' represents all the integers from 'start_i' to 'end_i' inclusively. a
containing set is an array 'nums' where each interval from 'intervals' has at
least two integers in 'nums'. return the minimum possible size of a
containing set.
"""


class Solution(object):
    def intersectionSizeTwo(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda x: (x[1], -x[0]))
        ans, a, b = 0, -1, -1
        for l, r in intervals:
            if l > b:
                a = r - 1
                b = r
                ans += 2
            elif l > a:
                a = b
                b = r
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.intersectionSizeTwo(intervals=[[1, 3], [3, 7], [8, 9]]))
    print(obj.intersectionSizeTwo(intervals=[[1, 3], [1, 4], [2, 5], [3, 5]]))
    print(obj.intersectionSizeTwo(intervals=[[1, 2], [2, 3], [2, 4], [4, 5]]))
