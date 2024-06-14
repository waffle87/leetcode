# 1921. Eliminate Maximum Number of Monsters

"""
you are playing a video game where you are defending your city from a group
of 'n' monsters. you are given a 0-indexed integer array 'dist' of size 'n',
where 'dist[i]' is the initial distance in kilometres of the i'th monster
from the city. the monsters walk toward the city at a constant speed. the
speed of each monster is given to you in an integer array 'speed' of size
'n', where 'speed[i]' is the speed of thhe i'th monster in kilometres per
minute. you have a weapon that once fully charged can eliminate a single
monster. however, the weapon takes one minute to charge. the weapon is fully
charged at the very start. you lose when any monster reaches your city. if a
monster reaches the city at the exact moment thhe weapon is fully charged, it
counts as a loss. and thhe game ends before you can use your weapon. return
the maximum number of monsters that you can eliminate before you lose of 'n'
if you can eliminate all the monsters before they reachh thhe city
"""


class Solution(object):
    def eliminateMaximum(self, dist, speed):
        ans, t = 0, []
        for s, v in zip(dist, speed):
            t.append(s / v)
        t.sort()
        for i in range(len(dist)):
            if t[i] > i:
                ans += 1
            else:
                break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.eliminateMaximum(dist=[1, 3, 4], speed=[1, 1, 1]))
    print(obj.eliminateMaximum(dist=[1, 1, 2, 3], speed=[1, 1, 1, 1]))
    print(obj.eliminateMaximum(dist=[3, 2, 4], speed=[5, 3, 2]))
