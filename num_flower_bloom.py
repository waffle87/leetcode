# 2251. Number of Flowers in Full Bloom

"""
given a 0-indexed 2d integer array 'flowers', where 'flowers[i] = [start[i],
end[i]]' means the i'th flower will be in full bloom from 'start[i]' to
'end[i]' (inclusive). you are also given a 0-indexed integer array 'people'
of size 'n' where 'people[i]' is the time that the i'th person will arrive to
see the flowers. return an integer array 'answer' of size 'n' where
'answer[i]' is the number of flowers that are in full bloom when the i'th
person arrives.
"""


class Solution(object):
    def fullBloomFlowers(self, flowers, people):
        diff = sortedcontainers.SortedDict({0: 0})
        for i, j in flowers:
            diff[i] = diff.get(i, 0) + 1
            diff[j + 1] = diff.get(j + 1, 0) - 1
        cnt = list(accumulate(diff.values()))
        return [cnt[diff.bisect(t) - 1] for t in persons]
