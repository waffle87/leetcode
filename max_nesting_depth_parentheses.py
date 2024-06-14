# 1614. Maximum Nesting Depth of the Parentheses


class Solution(object):
    def maxDepth(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        ans = 0
        for c in s:
            if c == "(":
                stack.append(c)
            elif c == ")":
                ans = max(ans, len(stack))
                stack.pop()
            else:
                continue
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDepth("(1+(2*3)+((8)/4))+1"))
    print(obj.maxDepth("(1)+((2))+(((3)))"))
