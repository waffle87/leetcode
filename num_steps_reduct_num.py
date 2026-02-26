# 1404. Number of Steps to Reduce a Number in Binary Representation to One

"""
given the binary representation of an integer as a string 's', return the
number of steps to reduce it to 1 under the following rules. if the current
number is even, you have to divide it by 2. if the current number is odd, you
have to add 1 to it. it is guaranteed that you can always reach one for all
test cases.
"""


class Solution:
    def numSteps(self, s: str) -> int:
        n, ops, carry = len(s), 0, 0
        for i in range(n - 1, 0, -1):
            digit = int(s[i]) + carry
            if digit % 2 == 1:
                ops += 2
                carry = 1
            else:
                ops += 1
        return ops + carry


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSteps(s="1101"))
    print(obj.numSteps(s="10"))
    print(obj.numSteps(s="1"))
