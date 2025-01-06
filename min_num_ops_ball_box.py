# 1769. Minimum Number of Operations to Move All Balls to Each Box

"""
you have 'n' boxes. you are given a binary string 'boxes' of length 'n' where
'boxes[i]' is '0' if the i'th box is empty, and '1' if it contains one ball.
in one operation, you can move one ball from a box to an adjacent box. box
'i' is adjacent to box 'j' if 'abs(i - j) == 1'. note that after doing so,
there may be more than one ball in some boxes. return an array 'answer' of
size 'n' where 'answer[i]' is the minimum number of operations needed to move
all the balls to i'th box.
"""


class Solution(object):
    def minOperations(self, boxes):
        """
        :type boxes: str
        :rtype: List[int]
        """
        l_cnt, l_cost, r_cnt, r_cost, n = 0, 0, 0, 0, len(boxes)
        ans = [0] * n
        for i in range(n):
            if boxes[i - 1] == "1":
                l_cnt += 1
            l_cost += l_cnt
            ans[i] = l_cost
        for i in range(n - 2, -1, -1):
            if boxes[i + 1] == "1":
                r_cnt += 1
            r_cost += r_cnt
            ans[i] += r_cost
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(boxes="110"))
    print(obj.minOperations(boxes="001011"))
