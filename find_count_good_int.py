# 3272. Find the Count of Good Integers
from math import factorial
from collections import Counter

"""
you are given two positive integers 'n' and 'k'. an integer 'x' is called
k-palindromic if 'x' is a palindrome and 'x' is divisble by 'k'. an integer
is called good if its digits can be rearranged to form a k-palindromic
integer. for example, for 'k = 2', 2020 can be rearranged to form the
k-palindromic integer 2002, wherase 1010 cannot be rearranged to form a
k-palindromic integer. return the count of good integers containing 'n'
digits.
"""


class Solution(object):
    def __init__(self):
        self.ans = 0
        self.vis = set()

    def to_num(self, digits):
        return int("".join(map(str, digits)))

    def permutation_cnt(self, freq, total):
        res = factorial(total)
        for i in freq.values():
            res //= factorial(i)
        return res

    def permutation_leading_zero(self, freq, total):
        if freq.get(0, 0) == 0:
            return 0
        freq[0] -= 1
        res = factorial(total - 1)
        for i in freq.values():
            res //= factorial(i)
        return res

    def gen_palindrome(self, palin, left, right, divisor, total):
        if left > right:
            val = self.to_num(palin)
            if val % divisor == 0:
                freq = Counter(palin)
                key = tuple(sorted(freq.items()))
                if key not in self.vis:
                    self.ans += self.permutation_cnt(
                        freq, total
                    ) - self.permutation_leading_zero(freq.copy(), total)
                    self.vis.add(key)
            return
        for i in range(1 if left == 0 else 0, 10):
            palin[left] = palin[right] = i
            self.gen_palindrome(palin, left + 1, right - 1, divisor, total)

    def countGoodIntegers(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        self.ans = 0
        self.vis.clear()
        self.gen_palindrome([0] * n, 0, n - 1, k, n)
        return self.ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countGoodIntegers(n=3, k=5))
    print(obj.countGoodIntegers(n=1, k=4))
    print(obj.countGoodIntegers(n=5, k=6))
