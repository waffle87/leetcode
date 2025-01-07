# 1408. String Matching in an Array

"""
given an array of string 'words', return all the strings in 'words' that is a
substring of another word. you can return the answer in any order. a
substring is a contiguous sequence of characters within a string.
"""


class Solution(object):
    def stringMatching(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        n, ans = len(words), []
        for i in range(n):
            for j in range(n):
                if i != j:
                    if words[j] in words[i]:
                        ans.append(words[j])
        return list(set(ans))


if __name__ == "__main__":
    obj = Solution()
    print(obj.stringMatching(words=["mass", "as", "hero", "superhero"]))
    print(obj.stringMatching(words=["leetcode", "et", "code"]))
    print(obj.stringMatching(words=["blue", "green", "bu"]))
