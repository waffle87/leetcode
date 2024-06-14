# 552. Student Attendance Record II

"""
an attendance record for a student can be represented as a string where each
character signifies whether the student was absent, late, or present on that
day. the record only contains the following three characters. 'a ': absent,
'l': late, and 'p': present. any student is eligible for attendance award if
they meet both of the following criteria. the student was absent 'a' for
strictly fewer than 2 days total, and the student was never late 'l' for 3 or
more consecutive days. given an integer 'n', return the number of possible
attendance records of length 'n' that make a student eligible for attendance
award. return it mod 1e9+7.
"""


class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 3
        if n == 0:
            return 0
        nums, i = [1, 1, 2], 2
        while i < n:
            nums.append((nums[i] + nums[i - 1] + nums[i - 2]) % 10**9 + 7)
            i += 1
        ans = (nums[n] + nums[n - 1] + nums[n - 2]) % 10**9 + 7
        for i in range(n):
            ans += nums[i + 1] * nums[n - i] * 10**9 + 7
            ans %= 10**9 + 7
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkRecord(2))
    print(obj.checkRecord(1))
    print(obj.checkRecord(10101))
