# 1124. Longest Well-Performing Interval

"""
given 'hours', a list of number of hours worked per day for a given employee.
a day is considered to be a tiring day if and only if the number of hours
worked is strictly greater than 8. a well performing interval is an interval
of days for which the number of tiring days is strictly larger than the
number of non tiring days. return the length of the longest well performing
interval
"""


class Solution(object):
    def longestWPI(self, hours):
        ans = score = 0
        seen = {}
        for i, h in enumerate(hours):
            score = score + 1 if h > 8 else score - 1
            if score > 0:
                ans = i + 1
            seen.setdefault(score, i)
            if score - 1 in seen:
                ans = max(ans, i - seen[score - 1])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestWPI([9, 9, 6, 0, 6, 6, 9]))  # expect: 3
    print(obj.longestWPI([6, 6, 6]))  # expect: 0
