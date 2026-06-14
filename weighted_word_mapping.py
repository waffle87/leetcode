# 3838. Weighted Word Mapping

"""
you are given an array of strings 'words', where each string represents a
word containing lowercase english letters. you are also given an integer
array 'weights' of length 26, where 'weights[i]' represents the weight of the
i'th lowercase english letter. the weight of a word is defined as the sum of
the weights of its characters. for each word, take its weight modulo 26 and
map the result to a lowercase english letter using reverse alphabetical
order. return a string formed by concatenating the mapped characters for all
words in order.
"""


class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []
        for i in words:
            total = 0
            for j in i:
                total += weights[ord(j) - ord("a")]
            ans.append(chr(ord("z") - total % 26))
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.mapWordWeights(
            words=["abcd", "def", "xyz"],
            weights=[
                5,
                3,
                12,
                14,
                1,
                2,
                3,
                2,
                10,
                6,
                6,
                9,
                7,
                8,
                7,
                10,
                8,
                9,
                6,
                9,
                9,
                8,
                3,
                7,
                7,
                2,
            ],
        )
    )
    print(
        obj.mapWordWeights(
            words=["a", "b", "c"],
            weights=[
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
                1,
            ],
        )
    )
    print(
        obj.mapWordWeights(
            words=["abcd"],
            weights=[
                7,
                5,
                3,
                4,
                3,
                5,
                4,
                9,
                4,
                2,
                2,
                7,
                10,
                2,
                5,
                10,
                6,
                1,
                2,
                2,
                4,
                1,
                3,
                4,
                4,
                5,
            ],
        )
    )
