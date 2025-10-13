# 2273. Find Resultant Array After Removing Anagrams

"""
you are given a 0-indexed string array 'words' where 'words[i]' consists of
lowercase english letters. in one operation, select any index 'i' such that
'0 < i < words.length' and 'words[i - 1]' and 'words[i]' are anagrams, and
delete 'words[i]' from 'words'. keep performing this operation as long as yu
can select an index that satisfies the conditions. return 'words' after
performining all operations. it can be shown that selecting the indices for
each operation in any arbitrary order will lead to the same result. an
anagram is a word or phrase formed by rearranging the letters of a different
word or phrase using all the original letters exactly once.
"""


class Solution(object):
    def anagram(self, s, t):
        return sorted(s) == sorted(t)

    def removeAnagrams(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        ans = []
        for i in words:
            if ans and self.anagram(ans[-1], i):
                continue
            ans.append(i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeAnagrams(words=["abba", "baba", "bbaa", "cd", "cd"]))
    print(obj.removeAnagrams(words=["a", "b", "c", "d", "e"]))
