# 3042. Count Prefix and Suffix Pairs I

"""
you are given a 0-indexed string array 'words'. let's define a boolean
function 'isPrefixSuffix' that takes two strings 'str1' and 'str2'.
'isPrefixSuffix()' returns true if 'str1' is both a prefix and suffix of
'str2', and false otherwise. return an integer denoting the number of index
pairs '(i, j)' such that 'i < j' and 'isPrefixSuffix(words[i], words[j])' is
true.
"""


class Solution(object):
    def countPrefixSuffixPairs(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        cnt = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if (
                    words[j].find(words[i], 0, len(words[i])) == 0
                    and words[j][::-1].find(words[i][::-1], 0, len(words[i])) == 0
                ):
                    cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.countPrefixSuffixPairs(words=["a", "aba", "ababa", "aa"]))
    print(obj.countPrefixSuffixPairs(words=["pa", "papa", "ma", "mama"]))
    print(obj.countPrefixSuffixPairs(words=["abab", "ab"]))
