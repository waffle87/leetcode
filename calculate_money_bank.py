# 1716. Calculate Money in Leetcode Bank

"""
hercy wants to save money for his first car. he puts money in the leetcode
bank every day. he starts by putting in $1 on monday, the first day. every
day from tuesday to sunday he will put in 1 more dollar than the day before.
on every subsequent monday, he will put in 1 more than the previous monday.
given 'n', return the total amount of money he will have in the leetcode bank
at the end of the n'th day.
"""


class Solution(object):
    def prog(self, next, prev, terms):
        return (next + prev) * terms // 2

    def totalMoney(self, n):
        """
        :type n: int
        :rtype: int
        """
        q, r = divmod(n, 7)
        return self.prog(28, 28 + (q - 1) * 7, q) + self.prog(q + 1, q + r, r)


if __name__ == "__main__":
    obj = Solution()
    print(obj.totalMoney(4))  # expect: 10
    print(obj.totalMoney(10))  # expect: 37
    print(obj.totalMoney(20))  # expect: 96
