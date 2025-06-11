# 3445. Maximum Difference Between Even and Odd Frequency II

"""
you are given a string 's' and an integer 'k'. your task is to find the
maximum difference between the frequency of two characters 'freq[a], -
freq[b]', in a substring 'subs' of 's' such that 'subs' has a size of at
least 'k', character 'a' has an odd frequency in 'subs', character 'b' has an
even frequency in 'subs'. return the maximum difference. note that 'subs' can
contain more than 2 distinct characters.
"""


class fenwick_tree:
    inf = float("inf")

    def __init__(self, n):
        self.n = n
        self.tree = [self.inf] * (n + 1)

    def update(self, i, val):
        pos = i + 1
        while pos <= self.n:
            self.tree[pos] = min(self.tree[pos], val)
            pos += pos & -pos

    def query(self, i):
        res, pos = self.inf, i + 1
        while pos > 0:
            res = min(res, self.tree[pos])
            pos -= pos & -pos
        return res


class Solution(object):
    def maxDifference(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n, ans = len(s), float("-inf")
        for a in range(5):
            for b in range(5):
                if a == b:
                    continue
                d = [0] * (n + 1)
                pa, pb = [0] * (n + 1), [0] * (n + 1)
                cnt_b = [0] * (n + 1)
                for i in range(1, n + 1):
                    digit = int(s[i - 1])
                    d[i] = (
                        d[i - 1] + (1 if digit == a else 0) - (1 if digit == b else 0)
                    )
                    pa[i] = (pa[i - 1] + (1 if digit == a else 0)) & 1
                    pb[i] = (pb[i - 1] + (1 if digit == b else 0)) & 1
                    cnt_b[i] = cnt_b[i - 1] + (1 if digit == b else 0)
                trees = [[fenwick_tree(n + 1) for _ in range(2)] for _ in range(2)]
                for j in range(n + 1):
                    if j >= k:
                        idx = j - k
                        trees[pa[idx]][pb[idx]].update(cnt_b[idx], d[idx])
                    if j > 0:
                        need_p, need_q = (
                            1 - pa[j],
                            pb[j],
                        )
                        if cnt_b[j] > 0:
                            best = trees[need_p][need_q].query(cnt_b[j] - 1)
                            if best != fenwick_tree.inf:
                                ans = max(ans, d[j] - best)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDifference(s="12233", k=4))
    print(obj.maxDifference(s="1122211", k=3))
    print(obj.maxDifference(s="110", k=3))
