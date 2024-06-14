# 344. Reverse String

"""
write a function that reverses a string. the input string is given as an
array of characters 's'. you must do this by modifying teh input array in
place with 'O(1)' extra memroy
"""


class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        s[:] = s[::-1]


if __name__ == "__main__":
    obj = Solution()
    s1 = "hello"
    s2 = "Hannah"
    obj.reverseString(s1)
    obj.reverseString(s2)
    print(s1)
    print(s2)
