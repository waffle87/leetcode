# 3414. Maximum Score of Non-overlapping Intervals
from bisect import bisect_right

"""
you are given a 2d integer array 'intervals' where 'intervals[i] = [l_i, r_i,
weight_i]'. interval 'i' starts at position 'l_i', and ends at 'r_i' and has
a weight of 'weight_i'. you can choose up to 4 non overlapping intervals. the
score of the chosen intervals is defined as the total sum of their weights.
return the lexicographically smallest array of at most 4 indices from
'intervals' with maximum score, representing your choice of non-overlapping
intervals.
"""


class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        indices = {}
        for i, (l, r, w) in enumerate(intervals):
            key = (l, r, w)
            if key not in indices:
                indices[key] = i
        intervals = sorted(indices.keys())
        n = len(intervals)
        next_index = [0] * n
        for i in range(n):
            l, r, w = intervals[i]
            next_index[i] = bisect_right(intervals, (r, float("inf"), float("inf")))
        dp = [[(0, []) for _ in range(5)] for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            l, r, w = intervals[i]
            idx = indices[(l, r, w)]
            for k in range(1, 5):
                skip = dp[i + 1][k]
                take_score, take_idx = dp[next_index[i]][k - 1]
                take_score -= w
                take_idx = sorted(take_idx + [idx])
                take = (take_score, take_idx)
                dp[i][k] = min(skip, take)
        return dp[0][4][1]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maximumWeight(
            intervals=[[1, 3, 2], [4, 5, 2], [1, 5, 5], [6, 9, 3], [6, 7, 1], [8, 9, 1]]
        )
    )
    print(
        obj.maximumWeight(
            intervals=[
                [5, 8, 1],
                [6, 7, 7],
                [4, 7, 3],
                [9, 10, 6],
                [7, 8, 2],
                [11, 14, 3],
                [3, 5, 5],
            ]
        )
    )
