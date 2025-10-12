# 3539. Find Sum of Array Product of Magical Sequences

"""
you are given two integers 'm' and 'k', and an integer array 'nums'. a
sequence of integers 'seq' is called magical if 'seq' has a size of 'm', '0
<= seq[i] < nums.len', and the binary representation of '2^seq[0] + 2^seq[1]
+ ...' has 'k' set bits. the array product of this sequence is defined as
'prod(seq) = (nums[seq[0]]  nums[seq[1]]  ...)'. return the sum of the
array products for all valid magical sequences. since the answer may be very
large, return it modulo 10^9+7. a set bit refers to a bit in the binary
represenation of a number that has a value of 1
"""


class Solution(object):
    def magicalSum(self, m, k, nums):
        """
        :type m: int
        :type k: int
        :type nums: List[int]
        :rtype: int
        """
        mod = 10**9 + 7
        n = len(nums)
        powtab = [[1] * (m + 1) for _ in range(n)]
        for i in range(n):
            for c in range(1, m + 1):
                powtab[i][c] = powtab[i][c - 1] * nums[i] % mod
        comb = [[0] * (m + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            comb[i][0] = 1
            for j in range(1, i + 1):
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod
        dp = [[[0] * (k + 1) for _ in range(m + 1)] for __ in range(m + 1)]
        dp[m][0][0] = 1
        for i in range(n):
            next_dp = [[[0] * (k + 1) for _ in range(m + 1)] for __ in range(m + 1)]
            pow_i = powtab[i]
            for rem in range(m + 1):
                for carry in range(m + 1):
                    row = dp[rem][carry]
                    if not any(row_elt for row_elt in row):
                        continue
                    for ones in range(k + 1):
                        base_val = row[ones]
                        if base_val == 0:
                            continue
                        for c in range(rem + 1):
                            t = c + carry
                            bit = t & 1
                            ones2 = ones + bit
                            if ones2 > k:
                                continue
                            carry2 = t >> 1
                            rem2 = rem - c
                            add = base_val
                            add = add * comb[rem][c] % mod
                            add = add * pow_i[c] % mod
                            next_dp[rem2][carry2][ones2] = (
                                next_dp[rem2][carry2][ones2] + add
                            ) % mod
            dp = next_dp
        ans = 0
        for carry in range(m + 1):
            extra = bin(carry).count("1")
            need = k - extra
            if 0 <= need <= k:
                ans = (ans + dp[0][carry][need]) % mod
        return ans % mod


if __name__ == "__main__":
    obj = Solution()
    print(obj.magicalSum(m=5, k=5, nums=[1, 10, 100, 10000, 1000000]))
    print(obj.magicalSum(m=2, k=2, nums=[5, 4, 3, 2, 1]))
    print(obj.magicalSum(m=1, k=1, nums=[28]))
