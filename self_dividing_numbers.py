# 728. Self Dividing Numbers

"""
a self-dividing number is a number that is divisible by every digit it
contains. for example, 128 is a self-dividing number because 128 % 1 == 0,
128 % 2 == 0, and 128 % 8 == 0. a self-dividing number is not allowed to
contain the digit zero. given two integers 'left' and 'right', return a list
of all the self-dividing numbers in the range '[left, right]' (both
inclusive).
"""


class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        return [
            i
            for i in range(left, right + 1)
            if all((j and (i % j == 0) for j in map(int, str(i))))
        ]


if __name__ == "__main__":
    obj = Solution()
    print(obj.selfDividingNumbers(left=1, right=22))
    print(obj.selfDividingNumbers(left=47, right=85))
