# 3532. Path Existence Queries in a Graph I

"""
you are given an integer 'n' representing the number of nodes in a graph,
labeled from tp to 'n - 1'. you are also given an integer array 'nums' of
length 'n' sorted in non-decreasing order, and an integer 'maxDiff'. an
undirected edge exists between nodes 'i' and 'j' if the absolute difference
between 'nums[i]' and 'nums[j]' is at most 'maxDiff'. you are also given a 2d
integer array 'queries'. for each 'queries[i] = [u_i, v_i]', determine
whether there exists a path between nodes 'u_i' and 'v_i'. return a boolean
array 'answer' where 'answer[i]' is 'true' if there exists a path between
'u_i' and 'v_i' in the i'th query and 'false' otherwise.
"""


class Solution:
    def pathExistenceQueries(
        self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]
    ) -> List[bool]:
        dp, cnt = [0] * n, 0
        for i in range(1, n):
            if nums[i] - nums[i - 1] > maxDiff:
                cnt += 1
            dp[i] = cnt
        return [dp[u] == dp[v] for u, v in queries]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.pathExistenceQueries(n=2, nums=[1, 3], maxDiff=1, queries=[[0, 0], [0, 1]])
    )
    print(
        obj.pathExistenceQueries(
            n=4, nums=[2, 5, 6, 8], maxDiff=2, queries=[[0, 1], [0, 2], [1, 3], [2, 3]]
        )
    )
