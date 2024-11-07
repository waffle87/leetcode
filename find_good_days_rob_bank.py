# 2100. Find Good Days to Rob the Bank

"""
you and a gang of thieves are planning on robbing a bank. you are given a
0-indexed integer array 'security' where 'security[i]' is the number of
guards on duty on the i'th day. the days are numbered starting from 0. you
are also given an integer 'time'. the i'th day is a good day to rob the bank
if there are at least 'time' days before and after the i'th day, the number
of guards at the bank for the 'time' days before/after 'i' are
non-increasing/non-decreasing. return a list of all days (0-indexed) that are
good days to rob the bank. the order that the days are returned in does not
matter
"""


class Solution(object):
    def goodDaysToRobBank(self, security, time):
        """
        :type security: List[int]
        :type time: int
        :rtype: List[int]
        """
        left, right = [1], [1]
        n, curr = len(security), 1
        for i in range(1, n):
            if security[i] <= security[i - 1]:
                curr += 1
            else:
                curr = 1
            left.append(curr)
        curr = 1
        for i in range(n - 2, -1, -1):
            if security[i] <= security[i + 1]:
                curr += 1
            else:
                curr = 1
            right.append(curr)
        right.reverse()
        return [i for i in range(n) if left[i] >= time + 1 and right[i] >= time + 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.goodDaysToRobBank(security=[5, 3, 3, 3, 5, 6, 2], time=2))
    print(obj.goodDaysToRobBank(security=[1, 1, 1, 1, 1], time=0))
    print(obj.goodDaysToRobBank(security=[1, 2, 3, 4, 5, 6], time=2))
