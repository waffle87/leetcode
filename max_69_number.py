# 1323. Maximum 69 Number

"""
you are given a positive integer 'num' consisting only of digit 6 and 9.
return the maximum number you can get by changing at most one digit. (6
becomes 9, and 9 becomes 6).
"""


class Solution(object):
    def maximum69Number(self, num):
        """
        :type num: int
        :rtype: int
        """
        return int(str(num).replace("6", "9", 1))


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximum69Number(9669))
    print(obj.maximum69Number(9996))
    print(obj.maximum69Number(9999))
