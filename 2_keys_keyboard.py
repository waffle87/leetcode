# 650. 2 Keys Keyboard

"""
there is only one character 'A' on the screen of a notepad. you can perform
one of two operations on this notepad for each step. copy all characters
present on the screen (a partial copy is not allowed). paste the characters
which are copied last time. given an integer 'n', return the minimum number
of operations to get the character 'A' exactly 'n' times on the screen.
"""


class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                return self.minSteps(n / i) + i
        return 0 if n == 1 else n


if __name__ == "__main__":
    obj = Solution()
    print(obj.minSteps(3))
    print(obj.minSteps(1))
