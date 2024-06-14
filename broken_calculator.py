# 991. Broken Calculator

"""
there is a broken calculator that has the integer 'start_value' on its
display initially. in one operation, you can
- multiply thenumber on display by 2
- subtract 1 from number on display
given two integers 'start_value' and 'target', return the minimum number of
operations needed to display 'target' on the calculator
"""


class Solution(object):
    def brokenCalc(self, start_value, target):
        ans = 0
        while start_value < target:
            ans += target % 2 + 1
            target = (target + 1) / 2
        return ans + start_value - target


if __name__ == "__main__":
    obj = Solution()
    print(obj.brokenCalc(2, 3))  # expect: 2
    print(obj.brokenCalc(5, 8))  # expect: 2
    print(obj.brokenCalc(3, 10))  # expect: 3
