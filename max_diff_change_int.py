# 1432. Max Difference You Can Get From Changing an Integer

"""
you are given an integer 'num'. you will apply the following steps exactly
two times: pick a digit 'x (0 <= x <= 9)', pick another digit 'y (0 <= y <=
9)'. the digit 'y' can be equal to 'x'. replace all occurences of 'x' in the
decimal representation of 'num' by 'y'. the new integer cannot have any
leading zeros. also the new integer cannot be 0. let 'a' and 'b' be the
results of applying the operations to 'num' the first and second times
respectively. return the max difference between 'a' and 'b'.
"""


class Solution(object):
    def maxDiff(self, num):
        """
        :type num: int
        :rtype: int
        """
        n = str(num)
        maxn, minn = float("-inf"), float("inf")
        for i in "0123456789":
            for j in "0123456789":
                next = n.replace(i, j)
                if next[0] == "0" or int(next) == 0:
                    continue
                maxn = max(maxn, int(next))
                minn = min(minn, int(next))
        return maxn - minn


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDiff(num=555))
    print(obj.maxDiff(num=9))
