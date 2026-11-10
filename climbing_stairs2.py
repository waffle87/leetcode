# 3693. Climbing Stairs II

"""
you are climbing a staircase with 'n + 1' steps numbered from 0 to 'n'. you
are also given a 1-indexed integer array 'costs' of length 'n' where
'costs[i]' is the cost step 'i'. from step 'i', you can jump only to step 'i
+ 1', 'i + 2', or 'i + 3'. the cost of jumping from step 'i' to 'j' is
defined as 'cost[j] + (j - i)^2'. you start from step 0 with cost 0. return
the minimum total cost to reach step 'n'.
"""


class Solution:
    def climbStairs(self, n: int, costs: list[int]) -> int:
        a, b, c = 0, 0, 0
        for i in costs:
            a, b, c = i + min(a + 1, b + 4, c + 9), a, b
        return a


if __name__ == "__main__":
    obj = Solution()
    print(obj.climbStairs(n=4, costs=[1, 2, 3, 4]))
    print(obj.climbStairs(n=4, costs=[5, 1, 6, 2]))
    print(obj.climbStairs(n=3, costs=[9, 8, 3]))
