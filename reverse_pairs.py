# 493. Reverse Pairs

"""
given an integer array 'nums', return the number of reverse pairs in the
array. a reverse pair is a pair '(i, j)' where '0 <= i < j < nums.len' and
'nums[i] > 2  nums[j]'
"""


class Bits:
    def __init__(self, n):
        self.n = n + 1
        self.sums = [0] * self.n

    def update(self, i, delta):
        while i < self.n:
            self.sums[i] += delta
            i += i & (-i)

    def query(self, i):
        res = 0
        while i > 0:
            res += self.sums[i]
            i -= i & (-i)
        return res


class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        new_nums = nums + [x * 2 for x in nums]
        sorted_set = sorted(list(set(new_nums)))
        tree = Bits(len(sorted_set))
        ans, ranks = 0, {}
        for i, n in enumerate(sorted_set):
            ranks[n] = i + 1
        for n in nums[::-1]:
            ans += tree.query(ranks[n] - 1)
            tree.update(ranks[n * 2], 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.reversePairs(nums=[1, 3, 2, 3, 1]))
    print(obj.reversePairs(nums=[2, 4, 3, 5, 1]))
