# 2900. Longest Unequal Adjacent Groups Subsequence I

"""
you are given a string array 'words' and a binary array 'groups' both of
length 'n' where 'words[i]' is associated with 'groups[i]'. your task is to
select the longest alternating subsequence from 'words'. a subsequence of
'words' is alternating if for any two consecutive strings in the sequence,
their corresponding elements in the binary array 'groups' differ.
essentially, you are to choose strings such that adjacent elements have
non-matching corresponding bits in the 'groups' array. return the selected
subsequence. if there are multiple, return any of them. note: the elements in
'words' are distinct.
"""


class Solution(object):
    def getLongestSubsequence(self, words, groups):
        """
        :type words: List[str]
        :type groups: List[int]
        :rtype: List[str]
        """
        k = [0]
        for i, j in enumerate(groups):
            if j != groups[k[-1]]:
                k.append(i)
        return [words[i] for i in k]


if __name__ == "__main__":
    obj = Solution()
    print(obj.getLongestSubsequence(words=["e", "a", "b"], groups=[0, 0, 1]))
    print(obj.getLongestSubsequence(words=["a", "b", "c", "d"], groups=[1, 0, 1, 1]))
