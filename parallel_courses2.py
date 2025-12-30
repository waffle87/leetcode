# 1494. Parallel Courses II
from itertools import permutations

"""
you are given an integer 'n' which indicates that there are 'n' courses
labeled from 1 to 'n'. you are also given an array 'relations' where
'relations[i] = [prev_course[i], next_course[i]]', representing a
prerequisite relationship between course 'prev_course' and course
'next_course': course 'prev_course' has to be taken before 'next_course'.
also, you are given integer 'k'. in one semester, you can take most 'k'
course as long as you have taken all the prerequisites in the previous
semesters for the courses you are taking. return the minimum number of
semesters needed to take all courses. the testcases will be generated such
that it is possible to take every course.
"""


class Solution(object):
    def minNumberOfSemesters(self, n, relations, k):
        """
        :type n: int
        :type relations: List[List[int]]
        :type k: int
        :rtype: int
        """
        dp = [[(100, 0, 0)] * n for _ in range(1 << n)]
        prereq = [0] * n
        for i, j in relations:
            prereq[j - 1] ^= 1 << (i - 1)
        for i in range(n):
            if prereq[i] == 0:
                dp[1 << i][i] = (1, 1, 1 << i)
        for i in range(1 << n):
            nz_bit = [len(bin(i)) - j - 1 for j, l in enumerate(bin(i)) if l == "1"]
            for j, l in permutations(nz_bit, 2):
                if prereq[l] & i == prereq[l]:
                    candid, bits, mask = dp[i ^ (1 << l)][j]
                    if prereq[l] & mask == 0 and bits < k:
                        dp[i][l] = min(dp[i][l], (candid, bits + 1, mask + (1 << l)))
                    else:
                        dp[i][l] = min(dp[i][l], (candid + 1, 1, 1 << l))
        return min([i for i, j, k in dp[-1]])


if __name__ == "__main__":
    obj = Solution()
    print(obj.minNumberOfSemesters(n=4, relations=[[2, 1], [3, 1], [1, 4]], k=2))
    print(
        obj.minNumberOfSemesters(n=5, relations=[[2, 1], [3, 1], [4, 1], [1, 5]], k=2)
    )
