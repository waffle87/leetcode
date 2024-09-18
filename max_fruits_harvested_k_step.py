# 2106. Maximum Fruits Harvested After at Most K Steps
import bisect

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
        amt = {}
        for a, b in fruits:
            amt[a] = b
        pos = [a for a, b in fruits if a != startPos]
        left, right, n = [], [], len(pos)
        idx = bisect.insort_right(pos, startPos)
        curr_f = 0
        for i in range(idx, n):
            curr_pos = pos[i]
            curr_f += amt[curr_pos]
            right.append([curr_pos - pos, curr_f])
        curr_f = 0
        for i in range(idx - 1, -1, -1):
            curr_pos = pos[i]
            curr_f += amt[curr_pos]
            left.append([pos - curr_pos, curr_f])
        ans = 0
        for r_dist, r_f in right:
            if r_dist <= k:
                curr_f = r_f
                l_dist = k - 2 * r_dist
                if l_dist > 0:
                    idx = bisect.bisect_right(left, [l_dist, float("inf")])
                    if idx > 0:
                        curr_f += left[idx - 1][1]
                ans = max(ans, curr_f)
        for l_dist, l_f in left:
            if l_dist <= k:
                curr_f = l_f
                r_dist = k - 2 * l_dist
                if r_dist > 0:
                    idx = bisect.bisect_right(right, [r_dist, float("inf")])
                    if idx > 0:
                        curr_f += right[idx - 1][1]
                ans = max(ans, curr_f)
        return ans + amt.get(pos, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxTotalFruits(fruits=[[2, 8], [6, 3], [8, 6]], startPos=5, k=4))
    print(
        obj.maxTotalFruits(
            fruits=[[0, 9], [4, 1], [5, 7], [6, 2], [7, 4], [10, 9]], startPos=5, k=4
        )
    )
    print(obj.maxTotalFruits(fruits=[[0, 3], [6, 4], [8, 5]], startPos=3, k=2))
