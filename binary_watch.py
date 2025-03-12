# 401. Binary Watch

"""
a binary watch has 4 leds on the top to represent the hours (0 - 11) and 6
leds on the bottom to represent the minutes (0 - 59). each led represents a 0
or one, with the least siginificant bit on the right. given an integer
'turnedOn' which represents the number of leds that are currently on, return
all possible times the watch could represent. you may return the answer in
any order.
"""


class Solution(object):
    def readBinaryWatch(self, turnedOn):
        """
        :type turnedOn: int
        :rtype: List[str]
        """
        return [
            "%d:%02d" % (h, m)
            for h in range(12)
            for m in range(60)
            if (bin(h) + bin(m)).count("1") == turnedOn
        ]


if __name__ == "__main__":
    obj = Solution()
    print(obj.readBinaryWatch(turnedOn=1))
    print(obj.readBinaryWatch(turnedOn=9))
