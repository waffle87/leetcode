# 3174. Clear Digits

"""
you are given a string 's'. your task is to remove all digits by doing this
operation repeatedly: delete the first digit and the closest non digit
character to its left. return the resulting string after removing all digits.
"""


class Solution(object):
    def clearDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        for c in s:
            if c.isdigit():
                if stack:
                    stack.pop()
            else:
                stack.append(c)
        return "".join(stack)


if __name__ == "__main__":
    obj = Solution()
    print(obj.clearDigits(s="abc"))
    print(obj.clearDigits(s="cb34"))
