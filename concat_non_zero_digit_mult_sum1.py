# 3754. Concatenate Non-Zero Digits and Multiply by Sum I

"""
you are given an integer 'n'. from a new integer 'x' by concatenating all the
non-zero digits of 'n' in their original order. if there are no non-zero
digits, 'x = 0'. let 'sum' be the sum of digits in 'x'. return an integer
representing the value of 'x  sum'.
"""


class Solution:
    def sumAndMultiply(self, n: int) -> int:
        return n and int(x := str(n).replace("0", "")) * sum(map(int, x))


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumAndMultiply(n=10203004))
    print(obj.sumAndMultiply(n=1000))
