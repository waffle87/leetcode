# 165. Compare Version Numbers

"""
given two version numbers 'version1' and 'version2', compare them. version
numbers consist of one or more revisions joined by a dot. each revision
consists of digits and may contain leading zeros. every revision contains at
least one character. revisions are 0-indexed from left to right, right the
leftmost revision being revision 0, the next revision being revision 1, and
so on. to compare version numbers, use the following rules. if 'version1 <
version2' return -1, if 'version1 > version2' return 1, otherwise, return 0
"""


class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        i, j, num1, num2 = 0, 0, 0, 0
        n, m = len(version1), len(version2)
        while i < n or j < m:
            while i < n and version1[i] != ".":
                num1 = num1 * 10 + (ord(version1[i]) - ord("0"))
                i += 1
            while j < m and version2[j] != ".":
                num2 = num2 * 10 + (ord(version2[j]) - ord("0"))
                j += 1
            if num1 > num2:
                return 1
            elif num1 < num2:
                return -1
            num1 = 0
            num2 = 0
            if i < n:
                i += 1
            if j < m:
                j += 1
        return 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.compareVersion(version1="1.01", version2="1.001"))
    print(obj.compareVersion(version1="1.0", version2="1.0.0"))
    print(obj.compareVersion(version1="0.1", version2="1.1"))
