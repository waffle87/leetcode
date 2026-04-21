# 1722. Minimize Hamming Distance After Swap Operations
from collections import Counter, defaultdict

"""
you are given two integer arrays, 'source' and 'target', both of length 'n'.
you are also given an array 'allowedSwaps' where each 'allowedSwaps[i] = [ai,
bi]' indicates that you are allowed to swap the elements at a specific pair
of indices multiple times and in any order. the hamming distance of two
arrays of the same length 'source' and 'target', is the number of positions
where the elements are different. return the minimum hamming distance of
'source' and 'target' after performing any aount of swap operations on array
'source'.
"""


class UnionFind:
    def __init__(self, n):
        self.root = list(range(n))

    def union(self, x, y):
        self.root[self.find(x)] = self.find(y)

    def find(self, x):
        if x != self.root[x]:
            self.root[x] = self.find(self.root[x])
        return self.root[x]


class Solution:
    def minimumHammingDistance(
        self, source: List[int], target: List[int], allowedSwaps: List[List[int]]
    ) -> int:
        uf = UnionFind(len(source))
        for x, y in allowedSwaps:
            uf.union(x, y)
        m = defaultdict(set)
        for i in range(len(source)):
            m[uf.find(i)].add(i)
        ans = 0
        for indices in m.values():
            A = [source[i] for i in indices]
            B = [target[i] for i in indices]
            ans += sum((Counter(A) - Counter(B)).values())
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minimumHammingDistance(
            source=[1, 2, 3, 4], target=[2, 1, 4, 5], allowedSwaps=[[0, 1], [2, 3]]
        )
    )
    print(
        obj.minimumHammingDistance(
            source=[1, 2, 3, 4], target=[1, 3, 2, 4], allowedSwaps=[]
        )
    )
    print(
        obj.minimumHammingDistance(
            source=[5, 1, 2, 4, 3],
            target=[1, 5, 4, 2, 3],
            allowedSwaps=[[0, 4], [4, 2], [1, 3], [1, 4]],
        )
    )
