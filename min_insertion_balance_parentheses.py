# 1541. Minimum Insertions to Balance a Parentheses String

"""
given a parentheses string 's' containing only the characters '(' and ')'. a
parenthese string is balanced if any left parenthesis '(' must have the
corresponding two right parentheses '))'. return the minimum number of
insertions needed to make 's' balanced.
"""


class Solution:
    def minInsertions(self, s: str) -> int:
        stack, n = [], len(s)
        cnt, i = 0, 0
        while i < n:
            if s[i] == "(":
                stack.append("(")
            else:
                if not stack:
                    if i != n - 1 and s[i + 1] == ")":
                        cnt += 1
                        i += 1
                    else:
                        cnt += 2
                else:
                    if i != n - 1 and s[i + 1] == ")":
                        stack.pop()
                        i += 1
                    else:
                        cnt += 1
                        stack.pop()
            i += 1
        return cnt + len(stack) * 2


if __name__ == "__main__":
    obj = Solution()
    print(obj.minInsertions(s="(()))"))
    print(obj.minInsertions(s="())"))
    print(obj.minInsertions(s="))())("))
