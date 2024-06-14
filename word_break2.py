# 140. Word Break II

"""
given a string 's' and a dictionary of strings 'wordDict', add spaces in 's'
to construct a sentence where each word is a valid dictionary word. return
all such possible sentences in any order. note that the same word in the
dictionary may be reused mutliple times in the segmentation.
"""


class Solution(object):
    def dfs(self, s, wordDict, memo):
        if s in memo:
            return memo[s]
        if not s:
            return []
        res = []
        for word in wordDict:
            if not s.startswith(word):
                continue
            if len(word) == len(s):
                res.append(word)
            else:
                res_rest = self.dfs(s[len(word) :], wordDict, memo)
                for item in res_rest:
                    item = word + " " + item
                    res.append(item)
        memo[s] = res
        return res

    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        return self.dfs(s, wordDict, {})


if __name__ == "__main__":
    obj = Solution()
    print(obj.wordBreak(s="catsanddog", wordDict=["cat", "cats", "and", "sand", "dog"]))
    print(
        obj.wordBreak(
            s="pineapplepenapple",
            wordDict=["apple", "pen", "applepen", "pine", "pineapple"],
        )
    )
    print(obj.wordBreak(s="catsandog", wordDict=["cats", "dog", "sand", "and", "cat"]))
