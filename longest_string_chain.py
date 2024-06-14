# 1048. Longest String Chain

"""
you are given an array of 'words' where each word consists of lowercase
english letters. 'word[a]' is a predecessor of 'word[b]' if and only if we
can insert exactly one letter anywhere in 'word[a]' without changing the
order of the other characters to make it equal to 'word[b]'. return the
length of the longest possible word chain with words chosen from the given
list of words.
"""


class Solution(object):
    def longestStrChain(self, words):
        dp = {}
        for w in sorted(words, key=len):
            dp[w] = max(dp.get(w[:i] + w[i + 1 :], 0) + 1 for i in xrange(len(w)))
        return max(dp.values())


if __name__ == "__main__":
    obj = Solution()
    print(obj.longestStrChain(["a", "b", "ba", "bca", "bda", "bdca"]))  # expect: 4
    print(obj.longestStrChain(["xbc", "pcxbcf", "xb", "cxbc", "pcxbc"]))  # expect: 5
    print(obj.longestStrChain(["abcd", "dbqca"]))  # expect: 1
