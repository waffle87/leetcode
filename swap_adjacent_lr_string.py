# 777. Swap Adjacent in LR String

"""
in a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a
move consists of either replacing one occurrence of "XL" with "LX", or
replacing one occurrence of "RX" with "XR". given the starting string 'start'
and the ending string 'end', return true if and only if there exists a
sequence of moves to transform 'start' to 'end'
"""


class Solution(object):
    def canTransform(self, start, end):
        """
        :type start: str
        :type end: str
        :rtype: bool
        """
        if start.replace("X", "") != end.replace("X", ""):
            return False
        n = len(start)
        l_start = [i for i in range(n) if start[i] == "L"]
        l_end = [i for i in range(n) if end[i] == "L"]
        r_start = [i for i in range(n) if start[i] == "R"]
        r_end = [i for i in range(n) if end[i] == "R"]
        for i, j in zip(l_start, l_end):
            if i < j:
                return False
        for i, j in zip(r_start, r_end):
            if i > j:
                return False
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.canTransform(start="RXXLRXRXL", end="XRLXXRRLX"))
    print(obj.canTransform(start="X", end="L"))
