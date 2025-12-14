# 2147. Number of Ways to Divide a Long Corridor

"""
along a long library corridor, there is a line of seats and decorative
plants. you are given a 0-indexed string 'corridor' of length 'n' consisting
of letters 's' and 'p' where each 's' represents a seat and each 'p'
represents a plant. one room divider has already been installed to the left
of index 0. and another to the right of index 'n - 1'. additional room
dividers can be installed. for each position between indices 'i - 1' and 'i'
at most one divider can be installed. divide the corridor into
non-overlapping sections, where each section has exactly two seats with any
number of plants. there may be multiple ways to perform the division. two
ways are different if there is a position with a room divider installed in
the first way but not the second way.
"""


class Solution(object):
    def numberOfWays(self, corridor):
        """
        :type corridor: str
        :rtype: int
        """
        a = [i for i, j in enumerate(corridor) if j == "S"]
        ans, mod = 1, 10**9 + 7
        for i in range(1, len(a) - 1, 2):
            ans *= a[i + 1] - a[i]
        return ans % mod * (len(a) % 2 == 0 and len(a) >= 2)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfWays(corridor="SSPPSPS"))
    print(obj.numberOfWays(corridor="PPSPSP"))
    print(obj.numberOfWays(corridor="S"))
