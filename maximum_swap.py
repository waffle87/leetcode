# 670. Maximum Swap

"""
you are given an integer 'num'. you can swap two digits at most once to get
the maximum valued number. return the maximum valued number you can get.
"""


class Solution(object):
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        num = [int(x) for x in str(num)]
        max_idx, xi, yi = len(num) - 1, 0, 0
        for i in range(len(num) - 1, -1, -1):
            if num[i] > num[max_idx]:
                max_idx = i
            elif num[i] < num[max_idx]:
                xi = i
                yi = max_idx
        num[xi], num[yi] = num[yi], num[xi]
        return int("".join([str(x) for x in num]))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumSwap(2736))
    print(obj.maximumSwap(9973))
