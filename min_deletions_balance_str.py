# 1653. Minimum Deletions to Make String Balanced

"""
you are given a string 's' consisting of only characters 'a' and 'b'. you can
delete any number of characters in 's' to make 's' balanced. 's' is balanced
if there is no pair of indices '(i, j)' such that 'i < j' and 's[i] = b' and
's[j] = a'. return the minimum number of deletions needed to make 's'
balanced.
"""


class Solution(object):
    def minimumDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt, rem = 0, 0
        for i in s:
            if i == "a":
                rem = min(rem + 1, cnt)
            else:
                cnt += 1
        return rem


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDeletions("aababbab"))
    print(obj.minimumDeletions("bbaaaaabb"))
