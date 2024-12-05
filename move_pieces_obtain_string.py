# 2337. Move Pieces to Obtain a String

"""
you are given two strings 'start' and 'target' both of length 'n'. each
string consists only of the characters 'L', 'R', and '_' where the characters
'L' and 'R' represent pieces, where a piece 'L' can move to the left only if
there is a blank space directly to its left, and piece 'R' can move to the
right only if there is a blank space directly to its right. return true if it
is possible to obtain the string 'target' by moving the pieces of string
'start' any number of times. otherwise, return false.
"""


class Solution(object):
    def canChange(self, start, target):
        """
        :type start: str
        :type target: str
        :rtype: bool
        """
        if start.replace("_", "") != target.replace("_", ""):
            return False
        n, i, j = len(start), 0, 0
        while i < n and j < n:
            while i < n and start[i] == "_":
                i += 1
            while j < n and target[j] == "_":
                j += 1
            if (
                i < n
                and j < n
                and (start[i] == "L" and i < j or start[i] == "R" and i > j)
            ):
                return False
            i += 1
            j += 1
        return True


if __name__ == "__main__":
    obj = Solution()
    print(obj.canChange(start="_L__R__R_", target="L______RR"))
    print(obj.canChange(start="R_L_", target="__LR"))
    print(obj.canChange(start="_R", target="R_"))
