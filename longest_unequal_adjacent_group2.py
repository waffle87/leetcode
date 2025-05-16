# 2901. Longest Unequal Adjacent Groups Subsequence II

"""
you are given a string array 'words' and an array 'groups', both arrays
having length 'n'. the hamming distance between two strings of equal length
is the number of positions at which the corresponding characters are
different. you need to select the longest subsequence from an array of
indices such that for the subsequence denoted as '[i0, i1, ..., ik-1]' having
length 'k', the following holds true: for adjacent indices in the subsequence
their corresponding groups are unequal. 'words[i]' and 'words[i + 1]' are
equal in length and the haming distance between them is 1. return a string
array containing the words corresponding to the indices in order in the
selected subsequence. if there are multiple, return any of them.
"""


class Solution(object):
    def getWordsInLongestSubsequence(self, words, groups):
        """
        :type words: List[str]
        :type groups: List[int]
        :rtype: List[str]
        """
        dp = []
        for i, j in zip(words, groups):
            dp.append(
                max(
                    (
                        k
                        for a, b, k in zip(words, groups, dp)
                        if j != b and len(i) == len(a) and sum(map(ne, i, a)) < 2
                    ),
                    key=len,
                    default=[],
                )
                + [i]
            )
        return max(dp, key=len)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.getWordsInLongestSubsequence(words=["bab", "dab", "cab"], groups=[1, 2, 2])
    )
    print(
        obj.getWordsInLongestSubsequence(
            words=["a", "b", "c", "d"], groups=[1, 2, 3, 4]
        )
    )
