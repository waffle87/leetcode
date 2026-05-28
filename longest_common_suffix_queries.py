# 3093. Longest Common Suffix Queries
from typing import List

"""
you are given two arrays of strings 'wordsContainer' and 'wordsQuery'. for
each 'wordsQuery[i]', you need to find a string from 'wordsContainer' that
has the longest common suffix with 'wordsQuery[i]'. if there are two or more
string in 'wordsContainer' that share the longest common suffix, find the
string that is the smallest in length. if there are two or more such strigs
that have the same smallest length, find the one that occured earlier in
'wordsContainer'. return an array of integers 'ans' where 'ans[i]' is the
index of the string in 'wordsContainer' that has the longest common suffix
with 'wordsQuery[i]'.
"""


class trie_node:
    def __init__(self):
        self.children = {}
        self.min_len = float("inf")
        self.idx = float("inf")


class Solution:
    def stringIndices(
        self, wordsContainer: List[str], wordsQuery: List[str]
    ) -> List[int]:
        root = trie_node()
        for i, word in enumerate(wordsContainer):
            n = len(word)
            curr = root
            if n < curr.min_len or (n == curr.min_len and i < curr.idx):
                curr.min_len = n
                curr.idx = i
            for char in reversed(word):
                if char not in curr.children:
                    curr.children[char] = trie_node()
                curr = curr.children[char]
                if n < curr.min_len or (n == curr.min_len and i < curr.idx):
                    curr.min_len = n
                    curr.idx = i
        ans = []
        for query in wordsQuery:
            curr = root
            for char in reversed(query):
                if char not in curr.children:
                    break
                curr = curr.children[char]
            ans.append(curr.idx)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.stringIndices(
            wordsContainer=["abcd", "bcd", "xbcd"], wordsQuery=["cd", "bcd", "xyz"]
        )
    )
    print(
        obj.stringIndices(
            wordsContainer=["abcdefgh", "poiuygh", "ghghgh"],
            wordsQuery=["gh", "acbfgh", "acbfegh"],
        )
    )
