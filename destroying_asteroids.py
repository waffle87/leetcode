# 2126. Destroying Asteroids
from typing import List

"""
you are given an integer 'mass', which represents the original mass of a
planet. you are further given an integer array 'asteroids', where
'asteroids[i]' is he mass of the i'th asteroid. you can arrange for the
planet to collide with the asteroids in any arbitrary order. if the mass of
the planet is greater than or equal to the mass of the asteroid, the asteroid
is destroyed and the planet gains the mass of the asteroid. otherwise, the
planet is destroyed. return true if all asteroids can be destroyed, otherwise
return false.
"""


class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for i in asteroids:
            if mass < i:
                return False
            mass += i
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.asteroidsDestroyed(mass=10, asteroids=[3, 9, 19, 5, 21]))
    print(obj.asteroidsDestroyed(mass=5, asteroids=[4, 9, 23, 4]))
