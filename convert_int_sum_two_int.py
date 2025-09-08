# 1317. Convert Integer to the Sum of Two No-Zero Integers

"""
no-zero integer is a positive integer that does not contain any 0 in its
decimal representation. given an integer 'n', return a list of two integers
'[a, b]' where 'a' and 'b' are no-zero integers and 'a + b = n'. the test
cases are generated such that there is at lease one valid solution. if there
are many valid solutions, you can return any of them
"""


class Solution(object):
    def check(self, n):
        return "0" not in str(n)

    def getNoZeroIntegers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        for i in range(1, n):
            j = n - i
            if self.check(i) and self.check(j):
                return [i, j]


if __name__ == "__main__":
    obj = Solution()
    print(obj.getNoZeroIntegers(2))
    print(obj.getNoZeroIntegers(11))
