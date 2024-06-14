# 1743. Restore the Array From Adjacent Pairs

"""
there is an integer array 'nums' that contains 'n' unique elements, but you
have forgotten it. however, you do remember that every pair of adjacent
elements in 'nums'. you are given a 2d integer array 'adjacent_pairs' of size
'n - 1' where each adjacent_pairs[i] = [ui, vi] indicates that the elements
'ui' and 'vi' are adjacent in 'nums'. it is guaranteed that every adjacent
pair of elements 'nums[i]' and 'nums[i + 1]' will exist in 'adjacent_pairs'
either as '[nums[i], nums[i + 1]]'. the pairs can appear in any order. return
the original array 'nums'. if there are multiple solutions, return any of
them.
"""


class Solution(object):
    def restoreArray(self, vals):
        pairs = defaultdict(list)

        for val in vals:
            pairs[val[0]].append(val[1])
            pairs[val[1]].append(val[0])

        ans = []
        start = -1000000

        for entry in pairs:
            if len(pairs[entry]) == 1:
                start = entry
                break

        left = -1000000
        ans.append(start)

        for i in range(1, len(vals) + 1):
            val = pairs[start]
            newval = val[0] if val[0] != left else val[1]
            ans.append(newval)
            left = start
            start = newval

        return ans
