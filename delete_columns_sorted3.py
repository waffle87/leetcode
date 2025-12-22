# 960. Delete Columns to Make Sorted III

"""
you are given an array of 'n' strings 'strs', all of the same length. we may
choose any deletion indices and we delete all the characters in those indices
for each string. suppose we chose a set of deletion indices 'answer' such
that after deletions, the final array has every string (row) in lexicographic
order. return the minimum possible value of 'ans.length'.
"""


class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        n = len(strs[0])
        dp = [1] * n
        for j in range(1, n):
            for i in range(j):
                if all(s[i] <= s[j] for s in strs):
                    dp[j] = max(dp[j], dp[i] + 1)
        return n - max(dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDeletionSize(strs=["babca", "bbazb"]))
    print(obj.minDeletionSize(strs=["edcba"]))
    print(obj.minDeletionSize(strs=["ghi", "def", "abc"]))
