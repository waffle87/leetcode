# 955. Delete Columns to Make Sorted II

"""
you are given an array of 'n' strings 'strs' all of the same length. we may
choose any deletion indices and we delete all the characters in those indices
for each string. for example, if we have 'strs = [abcdef, uvwxyz]' and
deletion indices '1, 2, 3', then the final array after deletions is '[bef,
vyz]'. suppose we chose a set of deletion indices 'answer' such that after
deletions, the final array has its elements in lexographic order. return the
minimum possible value of 'ans.len'.
"""


class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        n, m = len(strs), len(strs[0])
        unresolved, ans = n - 1, 0
        resolved = [False] * (n - 1)
        for i in range(m):
            if unresolved == 0:
                break
            need = False
            for j in range(n - 1):
                if not resolved[j] and strs[j][i] > strs[j + 1][i]:
                    need = True
                    break
            if need:
                ans += 1
                continue
            for j in range(n - 1):
                if not resolved[j] and strs[j][i] < strs[j + 1][i]:
                    resolved[j] = True
                    unresolved -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDeletionSize(strs=["ca", "bb", "ac"]))
    print(obj.minDeletionSize(strs=["xc", "yb", "za"]))
    print(obj.minDeletionSize(strs=["zyx", "wvu", "tsr"]))
