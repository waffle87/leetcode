# 3561. Resulting String After Adjacent Removals

"""
you are given a string 's' consisting of lowercase english letters. you must
repeatedly perform the following operation while the string 's' has at least
two consecutive characters: remove the leftmost pair of adjacent characters
in the string that are consecutive in the alphabet, in either order, and
shift the remaining characters to the left to fill the gap. return the
resulting string after no more operations can be performed. note: consider
the alphabet as circular, thus 'a' and 'z' are consecutive.
"""


class Solution(object):
    def resultingString(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = []

        def helper(a):
            c = abs(ord(ans[-1]) - ord(a))
            return c == 1 or c == 25

        for i in s:
            if ans and helper(i):
                ans.pop()
            else:
                ans.append(i)
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.resultingString(s="abc"))
    print(obj.resultingString(s="adcb"))
    print(obj.resultingString(s="zadb"))
