# 944. Delete Columns to Make Sorted

"""
you are given an array of 'n' strings 'strs', all of the same length. the
strings can be arranged such that there is one on each line, making a grid.
you want to delete the columns that are not sorted lexicographically. return
the number of columns that you will delete.
"""


class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        return sum(any(a > b for a, b in zip(i, i[1:])) for i in zip(*strs))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDeletionSize(strs=["cba", "daf", "ghi"]))
    print(obj.minDeletionSize(strs=["a", "b"]))
    print(obj.minDeletionSize(strs=["zyx", "wvu", "tsr"]))
