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
        a, b, cnt = s.count("a"), 0, len(s)
        for c in s:
            if c == "b":
                cnt = min(cnt, a + b)
                b += 1
            else:
                a -= 1
        return min(cnt, b)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumDeletions("aababbab"))
    print(obj.minimumDeletions("bbaaaaabb"))
