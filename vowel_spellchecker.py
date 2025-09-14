# 966. Vowel Spellchecker

"""
given a 'wordlist', we want to implement a spellchecker that converts a query
word into a correct word. for a given 'query', the spell checker handles two
categories of spelling mistakes: capitalisation and vowel errors. given some
'queries', return a list of words 'answer' where 'answer[i]' is the correct
word for 'query = queries[i]'
"""


class Solution(object):
    def spellchecker(self, wordlist, queries):
        """
        :type wordlist: List[str]
        :type queries: List[str]
        :rtype: List[str]
        """

        def mask(s):
            return "".join("*" if c in "aeiou" else c for c in s.lower())

        hash1 = set(wordlist)
        hash2 = {s.lower(): s for s in wordlist[::-1]}
        hash3 = {mask(s): s for s in wordlist[::-1]}

        def solve(query):
            if query in hash1:
                return query
            if query.lower() in hash2:
                return hash2[query.lower()]
            if mask(query) in hash3:
                return hash3[mask(query)]
            return ""

        return [solve(q) for q in queries]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.spellchecker(
            wordlist=["KiTe", "kite", "hare", "Hare"],
            queries=[
                "kite",
                "Kite",
                "KiTe",
                "Hare",
                "HARE",
                "Hear",
                "hear",
                "keti",
                "keet",
                "keto",
            ],
        )
    )
    print(obj.spellchecker(wordlist=["yellow"], queries=["YellOw"]))
