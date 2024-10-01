# 1170. Compare Strings by Frequency of the Smallest Character

"""
let the function 'f(s)' be the frequency of the lexicographically smallest
character in a non empty string 's'. for example, if 's = dcce' then 'f(s) =
2' because the lexicographically smallest character is 'c', which has a
frequency of 2. you are given an array of strings 'words' and another array
of query strings 'queries'. for each query 'queries[i]', count the number of
words in 'words' such that 'f(queries[i]) < f(w)' for each 'w' in 'words'.
return an integer array 'answer' where each 'answer[i]' is the answer to the
i'th query
"""


class Solution(object):
    def f(self, s):
        t = sorted(list(s))[0]
        return s.count(t)

    def numSmallerByFrequency(self, queries, words):
        """
        :type queries: List[str]
        :type words: List[str]
        :rtype: List[int]
        """
        query = [self.f(i) for i in queries]
        word = [self.f(i) for i in words]
        map = []
        for i in query:
            cnt = 0
            for j in word:
                if j > i:
                    cnt += 1
            map.append(cnt)
        return map


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSmallerByFrequency(queries=["cbd"], words=["zaaaz"]))
    print(
        obj.numSmallerByFrequency(
            queries=["bbb", "cc"], words=["a", "aa", "aaa", "aaaa"]
        )
    )
