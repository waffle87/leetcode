# 3479. Fruits Into Baskets III

"""
you are given two arrays of integers, 'fruits' and 'baskets', each of length
'n', where 'fruits[i]' represents the quantity of the i'th type of fruit, and
'baskets[j]' represents the capacity of the j'th basket. from left to right,
place the fruits according to these rules: each fruit type must be placed in
the leftmost available basket with a capacity greater than equal to the
quantity of that fruit type. return the number of fruit types that remain
unplaced after all possible allocations are made.
"""


class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        """
        :type fruits: List[int]
        :type baskets: List[int]
        :rtype: int
        """
        n, m = len(baskets), 1
        while m <= n:
            m <<= 1
        tree = [0] * (2 * m)
        for i in range(n):
            tree[m + i] = baskets[i]
        for i in range(m - 1, 0, -1):
            tree[i] = max(tree[2 * i], tree[2 * i + 1])
        ans = 0
        for i in fruits:
            curr = 1
            if tree[curr] < i:
                ans += 1
                continue
            while curr < m:
                if tree[2 * curr] >= i:
                    curr *= 2
                else:
                    curr = 2 * curr + 1
            tree[curr] = -1
            while curr > 1:
                curr //= 2
                tree[curr] = max(tree[2 * curr], tree[2 * curr + 1])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfUnplacedFruits(fruits=[4, 2, 5], baskets=[3, 5, 4]))
    print(obj.numOfUnplacedFruits(fruits=[3, 6, 1], baskets=[6, 4, 7]))
