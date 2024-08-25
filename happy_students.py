# 2860. Happy Students

"""
you are given a 0 indexed integer array 'nums' of length 'n' where 'n' is the
total number of students in the class. the class teacher tries to select a
group of students so that all the students remain happy. the i'th student
will become happy if one of these two conditions is met: the student is
selected and the total number of selected students is strictly greater than
'nums[i]', or the student is not selected and the total number of selected
students is strictly less than 'nums[i]'. return the number of ways to select
a group of students os that everyone remains happy
"""


class Solution(object):
    def countWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        ans = int(nums[0] != 0)
        nums.append(float("inf"))
        for i in range(len(nums) - 1):
            if nums[i] < i + 1 < nums[i + 1]:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countWays(nums=[1, 1]))
    print(obj.countWays(nums=[6, 0, 3, 3, 6, 7, 2, 7]))
