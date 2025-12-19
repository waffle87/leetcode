# 2092. Find All People With Secret

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
    def find(self, groups, idx):
        while idx != groups[idx]:
            idx = groups[idx]
        return idx

    def findAllPeople(self, n, meetings, firstPerson):
        """
        :type n: int
        :type meetings: List[List[int]]
        :type firstPerson: int
        :rtype: List[int]
        """
        groups = [i for i in range(n)]
        groups[firstPerson] = 0
        meetings.sort(key=lambda x: x[2])
        size, i = len(meetings), 0
        while i < size:
            curr_time, tmp = meetings[i][2], []
            while i < size and meetings[i][2] == curr_time:
                g1 = self.find(groups, meetings[i][0])
                g2 = self.find(groups, meetings[i][1])
                groups[max(g1, g2)] = min(g1, g2)
                tmp.extend([meetings[i][0], meetings[i][1]])
                i += 1
            for j in tmp:
                if self.find(groups, j) != 0:
                    groups[j] = j
        ans = []
        for j in range(n):
            if self.find(groups, j) == 0:
                ans.append(j)
        return ans


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
