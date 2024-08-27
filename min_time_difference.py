# 539. Minimum Time Difference

"""
given a list of 24 hour clock time points in 'HH:MM' format, return the
minimum minutes difference between any two time points in the list
"""


class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """

        def convert(time):
            return int(time[:2]) * 60 + int(time[3:])

        minutes = map(convert, timePoints)
        minutes.sort()

        return min(
            (y - x) % (24 * 60) for x, y in zip(minutes, minutes[1:] + minutes[:1])
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMinDifference(timePoints=["23:59", "00:00"]))
    print(obj.findMinDifference(timePoints=["00:00", "23:59", "00:00"]))
