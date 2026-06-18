# 1344. Angle Between Hands of a Clock

"""
given two numbers, 'hour' and 'minutes', return the smaller angle (in
degrees) formed between the 'hour' and the 'minute' hand. answers within
10^-5 of the actual value will be accepted.
"""


class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        return min(abs(30 * hour - 5.5 * minutes), 360 - abs(30 * hour - 5.5 * minutes))


if __name__ == "__main__":
    obj = Solution()
    print(obj.angleClock(hour=12, minutes=30))
    print(obj.angleClock(hour=3, minutes=30))
    print(obj.angleClock(hour=3, minutes=15))
