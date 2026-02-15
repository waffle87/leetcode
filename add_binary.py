# 67. Add Binary

"""
given two binary strings 'a' and 'b', return their sum as a binary string.
"""


class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        ans, carry = [], 0
        i, j = len(a) - 1, len(b) - 1
        while i >= 0 or j >= 0 or carry:
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1
            ans.append(str(carry % 2))
            carry //= 2
        return "".join(reversed(ans))


if __name__ == "__main__":
    obj = Solution()
    print(obj.addBinary(a="11", b="1"))
    print(obj.addBinary(a="1010", b="1011"))
