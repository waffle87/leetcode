# 394. Decode String

"""
given an encoded string, return its decoded string. the encoding rule is
'k[encoded_string]' where the 'encoded_string' inside the square brackets is
being repeated exactly 'k' times. note that 'k' is guaranteed to be a
positive integer. you may assume that the input string is always valid; there
are no extra white spaces, square brackets are well-formed, etc. furthermore,
you may assume that the original data does not contain any digits, and that
digits are only for those repeat numbers, 'k'. the test cases are generated
such that the output will never exceed '10^5'.
"""


class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stk, curr_int, curr_str = [], 0, ""
        for c in s:
            if c == "[":
                stk.append(curr_str)
                stk.append(curr_int)
                curr_str = ""
                curr_int = 0
            elif c == "]":
                num = stk.pop()
                prev_str = stk.pop()
                curr_str = prev_str + num * curr_str
            elif c.isdigit():
                curr_int = curr_int * 10 + int(c)
            else:
                curr_str += c
        return curr_str


if __name__ == "__main__":
    obj = Solution()
    print(obj.decodeString(s="3[a]2[bc]"))
    print(obj.decodeString(s="3[a2[c]]"))
    print(obj.decodeString(s="2[abc]3[cd]ef"))
