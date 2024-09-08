# 1947. Maximum Compatibility Score Sum

"""
there is a survey that consists of 'n' questions where each questions answer
is either 0 (no) or 1 (yes). the survey was given to 'm' students numbered
from 0 to 'm - 1' and 'm' mentors numbered from 0 to 'm - 1'. the answers of
the students are represented by a 2d integer array 'students' where
'students[i]' is an integer array that contains the answers of the i'th
student. the answers of the mentors are represented by a 2d integer array
'mentors' where 'mentors[j]' is an integer array that contains the answers of
the j'th mentor. each student will be assigned to one mentor. the
compatibility score of a student-mentor pair is the number of answers that
are the same for both student and mentor. given 'students' and 'mentors',
return the maximum compatibility score sum that can be achieved
"""


class Solution(object):
    def maxCompatibilitySum(self, students, mentors):
        """
        :type students: List[List[int]]
        :type mentors: List[List[int]]
        :rtype: int
        """
        m = len(students)
        score = [[0] * m for _ in range(m)]
        for i in range(m):
            for j in range(m):
                score[i][j] = sum(x == y for x, y in zip(students[i], mentors[j]))

        def dp(mask, j):
            res = 0
            for i in range(m):
                if not mask & (1 << i):
                    res = max(res, dp(mask ^ (1 << i), j - 1) + score[i][j])
            return res

        return dp(1 << m, m - 1)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxCompatibilitySum(
            students=[[1, 1, 0], [1, 0, 1], [0, 0, 1]],
            mentors=[[1, 0, 0], [0, 0, 1], [1, 1, 0]],
        )
    )
    print(
        obj.maxCompatibilitySum(
            students=[[0, 0], [0, 0], [0, 0]], mentors=[[1, 1], [1, 1], [1, 1]]
        )
    )
