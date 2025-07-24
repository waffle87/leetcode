# 2322. Minimum Score After Removals on a Tree
from collections import defaultdict

"""
there is an undirected connected tree with 'n' nodes labeled from 0 to 'n -
1' and 'n - 1' edges. you are given a 0-indexed integer array 'nums' of
length 'n' where 'nums[i]' represents the value of the i'th node. you are
also given a 2d integer array 'edges' of length 'n - 1' where 'edges[i] =
[a_i, b_i]' indicates that there is an edge between nodes 'a_i' and 'b_i' in
the tree. remove two distinct edges of the tree to form three connected
components. for a pair of removed edges, the following steps are defined: get
the xor of all the values of the nodes for each of the three components
respectively, the difference between the largest xor value and the smallest
xor value is the score of the pair. return the minimum score of any possible
pair of edge removals on the given tree.
"""


class Solution(object):
    def minimumScore(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        find = defaultdict(list)
        for x, y in edges:
            find[x].append(y)
            find[y].append(x)

        def xor_subtree(root, prev):
            res, val = [], nums[root]
            for i in find[root]:
                if i != prev:
                    tmp = xor_subtree(i, root)
                    res.extend(tmp)
                    val ^= tmp[-1]
            res.append(val)
            return res

        ans = float("inf")
        for x, y in edges:
            lx = xor_subtree(x, y)
            rx = xor_subtree(y, x)
            lv = lx[-1]
            rv = rx[-1]
            for l1 in lx[:-1]:
                l2 = lv ^ l1
                ans = min(ans, max(l1, l2, rv) - min(l1, l2, rv))
            for r1 in rx[:-1]:
                r2 = rv ^ r1
                ans = min(ans, max(r1, r2, lv) - min(r1, r2, lv))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minimumScore(nums=[1, 5, 5, 4, 11], edges=[[0, 1], [1, 2], [1, 3], [3, 4]])
    )
    print(
        obj.minimumScore(
            nums=[5, 5, 2, 4, 4, 2], edges=[[0, 1], [1, 2], [5, 2], [4, 3], [1, 3]]
        )
    )
