# 2818. Apply Operations to Maximize Score

"""
you are given an array 'nums' of 'n' positive integers and an integer 'k'.
initially, you start with a score of 1. you have to maxmise your score by
applying the following operation at most 'k' times: chose any non-empty
element 'x' of 'nums[l .. r]' with the highest prime score. if multiple such
elements exist, choose the one with the smallest index. multiple your score
'x'. return the maximum possible score after applying at most 'k' operations.
since the answer may be very large, return it module '10e9+7'
"""


class Solution(object):
    mod = 10**9 + 7

    def mod_pow(self, x, n):
        res = 1
        while n > 0:
            if n % 2 == 1:
                res = (res * x) % self.mod
            x = (x * x) % self.mod
            n //= 2
        return res

    def maximumScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        n = len(nums)
        upper = max(nums) + 1
        prime = [True] * upper
        prime[0] = prime[1] = False
        score = [0] * upper
        for i in range(2, upper):
            if prime[i]:
                for j in range(i, upper, i):
                    score[j] += 1
                    prime[j] = False
        next, stk = [n] * n, []
        for i in range(n - 1, -1, -1):
            while stk and score[nums[i]] >= score[nums[stk[-1]]]:
                stk.pop()
            next[i] = stk[-1] if stk else n
            stk.append(i)
        prev, stk = [-1] * n, []
        for i in range(n):
            while stk and score[nums[i]] > score[nums[stk[-1]]]:
                stk.pop()
            prev[i] = stk[-1] if stk else -1
            stk.append(i)
        ans = 1
        tuples = [[nums[i], i] for i in range(n)]
        tuples.sort(reverse=True)
        for num, idx in tuples:
            operations = min(
                (idx - prev[idx]) * (next[idx] - idx),
                k,
            )
            ans = (ans * self.mod_pow(num, operations)) % self.mod
            k -= operations
            if k == 0:
                return ans
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumScore(nums=[8, 3, 9, 3, 8], k=2))
    print(obj.maximumScore(nums=[19, 12, 14, 6, 10, 18], k=3))
