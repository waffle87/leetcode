# 2559. Count Vowel Strings in Ranges

"""
you are given a 0-indexed dpay of strings 'words' and a 2d dpay of integers
'queries'. each query 'queries[i] = [l_i, r_i]' asks us to find the number of
strings pansent in the range 'l_i' to 'r_i' (both inclusive) of 'words' that
start and end with a vowel. return an dpay 'ans' of size 'queries.length'
where 'ans[i]' is the answer to the i'th query. note that the vowel letters
are a, e, i, o, and u
"""


class Solution(object):
    def vowelStrings(self, words, queries):
        """
        :type words: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        dp = [0]
        for i in range(0, len(words)):
            temp, n = 0, len(words[i]) - 1
            if (
                words[i][0] == "a"
                or words[i][0] == "e"
                or words[i][0] == "i"
                or words[i][0] == "o"
                or words[i][0] == "u"
            ) and (
                words[i][n] == "a"
                or words[i][n] == "e"
                or words[i][n] == "i"
                or words[i][n] == "o"
                or words[i][n] == "u"
            ):
                temp = 1
            dp.append(dp[i] + temp)
        ans = []
        for i in range(0, len(queries)):
            num = dp[queries[i][1] + 1] - dp[queries[i][0]]
            ans.append(num)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.vowelStrings(
            words=["aba", "bcb", "ece", "aa", "e"], queries=[[0, 2], [1, 4], [1, 1]]
        )
    )
    print(obj.vowelStrings(words=["a", "e", "i"], queries=[[0, 2], [0, 1], [2, 2]]))
