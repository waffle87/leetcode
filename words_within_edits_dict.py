# 2452. Words Within Two Edits of Dictionary

"""
you are given two string arrays 'queries' and 'dictionary'. all words in each
array comprise of lowercase english letters and have the same length. in one
edit, you can take a word from 'queries' and change any letter in it to any
other letter. find all words from 'queries' that, after a maximum of two
edits, equal some word from 'dictionary'. return a list of all words from
'queries' that match with some word from 'dictionary' after a maximum of two
edits. return the words in the same order that they appear in 'queries'.
"""


class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans, n = [], len(queries[0])
        for q in queries:
            for d in dictionary:
                diff = 0
                for j in range(n):
                    if q[j] != d[j]:
                        diff += 1
                    if diff > 2:
                        break
                if diff <= 2:
                    ans.append(q)
                    break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.twoEditWords(
            queries=["word", "note", "ants", "wood"],
            dictionary=["wood", "joke", "moat"],
        )
    )
    print(obj.twoEditWords(queries=["yes"], dictionary=["not"]))
