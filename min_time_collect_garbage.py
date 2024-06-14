# 2391. Minimum Amount of Time to Collect Garbage
import itertools

"""
given a 0-indexed array of strings 'garbage' where 'garbage[i]' represents
the assortment of garbage at the i'th house. 'garbage[i]' consists of only
characters 'M, P, and G' representing one unit of metal, paper, and glass
garbage respectively. picking up one unitof any type of garbage takes 1
minute. you are also given a 0-indexed integer array 'travel' where
'travel[i]' is the number of minutes needed to go from house 'i' to house 'i
+ 1'. there are three garbage trucks in the city, each responsible for
picking up one type of garbage. each garbage truck starts at house 0 and must
visit each house in order, however they do not need to visit every house.
only one garbage truck may be used at any given moment. while one truck is
driving or picking up garbage, the other two trucks cannot do anything.
return the minimum number of minutes needed to pick up all the garbage.
"""


class Solution(object):
    def garbageCollection(self, garbage, travel):
        """
        :type garbage: List[str]
        :type travel: List[int]
        :rtype: int
        """
        last = {c: i for i, pgm in enumerate(garbage) for c in pgm}
        dist = list(itertools.accumulate(travel, initial=0))
        return sum(map(len, garbage)) + sum(dist[last.get(c, 0)] for c in "PGM")


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.garbageCollection(garbage=["G", "P", "GP", "GG"], travel=[2, 4, 3])
    )  # expect: 21
    print(
        obj.garbageCollection(garbage=["MMM", "PGM", "GP"], travel=[3, 10])
    )  # expect: 37
