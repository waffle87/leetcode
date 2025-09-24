# 166. Fraction to Recurring Decimal

"""
given two integers representing the 'numerator' and 'denominator' of a
fraction, reeturn the fraction in string format. if the fractional part is
repeating, enclose the repeating part in parentheses. if multiple answers are
possible, return any of them. it is guaranteed that the length of the answer
string is less than 10^4 for all the digits given inputs.
"""


class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        n, rem = divmod(abs(numerator), abs(denominator))
        sign = "-" if numerator * denominator < 0 else ""
        ans, stack = [sign + str(n), "."], []
        while rem not in stack:
            stack.append(rem)
            n, rem = divmod(rem * 10, abs(denominator))
            ans.append(str(n))
        idx = stack.index(rem)
        ans.insert(idx + 2, "(")
        ans.append(")")
        return "".join(ans).replace("(0)", "").rstrip(".")


if __name__ == "__main__":
    obj = Solution()
    print(obj.fractionToDecimal(1, 2))
    print(obj.fractionToDecimal(2, 1))
    print(obj.fractionToDecimal(4, 333))
