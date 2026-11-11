# 3789. Minimum Cost to Acquire Required Items

"""
you are given five integers 'cost1', 'cost2', 'costBoth', 'need1', and
'need2'. there are three types of items available:
- an item of type 1 costs 'cost1' and contributes 1 unit to the type 1
requirement only
- an item of type 2 costs 'cost2' and contributes 1 unit to the type 2
requirement only
- an item of type 3 costs 'costBoth' and contributes 1 unit to both type 1
and type 2 requirements. you must collect enough items so that the total
contribution toward type 1 is at least 'need1' and similarly such for
'need2'. return an integer representing the minimum possible total cost to
achieve these requirements.
"""


class Solution:
    def minimumCost(
        self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int
    ) -> int:
        def bound(need_a, cost_a, need_b, cost_b):
            p_a = min(cost_a, costBoth)
            p_b = min(cost_b, costBoth - p_a)
            return need_a * p_a + need_b * p_b

        return max(bound(need1, cost1, need2, cost2), bound(need2, cost2, need1, cost1))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumCost(cost1=3, cost2=2, costBoth=1, need1=3, need2=2))
    print(obj.minimumCost(cost1=5, cost2=4, costBoth=15, need1=2, need2=3))
    print(obj.minimumCost(cost1=5, cost2=4, costBoth=15, need1=0, need2=0))
