# 1404. Number of Steps to Reduce a Number in Binary Representation to One

"""
given the binary representation of an integer as a string 's', return the
number of steps to reduce it to 1 under the following rules. if the current
number is even, you have to divide it by 2. if the current number is odd, you
have to add 1 to it. it is guaranteed that you can always reach one for all
test cases.
"""


class Solution(object):
    def numSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans, carry, n = 0, 0, len(s)
        for i in range(n - 1, 0, -1):
            if int(s[i]) + carry == 1:
                carry = 1
                ans += 2
            else:
                ans += 1
        return ans + carry


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSteps("1101"))
    print(obj.numSteps("10"))
    print(obj.numSteps("1"))
