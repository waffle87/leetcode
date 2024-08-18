# 1964. Find the Longest Valid Obstacle Course at Each Position

"""
you want to build obstacle courses. you are given a 0-indexed integer array
'obstacles' of length 'n' where 'obstacles[i]' describes the height of the
i'th obstacle. for every index 'i' between 0 and 'n - 1' (inclusive), find
the length of the longest obstacle course in 'obstacles' such that:
- you choose any number of obstacles between 0 and 'i' inclusive
- you must include the i'th obstacle in the course
- you must put the chosen obstacles in the same order as they appear in
'obstacles'
- every obstacle (except the first) is taller than or the same height as the
obstacle immediately before it return an array 'ans' of length 'n', where
'ans[i]' is the length of the longest obstacle course for index 'i' as
described above
"""


class Solution(object):
    def longestObstacleCourseAtEachPosition(self, obstacles):
        """
        :type obstacles: List[int]
        :rtype: List[int]
        """
        ans, stk = [], []
        for i in obstacles:
            mid = bisect_right(stk, i)
            if mid == len(stk):
                stk.append(i)
            else:
                stk[mid] = i
            ans.append(mid + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestObstacleCourseAtEachPosition(obstacles=[1, 2, 3, 2]))
    print(obj.longestObstacleCourseAtEachPosition(obstacles=[2, 2, 1]))
    print(obj.longestObstacleCourseAtEachPosition(obstacles=[3, 1, 5, 6, 4, 2]))
