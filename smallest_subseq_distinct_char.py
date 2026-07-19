# 1081. Smallest Subsequence of Distinct Characters

"""
given a string 's', return the lexicographically smallest subsequence of 's'
that contains all the distinct characters of 's' exactly once.
"""


class Solution:
    def smallestSubsequence(self, s: str) -> str:
        freq = {i: 0 for i in s}
        vis, stack = set(), []
        for i in s:
            freq[i] += 1
        for i in s:
            freq[i] -= 1
            if i in vis:
                continue
            while stack and stack[-1] > i and freq[stack[-1]] > 0:
                vis.remove(stack.pop())
            stack.append(i)
            vis.add(i)
        return "".join(stack)


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestSubsequence(s="bcabc"))
    print(obj.smallestSubsequence(s="cbacdcbc"))
