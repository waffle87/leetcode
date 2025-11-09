# 2169. Count Operations to Obtain Zero

"""
you are given two non-negative integers 'num1' and 'num2'. in one operation,
if 'num1 >= num2', you must subtract 'num2' from 'num1' otherwise subtract
'num1' from 'num2'. return the number of operations required to make either
'num1 = 0', or 'num2 = 0'
"""


class Solution(object):
    def countOperations(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        return (
            0 if num2 == 0 else num1 // num2 + self.countOperations(num2, num1 % num2)
        )


if __name__ == "__main__":
    obj = Solution()
    print(obj.countOperations(num1=2, num2=3))
    print(obj.countOperations(num1=10, num2=10))
