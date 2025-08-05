# 3477. Fruits Into Baskets II

"""
you are given two arrays of integers 'fruits' and 'baskets' each of length
'n', where 'fruits[i]' represents the quantity of the i'th type of fruit, and
'baskets[j]' represents the capacity of the 'j'th basket. from left to right,
place the fruits according to these rules: each fruit type must be place in
the leftmost available basket with a capacity greater than or equal to the
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
        n = len(fruits)
        used = [False] * n
        unplaced = 0
        for i in fruits:
            placed = False
            for j in range(n):
                if not used[j] and baskets[j] >= i:
                    used[j] = True
                    placed = True
                    break
            if not placed:
                unplaced += 1
        return unplaced


if __name__ == "__main__":
    obj = Solution()
    print(obj.numOfUnplacedFruits(fruits=[4, 2, 5], baskets=[3, 5, 4]))
    print(obj.numOfUnplacedFruits(fruits=[3, 6, 1], baskets=[6, 4, 7]))
