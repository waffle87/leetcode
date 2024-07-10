# 1598. Crawler Log Folder
from functools import reduce

"""
the leetcode file system keeps a log each time some user performs a change
folder operation. the operations are described below. "../" move to the
parent folder of the current folder. if you are already in the main folder,
remain in the same folder. "./" remain in the same folder. "x/" move to the
child folder named 'x' which is guaranteed to exist. you are given a list of
strings 'logs' where 'logs[i]' is the operation performed by the user at the
i'th step.
"""


class Solution(object):
    def minOperations(self, logs):
        """
        :type logs: List[str]
        :rtype: int
        """
        return reduce(lambda depth, folder: max(0, depth - folder.rfind(".")), logs, 0)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minOperations(logs=["d1/", "d2/", "../", "d21/", "./"]))
    print(obj.minOperations(logs=["d1/", "d2/", "./", "d3/", "../", "d31/"]))
    print(obj.minOperations(logs=["d1/", "../", "../", "../"]))
