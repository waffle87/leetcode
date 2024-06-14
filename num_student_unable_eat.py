# 1700. Number of Students Unable to Eat Lunch
from collections import Counter

"""
the school cafeteria offers circular and square sandwiches at lunch break,
referred to by numbers 0 and 1, respectively. all students stand in a queue.
each student either prefers square or circular sandwiches. the number of
sandwiches in the cafeteria is equal to the number of students.
"""


class Solution(object):
    def countStudents(self, students, sandwiches):
        """
        :type students: List[int]
        :type sandwiches: List[int]
        :rtype: int
        """
        cnt = Counter(students)
        n, k = len(students), 0
        while k < n and cnt[sandwiches[k]]:
            cnt[sandwiches[k]] -= 1
            k += 1
        return n - k


if __name__ == "__main__":
    obj = Solution()
    print(obj.countStudents(students=[1, 1, 0, 0], sandwiches=[0, 1, 0, 1]))
    print(obj.countStudents(students=[1, 1, 1, 0, 0, 1], sandwiches=[1, 0, 0, 0, 1, 1]))
