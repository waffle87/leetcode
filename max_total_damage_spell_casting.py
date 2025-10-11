# 3186. Maximum Total Damage With Spell Casting
from collections import Counter

"""
a magician has various spells. you are given an array 'power', where each
element represents the damage of a spell. multiple spells can have the same
damage value. it is a known fact that if a magician decides to cast a spell
with a damage of 'power[i]', they cannot cast any spell with a damage of
'power[i] - 2', 'power[i] - 1', 'power[i] + 1', or 'power[i] + 2'. each spell
can only be cast once. return the maximum possible total damage that a
magician can cast.
"""


class Solution(object):
    def maximumTotalDamage(self, power):
        """
        :type power: List[int]
        :rtype: int
        """
        freq = Counter(power)
        keys = sorted(freq)
        n = len(keys)
        dp = [0] * n
        dp[0] = freq[keys[0]] * keys[0]
        for i in range(1, n):
            take = freq[keys[i]] * keys[i]
            l, r, ans = 0, i - 1, -1
            while l <= r:
                mid = (l + r) // 2
                if keys[mid] <= keys[i] - 3:
                    ans = mid
                    l = mid + 1
                else:
                    r = mid - 1
            if ans >= 0:
                take += dp[ans]
            dp[i] = max(dp[i - 1], take)
        return dp[-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumTotalDamage(power=[1, 1, 3, 4]))
    print(obj.maximumTotalDamage(power=[7, 1, 6, 6]))
