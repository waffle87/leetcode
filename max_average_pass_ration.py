# 1792. Maximum Average Pass Ratio
import heapq

"""
there is a school that has classes of student and each class will be having a
final exam. you are given a 2d integer array 'classes', where 'classes[i] =
[pass_i, total_i]'. you know beforehand that in the i'th class, there are
'total_i' total students, but only 'pass_i' number of students will pass the
exam. you are also given an integer 'extraStudents'. there are another
'extraStudents' brilliant students that are guaranteed to pass the exam of
any class they are assigned to. you want to assign each of the
'extraStudents' to a class in a way that maximises the average pass ration
across all classes. return the maximum possible average pass ratio after
assigning the 'extraStudents'. answers within '10^-5' of the actual answer
will be accepted.
"""


class Solution(object):
    def maxAverageRatio(self, classes, extraStudents):
        """
        :type classes: List[List[int]]
        :type extraStudents: int
        :rtype: float
        """
        pq = [(a / b - (a + 1) / (b + 1), a, b) for a, b in classes]
        heapq.heapify(pq)
        while extraStudents:
            v, a, b = heapq.heappop(pq)
            a, b = a + 1, b + 1
            heapq.heappush(pq, (-(a + 1) / (b + 1) + a / b, a, b))
            extraStudents -= 1
        return sum(a / b for v, a, b in pq) / len(pq)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxAverageRatio(classes=[[1, 2], [3, 5], [2, 2]], extraStudents=2))
    print(
        obj.maxAverageRatio(classes=[[2, 4], [3, 9], [4, 5], [2, 10]], extraStudents=4)
    )
