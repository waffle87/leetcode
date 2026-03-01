# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

"""
a decimal number is called deci-binary if each of its digits is either 0 or 1
without any leading zeros. for example, 101 and 1100 are deci-binary while
112 and 3001 are not. given a string 'n' that represents a positive decimal
integer, return the minimum number of possible deci-binary numbers needed so
that they sum up to 'n'.
"""


class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))


if __name__ == "__main__":
    obj = Solution()
    print(obj.minPartitions(n="32"))
    print(obj.minPartitions(n="82734"))
    print(obj.minPartitions(n="27346209830709182346"))
