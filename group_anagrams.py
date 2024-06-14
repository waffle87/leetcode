# 49. Group Anagrams
from collections import defaultdict

"""
given an array of strings 'strs', group the anagrams together . you can
return the answer in any order. an anagram is a word or phrase formed by
rearranging the letters of a different word or phrase, typically using all
the original letters exactly once.
"""


class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        anagram_map = defaultdict(list)
        for word in strs:
            sorted_word = "".join(sorted(word))
            anagram_map[sorted_word].append(word)
        return list(anagram_map.values())


if __name__ == "__main__":
    obj = Solution()
    print(obj.groupAnagrams(strs=["eat", "tea", "tan", "ate", "nat", "bat"]))
    print(obj.groupAnagrams(strs=[""]))
    print(obj.groupAnagrams(strs=["a"]))
