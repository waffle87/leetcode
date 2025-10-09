# 3494. Find the Minimum Amount of Time to Brew Potions
from itertools import accumulate

"""
you are given two integer arrays 'skill' and 'mana' of length 'n' and 'm'
respectively. in a laboratory, 'n' wizards must brew 'm' potions in order.
each potion has a mana capacity 'mana[j]' and must pass through all the
wizards sequentially to be brewed properly. the time taken by the i'th wizard
on the j'th potion is 'time_ij = skill[i]  mana[j]'. since the brewing
process is delicate, a potion must be passed to the next wizard immediately
after the current wizard completes their work. this means the timing must be
synchronised so that each wizard begins working on a potion exactly when it
arrives. return the minimum amount of time required for the potions to be
brewed properly.
"""


class Solution(object):
    def minTime(self, skill, mana):
        """
        :type skill: List[int]
        :type mana: List[int]
        :rtype: int
        """
        acc, t = list(accumulate(skill, initial=0)), 0
        for j in range(1, len(mana)):
            t += max(
                mana[j - 1] * acc[i + 1] - mana[j] * acc[i] for i in range(len(skill))
            )
        return t + acc[-1] * mana[-1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.minTime(skill=[1, 5, 2, 4], mana=[5, 1, 4, 2]))
    print(obj.minTime(skill=[1, 1, 1], mana=[1, 1, 1]))
    print(obj.minTime(skill=[1, 2, 3, 4], mana=[1, 2]))
