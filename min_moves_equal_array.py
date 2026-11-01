# 453. Minimum Moves to Equal Array Elements

"""
given an integer array 'nums' of size 'n', return the minimum number of moves
required to make all array elements equal. in one move you can increment 'n -
1' elements of the array by 1
"""


class Fenwick:
    def __init__(self, n: int) -> None:
        self.n: int = n
        self.bits: list[int] = [0] * (n + 1)

    def update(self, idx: int, val: int) -> None:
        idx += 1
        while idx <= self.n:
            self.bits[idx] += val
            idx += idx & -idx

    def query(self, idx: int) -> int:
        idx += 1
        res = 0
        while idx:
            res += self.bits[idx]
            idx -= idx & -idx
        return res


class Solution:
    def minMoves(self, nums: list[int]) -> int:
        n = len(nums)
        freq = {}
        for i in nums:
            freq[i] = freq.get(i, 0) + 1
        vals = sorted(freq)
        ranks = {j: i for i, j in enumerate(vals)}
        m = len(vals)
        tree = Fenwick(m)
        for i, j in freq.items():
            tree.update(ranks[i], j)
        ans = 0
        for i in range(1, m):
            gap = vals[i] - vals[i - 1]
            above = n - tree.query(i - 1)
            ans += gap * above
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minMoves([1, 2, 3]))
    print(obj.minMoves([1, 1, 1]))
