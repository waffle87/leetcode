# 2696. Minimum String Length After Removing Substrings

"""
you are given a string 's' consisting only of uppercase english letters. you
can apply some operations to this string where in one operation you can
remove any occurence of one of the sbustrings 'AB' or 'CD' from 's'. return
the minimum possible length of the resulting string that you can obtain. note
that the string concatenates after removing the substring and could produce
new 'AB' or 'CD' substrings
"""


class Solution(object):
    def minLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        for c in s:
            if not stack:
                stack.append(c)
                continue
            if c == "B" and stack[-1] == "A":
                stack.pop()
            elif c == "D" and stack[-1] == "C":
                stack.pop()
            else:
                stack.append(c)
        return len(stack)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minLength(s="ABFCACDB"))
    print(obj.minLength(s="ACBBD"))
