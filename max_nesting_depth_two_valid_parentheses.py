# 1111. Maximum Nesting Depth of Two Valid Parentheses Strings


class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        return [i & 1 ^ (j == "(") for i, j in enumerate(seq)]


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDepthAfterSplit(seq="(()())"))
    print(obj.maxDepthAfterSplit(seq="()(())()"))
