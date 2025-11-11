# 474. Ones and Zeroes

"""
you are given an array of binary strings 'strs', and two integers 'm' and
'n'. return the size of the largest subset of 'strs' such that there are at
most 'm' 0's and 'n' 1's in the subset. a set 'x' is a subset of a set 'y' if
all elements of 'x' are also elements of 'y'.
"""


class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = {(0, 0): 0}
        for i in strs:
            ones, zeroes = 0, 0
            for j in i:
                if j == "0":
                    zeroes += 1
                else:
                    ones += 1
            tmp = {}
            for k, v in dp.items():
                prev_zeroes, prev_ones = k
                new_zeroes, new_ones = prev_zeroes + zeroes, prev_ones + ones
                if new_zeroes <= m and new_ones <= n:
                    if (new_zeroes, new_ones) not in dp:
                        tmp[(new_zeroes, new_ones)] = v + 1
                    elif dp[(new_zeroes, new_ones)] < v + 1:
                        tmp[(new_zeroes, new_ones)] = v + 1
            dp.update(tmp)
        return max(dp.values())


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMaxForm(strs=["10", "0001", "111001", "1", "0"], m=5, n=3))
    print(obj.findMaxForm(strs=["10", "0", "1"], m=1, n=1))
