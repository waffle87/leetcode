# 947. Most Stones Removed with Same Row or Column

"""
on a 2d plane, we place 'n' stones at some integer coordinate stones. each
coordinate point may have at most one stone. a stone can be removed if it
shares either the same row or the same column as another stone that has not
been removed. given an array 'stones' of length 'n' where 'stones[i] = [x_i,
y_i]' represents the location of the i'th stone, return the largest possible
number of stones that can be removed
"""


class Solution(object):
    def removeStones(self, stones):
        """
        :type stones: List[List[int]]
        :rtype: int
        """
        uf = {}

        def find(x):
            if x != uf.setdefault(x, x):
                uf[x] = find(uf[x])
            return uf[x]

        for i, j in stones:
            uf[find(i)] = find(~j)
        return len(stones) - len({find(x) for x in uf})


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeStones(stones=[[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]))
    print(obj.removeStones(stones=[[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]))
