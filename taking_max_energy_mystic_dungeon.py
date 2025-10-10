# 3147. Taking Maximum Energy From the Mystic Dungeon

"""
in a mystic dungeon, 'n' magicians are standing in a line. each magician has
an attribute that gives you energe. some magicians can give you negative
energy, which means taking energy from you. you have been cursed in such a
way that after absorbing energy from magician 'i', you will be instantly
transported to magician '(i + k)'. this process will be repeated until you
reach the magician where '(i + k)' does not exist. in other words, you will
choose a starting point until you reach the end of the magicians sequence,
absorbing all the energy during the journey. you are given an array 'energy'
and an integer 'k'. return the maximum possible energy you can gain. note
that when you are reach a magician, you must take energy from them, whether
it is positive or negative.
"""


class Solution(object):
    def maximumEnergy(self, energy, k):
        """
        :type energy: List[int]
        :type k: int
        :rtype: int
        """
        ans, n = float("-inf"), len(energy)
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            dp[i] = energy[i] + (dp[i + k] if i + k < n else 0)
            ans = max(ans, dp[i])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumEnergy(energy=[5, 2, -10, -5, 1], k=3))
    print(obj.maximumEnergy(energy=[-2, -3, -1], k=2))
