# 3337. Total Characters in String After Transformations II

"""
you are given a string 's' consisting of lowercase english letters, an
integer 't' representing the number of transformations to perform, and an
array 'nums' of size 26. in one transformation, every character in 's' is
replaced according to the following rules: replace 's[i]' with the next
'nums[s[i] - 'a']' consecutive characters in the alphabet. the transformation
wraps around the alphabet if it exceeds 'z'. return the length of the
resulting string after exactly 't' tranformations.
"""


class Solution(object):
    def multiply(self, a, b, mod):
        res = [[0] * len(b[0]) for _ in range(len(a))]
        for i in range(len(a)):
            for j in range(len(b[0])):
                for k in range(len(b)):
                    res[i][j] += a[i][k] * b[k][j]
                res[i][j] %= mod
        return res

    def power(self, base, pow, mod):
        n = len(base)
        res = [[1 if i == j else 0 for j in range(n)] for i in range(n)]
        while pow > 0:
            if pow & 1:
                res = self.multiply(res, base, mod)
            base = self.multiply(base, base, mod)
            pow >>= 1
        return res

    def lengthAfterTransformations(self, s, t, nums):
        """
        :type s: str
        :type t: int
        :type nums: List[int]
        :rtype: int
        """
        transform = [[0] * 26 for i in range(26)]
        for i, j in enumerate(nums):
            for k in range(i + 1, i + j + 1):
                transform[i][k % 26] = 1
        cnt, mod = [0] * 26, 10**9 + 7
        matrix = self.power(transform, t, mod)
        for i in s:
            cnt[ord(i) - ord("a")] += 1
        ans = self.multiply([cnt], matrix, mod)
        return sum(ans[0]) % mod


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.lengthAfterTransformations(
            s="abcyy",
            t=2,
            nums=[
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                2,
            ],
        )
    )
    print(
        obj.lengthAfterTransformations(
            s="azbk",
            t=1,
            nums=[
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
                2,
            ],
        )
    )
