# 3202. Find the Maximum Length of Valid Subsequence II

"""
you are given an integer array 'nums' and a positive integer 'k'. a
subsequence 'sub' of 'nums' with length 'x' is called valid if it satisfies
'(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x
- 1]) % k'. return the length of the longest valid subsequence of 'nums'
"""


class Solution(object):
    def maximumLength(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        left = [[] for _ in range(k)]
        right = [i % k for i in nums]
        for i, j in enumerate(right):
            left[j].append(i)
        m = max(len(i) for i in left) if k > 0 else 0
        if k == 0 or k == 1:
            return m
        for x in range(k):
            for y in range(x + 1, k):
                a, b = left[x], left[y]
                la, lb = len(a), len(b)
                if la == 0 and lb == 0:
                    continue
                i, j = 0, 0
                sx, sy = 0, 0
                while i < la or j < lb:
                    if j == lb or (i < la and a[i] < b[j]):
                        nx = 1
                        if sy > 0:
                            nx = sy + 1
                        if nx > sx:
                            sx = nx
                        i += 1
                    else:
                        ny = 1
                        if sx > 0:
                            ny = sx + 1
                        if ny > sy:
                            sy = ny
                        j += 1
                curr = max(sx, sy)
                if curr > m:
                    m = curr
        return m


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumLength(nums=[1, 2, 3, 4, 5], k=2))
    print(obj.maximumLength(nums=[1, 4, 2, 3, 1, 4], k=3))
