# 1957. Delete Characters to Make Fancy String

"""
a fancy string is a string where no three consecutive characters are equal.
given a string 's', delete the minimum possible number of characters from 's'
to make it fancy. return the final string after the deletion. it can be shown
that the answer will always be unique
"""


class Solution(object):
    def makeFancyString(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt, ans = 0, []
        for i, j in enumerate(s):
            if i > 0 and j == s[i - 1]:
                cnt += 1
            else:
                cnt = 1
            if cnt < 3:
                ans.append(j)
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.makeFancyString(s="leeetcode"))
    print(obj.makeFancyString(s="aaabaaaa"))
    print(obj.makeFancyString(s="aab"))
