# 1750. Minimum Length of String After Deleting Similar Ends

"""
g given a string 's' consisting of only characters a, b, and c you are asked to
g apply the following algorithm on the string any number of times. first, pick
g a non-empty prefix from the string 's' where all the characters in the prefix
g are equal. next, pick a non-empty suffix from the string 's' where all the
g characters in the suffix are equal. the prefix and the suffix should not
g intersect at any index. the characters from the prefix and the suffix must be
g the same. delete both the prefix and the suffix. return the minimum length of
g 's' after performining the above operation any number of times.
"""


class Solution(object):
    def minimumLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        while len(s) > 1 and s[0] == s[-1]:
            s = s.strip(s[0])
        return len(s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumLength("ca"))
    print(obj.minimumLength("cabaabac"))
    print(obj.minimumLength("aabccabba"))
