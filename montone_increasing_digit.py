# 738. Monotone Increasing Digits

"""
an integer has monotone increasing digits if and only if each pair of
adjacent digts 'x' and 'y' satisfy 'x <= y'. given an integer 'n', return the
largest number that is less than or equal to 'n' with monotone inccreasing
digits
"""


class Solution(object):
    def monotoneIncreasingDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 10:
            return n
        k, idx = n, -1
        num = [int(d) for d in str(k)[::-1]]
        for i in range(1, len(num)):
            if num[i] > num[i - 1] or (idx != -1 and num[idx] == num[i]):
                idx = i
        if idx == -1:
            return n
        for i in range(idx):
            num[i] = 9
        num[idx] -= 1
        return int("".join([str(i) for i in num[::-1]]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.monotoneIncreasingDigits(10))
    print(obj.monotoneIncreasingDigits(1234))
    print(obj.monotoneIncreasingDigits(332))
