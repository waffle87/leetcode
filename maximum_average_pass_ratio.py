# 1792. Maximum Average Pass Ratio
import heapq

"""
there is a school that has classes of students and each class will be having
a final exam. you are given a 2d integer array 'classes' where 'classes[i] =
[pass_i, total_i]'. you know beforehand that in the i'th there are 'total_i'
students, but only 'pass_i' students that will pass the exam. you are also
given in integer 'extraStudents'. there are another 'extraStudents' brilliant
students that are guaranteed to pass the exam of any class. return the
maximum possible average pass ratio after assigning the 'extraStudents'
students. answers within 10^-5 of the actual answer will be accepted.
"""


class Solution(object):
    def maxAverageRatio(self, classes, extraStudents):
        """
        :type classes: List[List[int]]
        :type extraStudents: int
        :rtype: float
        """
        h = [(a / b - (a + 1) / (b + 1), a, b) for a, b in classes]
        heapq.heapify(h)
        while extraStudents:
            v, a, b = heapq.heappop(h)
            a += 1
            b += 1
            heapq.heappush(h, (-(a + 1) / (b + 1) + a / b, a, b))
            extraStudents -= 1
        return sum(a / b for v, a, b in h) / len(h)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxAverageRatio(classes=[[1, 2], [3, 5], [2, 2]], extraStudents=2))
    print(
        obj.maxAverageRatio(classes=[[2, 4], [3, 9], [4, 5], [2, 10]], extraStudents=4)
    )
