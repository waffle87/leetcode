# 1282. Group the People Given the Group Size They Belong To
import collections

"""
there are 'n' people that are split into some unknown number of groups. each
person is labeled with a unique id from 0 to 'n - 1'. you are given an
integer array 'group_sizes' where 'group_sizes[i]' is the size of the group
that person 'i' is in. for example if 'group_sizes[i] = 3', then person 1
must be in a groiup size of 3. return a list of groups such that each person
'i' is in a group of size 'group_sizes[i]'. each person should appear in
exactly one group, and every person must be in a group. if there are multiple
answers, return any of them. it is guaranteed that there will be at least one
valid solution for the given input.
"""


class Solution(object):
    def groupThePeople(self, group_sizes):
        count = collections.defaultdict(list)
        for i, size in enumerate(group_sizes):
            count[size].append(i)
        return [l[i : i + s] for s, l in count.items() for i in xrange(0, len(l), s)]


if __name__ == "__main__":
    obj = Solution()
    print(obj.groupThePeople([3, 3, 3, 3, 3, 1, 3]))  # expect: [[5],[0,1,2],[3,4,6]]
    print(obj.groupThePeople([2, 1, 3, 3, 3, 2]))  # expecct: [[1],[0,5],[2,3,4]]
