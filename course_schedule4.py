# 1462. Course Schedule IV

"""
there are a total of 'numCourses' courses that you have to take, labeled from
0 to 'numCourses - 1'. you are given an array 'prerequisites' where
'prerequisites[i] = [a_i, b_i]' indicates that you must take course 'a_i'
before 'b_i'. prerequisites can also be indirect. if course 'a' is a
prerequisite of course 'b', and course 'b' is a prerequisite of course 'c',
then course 'a' is a prerequisite of course 'c'. you are also given an array
'queries' where 'queries[j] = [u_j, v_j]'. for the j'th query, you should
answer whether course 'u_j' is a prerequisite of course 'v_j' or not.
"""


class Solution(object):
    def checkIfPrerequisite(self, numCourses, prerequisites, queries):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[bool]
        """
        connected = [[False] * numCourses for i in range(numCourses)]
        for i, j in prerequisites:
            connected[i][j] = True
        for k in range(numCourses):
            for i in range(numCourses):
                for j in range(numCourses):
                    connected[i][j] = connected[i][j] or (
                        connected[i][k] and connected[k][j]
                    )
        return [connected[i][j] for i, j in queries]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.checkIfPrerequisite(
            numCourses=2, prerequisites=[[1, 0]], queries=[[0, 1], [1, 0]]
        )
    )
    print(
        obj.checkIfPrerequisite(
            numCourses=2, prerequisites=[], queries=[[1, 0], [0, 1]]
        )
    )
    print(
        obj.checkIfPrerequisite(
            numCourses=3,
            prerequisites=[[1, 2], [1, 0], [2, 0]],
            queries=[[1, 0], [1, 2]],
        )
    )
