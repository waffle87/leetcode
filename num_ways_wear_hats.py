# 1434. Number of Ways to Wear Different Hats to Each Other

"""
there are 'n' people and 40 types of hats labeled from 1 to 40. given a 2d
integer array 'hats', where 'hats[i]' is a list of all hats preferred by the
i'th person. return the number of ways that 'n' people can wear different
hats from each other. since the answer may be too large, return it modulo
10^9 + 7.
"""


class Solution(object):
    def numberWays(self, hats):
        """
        :type hats: List[List[int]]
        :rtype: int
        """
        mod = 10**9 + 7
        hat_ppl = [[] for i in range(41)]
        for i, j in enumerate(hats):
            for k in j:
                hat_ppl[k].append(i)
        hat_ppl = list(filter(lambda x: x, hat_ppl))
        hat_cnt, ppl_cnt = len(hat_ppl), len(hats)
        if hat_cnt < ppl_cnt:
            return 0

        def dp(i, mask):
            if bin(mask).count("1") == ppl_cnt:
                return 1
            if i == hat_cnt:
                return 0
            res = dp(i + 1, mask)
            for j in hat_ppl[i]:
                if mask & (1 << j) == 0:
                    mask |= 1 << j
                    res += dp(i + 1, mask)
                    mask ^= 1 << j
            return res % mod

        return dp(0, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberWays(hats=[[3, 4], [4, 5], [5]]))
    print(obj.numberWays(hats=[[3, 5, 1], [3, 5]]))
    print(obj.numberWays(hats=[[1, 2, 3, 4], [1, 2, 3, 4], [1, 2, 3, 4], [1, 2, 3, 4]]))
