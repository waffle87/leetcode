# 3463. Check If Digits Are Equal in String After Operations II
"""
you are given a string 's' consisting of digits. perform the following
operation repeatedly until the string has exactly two digits: for each pair
of consecutive digits in 's', starting from the first digit, calculate a new
digit as the sum of the two digits modulo 10. replace 's' with the sequence
of newly calculated digits, maintaining the order in which they are computed.
return 'true' if the final two digits in 's' are the same; otherwise return
false.
"""


class Solution(object):
    def hasSameDigits(self, s):
        """
        :type s: str
        :rtype: bool
        """

        def fac(a, mod):
            cnt = 0
            while a > 0 and a % mod == 0:
                cnt += 1
                a //= mod
            return a % mod, cnt

        def test(mod):
            n, res, r, c = len(s), 0, 1, 0
            for i in range(n - 1):
                if c == 0:
                    res += r * (int(s[i]) - int(s[i + 1]))
                rr, cc = fac(n - 2 - i, mod)
                r = r * rr % mod
                c += cc
                rr, cc = fac(i + 1, mod)
                r = r * pow(rr, mod - 2, mod) % mod
            return res % mod == 0

        return test(2) and test(5)


if __name__ == "__main__":
    obj = Solution()
    print(obj.hasSameDigits(s="3902"))
    print(obj.hasSameDigits(s="34789"))
