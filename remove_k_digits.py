# 402. Remove K Digits

"""
given string 'num' representing a non-negative integer 'num', and an integer
'k' return the smallest possible integer after removing 'k' digits from
'num'.
"""


class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        stk = list()
        for n in num:
            while stk and k and stk[-1] > n:
                stk.pop()
                k -= 1
            if stk or n != "0":
                stk.append(n)
        if k:
            stk = stk[0:-k]
        return "".join(stk) or "0"


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeKdigits(num="1432219", k=3))
    print(obj.removeKdigits(num="10200", k=1))
    print(obj.removeKdigits(num="10", k=2))
