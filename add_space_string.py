# 2109. Adding Spaces to a String

"""
given a 0-indexed string 's' and a 0-indexed integer array 'spaces' that
describes the indices in the original string where spaces will be added. each
space should be inserted before the character at the given index. return the
modified string after the spaces have been added
"""


class Solution(object):
    def addSpaces(self, s, spaces):
        """
        :type s: str
        :type spaces: List[int]
        :rtype: str
        """
        ans, j = [], 0
        for i, c in enumerate(s):
            if j < len(spaces) and i == spaces[j]:
                ans.append(" ")
                j += 1
            ans.append(c)
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.addSpaces(s="LeetcodeHelpsMeLearn", spaces=[8, 13, 15]))
    print(obj.addSpaces(s="icodeinpython", spaces=[1, 5, 7, 9]))
    print(obj.addSpaces(s="spacing", spaces=[0, 1, 2, 3, 4, 5, 6]))
