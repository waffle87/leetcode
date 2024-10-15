# 2938. Separate Black and White Balls

"""
there are 'n' balls on a table, each ball has a colour black or white. you
are given a 0-indexed binary string 's' of length 'n', where 1 and 0
represent black and white balls respectively. in each step, you can choose
two adjacent balls and swap them. return the minimum number of steps to group
all the black balls to the right and all the white balls to the left
"""


class Solution(object):
    def minimumSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        one_cnt, swap_cnt = 0, 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == "1":
                swap_cnt += one_cnt
            else:
                one_cnt += 1
        return swap_cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumSteps("101"))
    print(obj.minimumSteps("100"))
