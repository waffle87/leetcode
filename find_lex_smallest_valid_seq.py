# 3302. Find the Lexicographically Smallest Valid Sequence

"""
you are given two strings 'word1' and 'word2'. a string 'x' is called almost
equal to 'y' if you can change at most one character in 'x' to make it
identical to 'y'. a sequence of indices 'seq' is called valid if the indices
are sorted in ascending order, and concatenating the characters at these
indices in 'word1' in the smae order results in a string that is almost equal
to 'word2'. return an array of size 'word2.length' representing the
lexicographically smallest valid sequence of indices. if no such sequence o_
indices exists, return an empty array. note that the answer must represent
the lexicographically smallest array, not the corresponding string formed by
those indices.
"""


class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n1, n2 = len(word1), len(word2)
        pref = [0] * n1
        j = n2 - 1
        for i in range(n1 - 1, -1, -1):
            if i < n1 - 1:
                pref[i] = pref[i + 1]
            if j >= 0 and word1[i] == word2[j]:
                pref[i] += 1
                j -= 1
        ans = [-1] * n2
        match = 0
        i, j = 0, 0
        while i < n1 and j < n2:
            if word1[i] == word2[j]:
                ans[j] = i
                j += 1
                match += 1
            elif i < n1 - 1 and pref[i + 1] >= n2 - match - 1:
                ans[j] = i
                j += 1
                i += 1
                while j < n2 and i < n1:
                    if word1[i] == word2[j]:
                        ans[j] = i
                        j += 1
                    i += 1
                return ans
            i += 1
        if match == n2:
            return ans
        return []


if __name__ == "__main__":
    obj = Solution()
    print(obj.validSequence(word1="vbcca", word2="abc"))
    print(obj.validSequence(word1="bacdc", word2="abc"))
    print(obj.validSequence(word1="aaaaaa", word2="aaabc"))
    print(obj.validSequence(word1="abc", word2="ab"))
