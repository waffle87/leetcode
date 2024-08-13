# 40. Combination Sum II

"""
given a collection of candidate numbers and a target number, find all unique
combinations in 'candidates' where the candidate numbers sum to 'target'.
each number in 'candidates' may only be used once
"""


class Solution(object):
    def dfs(self, candidates, target, idx, path, res):
        if target <= 0:
            if target == 0:
                res.append(path)
            return
        for i in range(idx, len(candidates)):
            if i > idx and candidates[i] == candidates[i - 1]:
                continue
            self.dfs(
                candidates, target - candidates[i], i + 1, path + [candidates[i]], res
            )

    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        self.dfs(sorted(candidates), target, 0, [], ans)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.combinationSum2(candidates=[10, 1, 2, 7, 6, 1, 5], target=8))
    print(obj.combinationSum2(candidates=[2, 5, 2, 1, 2], target=5))
