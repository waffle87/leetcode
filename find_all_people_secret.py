# 2092. Find All People With Secret
from collections import defaultdict

"""
given an integer 'n' indicating there are 'n' people numbered from 0 to 'n -
1'. you are also given a 0-indexed 2d integer array 'meetings' where
'meetings[i] = [x_i, y_i, time_i]' indicates that person 'x_i'  and person
'y_i' have a metting at 'time_i'. a person may attend multiple meetings at
the same time. finally, you are given an integer 'firstPerson'. person 0 has
a secret and initially shares the secret with a person 'firstPerson' at time
0. this secret is then shared every time a meeting takes place with a person
that has the secret. more formall, for every meeting 'x_i', has secret at
'time_i' then they will share the secret with person 'y_i' and vice versa
"""


class Solution(object):
    def findAllPeople(self, n, meetings, firstPerson):
        """
        :type n: int
        :type meetings: List[List[int]]
        :type firstPerson: int
        :rtype: List[int]
        """

        class UnionFind:
            def __init__(self):
                self.parents = {}
                self.ranks = {}

            def insert(self, x):
                if x not in self.parents:
                    self.parents[x] = x
                    self.ranks[x] = 0

            def find_parent(self, x):
                if self.parents[x] != x:
                    self.parents[x] = self.find_parent(self.parents[x])
                return self.parents[x]

            def union(self, x, y):
                self.insert(x)
                self.insert(y)
                x, y = self.find_parent(x), self.find_parent(y)
                if x == y:
                    return
                if self.ranks[x] > self.ranks[y]:
                    self.parents[y] = x
                else:
                    self.parents[x] = y
                    if self.ranks[x] == self.ranks[y]:
                        self.ranks[y] += 1

        time2meets = defaultdict(list)
        for x, y, t in meetings:
            time2meets[t].append((x, y))
        time2meets = sorted(time2meets.items())

        curr_know = set([0, firstPerson])

        for time, meets in time2meets:
            uf = UnionFind()
            for x, y in meets:
                uf.union(x, y)

            groups = defaultdict(set)
            for idx in uf.parents:
                groups[uf.find_parent(idx)].add(idx)

            for group in groups.values():
                if group & curr_know:
                    curr_know.update(group)

        return list(curr_know)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findAllPeople(
            n=6, meetings=[[1, 2, 5], [2, 3, 8], [1, 5, 10]], firstPerson=1
        )
    )
    print(
        obj.findAllPeople(
            n=4, meetings=[[3, 1, 3], [1, 2, 2], [0, 3, 3]], firstPerson=3
        )
    )
    print(
        obj.findAllPeople(
            n=5, meetings=[[3, 4, 2], [1, 2, 1], [2, 3, 1]], firstPerson=1
        )
    )
