# 2106. Maximum Fruits Harvested After at Most K Steps
from bisect import bisect_left

"""
fruits are available at some positions on an infinite x-axis. you are given a
2d integer array 'fruits' where 'fruits[i] = [positions[i], amount[i]]'
depicts 'amount[i]' fruits at the position 'position[i]'. 'fruits' is already
sorted by 'position[i]' in ascending order, and eash 'position[i]' is unique.
you are also given an integer 'startPos' and an integer 'k'. initially, y-u
are at the position 'startPos'. from any position, you can either walk to the
left or right. it takes one step to move one unit on the x-axis, and you can
walk at most 'k' steps in total. for every position you reach, you harvest
all the fruits at that position, and the fruits will dsiappear from that
position.
"""


class Solution(object):
    def maxTotalFruits(self, fruits, startPos, k):
        """
        :type fruits: List[List[int]]
        :type startPos: int
        :type k: int
        :rtype: int
        """
        l = bisect_left([i[0] for i in fruits], startPos + k)
        amount, total, r = 0, 0, l
        while r < len(fruits) and fruits[r][0] <= startPos + k:
            amount += fruits[r][1]
            while (
                min(
                    startPos - 2 * fruits[l][0] + fruits[r][0],
                    2 * fruits[r][0] - startPos - fruits[l][0],
                )
                > k
            ):
                amount -= fruits[l][1]
                l += 1
            total = max(total, amount)
            r += 1
        return total


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxTotalFruits(fruits=[[2, 8], [6, 3], [8, 6]], startPos=5, k=4))
    print(
        obj.maxTotalFruits(
            fruits=[[0, 9], [4, 1], [5, 7], [6, 2], [7, 4], [10, 9]], startPos=5, k=4
        )
    )
    print(obj.maxTotalFruits(fruits=[[0, 3], [6, 4], [8, 5]], startPos=3, k=2))
