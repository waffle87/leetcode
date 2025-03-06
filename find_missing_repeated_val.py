# 2965. Find Missing and Repeated Values

"""
you are given a 0-indexed 2d integer matrix 'grid' of size 'n  n' with
values in the range '[1, n^2]'. each integer appears exactly once except 'a'
which appears twice and 'b' which is missing. the task is to find the
repeating and missing numbers 'a' and 'b'. return a 0-indexed integer array
'ans' of size '2' where 'ans[0]' equals to 'a' and 'ans[1]' equals 'b'.
"""


class Solution(object):
    def findMissingAndRepeatedValues(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[int]
        """
        repeated, missing, n = 0, 0, len(grid)
        cnt = [0] * (n * n + 1)
        for i in grid:
            for j in i:
                cnt[j] += 1
                if cnt[j] == 2:
                    repeated = j
        for i in range(1, n * n + 1):
            if cnt[i] == 0:
                missing = i
                break
        return [repeated, missing]


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMissingAndRepeatedValues(grid=[[1, 3], [2, 2]]))
    print(obj.findMissingAndRepeatedValues(grid=[[9, 1, 7], [8, 9, 2], [3, 4, 6]]))
