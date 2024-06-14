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
        n1 = [int(v) for v in version1.split(".")]
        n2 = [int(v) for v in version2.split(".")]
        for i in range(max(len(n1), len(n2))):
            v1 = n1[i] if i < len(n1) else 0
            v2 = n2[i] if i < len(n2) else 0
            if v1 > v2:
                return 1
            elif v1 < v2:
                return -1
        return 0


if __name__ == "__main__":
    obj = Solution()
    print(obj.compareVersion(version1="1.01", version2="1.001"))
    print(obj.compareVersion(version1="1.0", version2="1.0.0"))
    print(obj.compareVersion(version1="0.1", version2="1.1"))
