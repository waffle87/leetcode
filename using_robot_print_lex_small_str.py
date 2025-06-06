# 2434. Using a Robot to Print the Lexicographically Smallest String
from collections import Counter

"""
you are given a string 's' and a robot that currently holds an empty string
't'. apply one of the followiing operations until 's' and 't' are both empty.
remove the first character of a string 's' and give it to the robot. the
robot will append this charcter to the string 't'. remove the last character
of a string 't' and give it to the robot. the robot will write this character
on paper.
"""


class Solution(object):
    def robotWithString(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt, low, ans, t = Counter(s), "a", [], []
        for i in s:
            t += i
            cnt[i] -= 1
            while low < "z" and cnt[low] == 0:
                low = chr(ord(low) + 1)
            while t and t[-1] <= low:
                ans += t.pop()
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.robotWithString(s="zza"))
    print(obj.robotWithString(s="bac"))
    print(obj.robotWithString(s="bdda"))
