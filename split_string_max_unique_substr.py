# 1593. Split a String Into the Max Number of Unique Substrings

"""
given a string 's', return the maximum number of unique substrings that the
given string can be split into. you can split string 's' into any list of
non-empty substrings, where the concatenation of the substrings forms the
origin string. however, you must split the substrings such that all of them
are unique. a substring is a contiguous sequence of characters within a
string.
"""


class Solution(object):
    def maxUniqueSplit(self, s):
        """
        :type s: str
        :rtype: int
        """

        def backtrack(beg, vis):
            if beg == len(s):
                return 0
            max_split = 0
            for end in range(beg + 1, len(s) + 1):
                substr = s[beg:end]
                if substr not in vis:
                    vis.add(substr)
                    max_split = max(max_split, backtrack(end, vis) + 1)
                    vis.remove(substr)
            return max_split

        return backtrack(0, set())


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxUniqueSplit(s="ababccc"))
    print(obj.maxUniqueSplit(s="aba"))
    print(obj.maxUniqueSplit(s="aa"))
