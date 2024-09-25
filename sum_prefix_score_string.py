# 2416. Sum of Prefix Scores of Strings

"""
you are given an array 'words' of size 'n' consisting of non empty strings.
we define the score of a string 'word' as the number of strings 'words[i]'
such that 'word' is a prefix of 'words[i]'. return an array 'answer' of size
'n' where 'answer[i]' is the sum of the scores of every non empty prefix of
'words[i]'. note that a string is considered as a prefix of itself.
"""


class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.cnt = 0


class Solution(object):
    def sumPrefixScores(self, words):
        """
        :type words: List[str]
        :rtype: List[int]
        """
        trie, a, ans = Trie(), ord("a"), []
        for w in words:
            t = trie
            for c in w:
                c = ord(c) - a
                if not t.children[c]:
                    t.children = Trie()
                t.children[c].cnt += 1
                t = t.children[c]
        for w in words:
            t, curr = trie, 0
            for c in w:
                c = ord(c) - a
                curr += t.children[c].cnt
                t = t.children[c]
            ans.append(curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumPrefixScores(words=["abc", "ab", "bc", "b"]))
    print(obj.sumPrefixScores(words=["abcd"]))
