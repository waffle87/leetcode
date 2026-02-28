# 1680. Concatenation of Consecutive Binary Numbers

"""
given an integer 'n', return the decimal value of the binary string formed by
concatenating the binary rerpesentations of 1 to 'n' in order, modulo 10^9
+ 7.
"""


class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans = ""
        for i in range(1, n + 1):
            ans += bin(i)[2:]
        return int(ans, 2) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.concatenatedBinary(n=1))
    print(obj.concatenatedBinary(n=3))
    print(obj.concatenatedBinary(n=12))
