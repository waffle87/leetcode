# 2358. Maximum Number of Groups Entering a Competition
"""iven a positive integer array 'grades' which represents the grades of
students in a university. you would like to entre all these students into a
competition in orderd non empty groups such that the ordering meets the
following requirements. the sum of the grades of students in the i'th group
is less than the sum of the grades of students in the '(i +1)'th group for
all groups except last. the total number of students in the i'th group is
less than the total number of students in the i'th group is less than the
total numboer of students in the '(i + 1)'th group, for all groups. return
the maximum numberof groups that can be formed.
 """


class Solution(object):
    def maximumGroups(self, grades):
        """
        :type grades: List[int]
        :rtype: int
        """
        n, k = len(grades), 0
        while n >= k + 1:
            k += 1
            n -= k
        return k
        # or return (int)(sqrt(len(grades) * 2 + 0.25) - 0.5)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumGroups(grades=[10, 6, 12, 7, 3, 5]))
    print(obj.maximumGroups(grades=[8, 8]))
