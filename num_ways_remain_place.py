# 1269. Number of Ways to Stay in the Same Place After Some Steps

"""
you have a pointer at index 0 in an array of size 'arr_len'. at each step,
you can move 1 position to the left, 1 position to the right in the array, or
stay in the same plae. given two integers 'steps' and 'arr_len' return the
number of ways such that your pointer is still at index 0 after exactly
'steps' steps. since the answer may be too large, return it modulo 10e9+7
"""


class Solution(object):
    def dfs(self, steps, arr_len, pos):
        if pos < 0 or pos >= arr_len:
            return 0
        if steps == 0:
            return 1 if pos == 0 else 0
        return (
            self.dfs(steps - 1, arr_len, pos - 1)
            + self.dfs(steps - 1, arr_len, pos)
            + self.dfs(steps - 1, arr_len, pos + 1)
        )

    def numWays(self, steps, arr_len):
        if steps is None or steps < 0 or not arr_len:
            return 0
        return self.dfs(steps, arr_len, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numWays(3, 2))  # expect: 4
    print(obj.numWays(2, 4))  # expect: 2
    print(obj.numWays(4, 2))  # expect: 8
