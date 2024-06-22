# 1375. Number of Times Binary String Is Prefix-Aligned

"""
you have a 1 indexed binary string of length 'n' where all the bits are 0
initially. we will flip all the bits of this binary string one by one. you
are given a 1 indexed integer array 'flips' where 'flips[i]' indicates that
the bit at index 'i' will be flipped in the i'th step. a binar y string is
prefix aligned if after the i'th step, all the bits in the inclusive range
'[1, i]' are ones and all the other bits are zeros. return the number of
times the binary string is prefix aligned during the flipping process.
"""


class Solution(object):
    def numTimesAllBlue(self, flips):
        """
        :type flips: List[int]
        :rtype: int
        """
        ans, state = 0, 0
        for i in flips:
            state = state | (1 << (i - 1))
            if state & (state + 1) == 0:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numTimesAllBlue([3, 2, 4, 1, 5]))
    print(obj.numTimesAllBlue([4, 1, 2, 3]))
