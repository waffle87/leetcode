# 1255. Maximum Score Words Formed by Letters

"""
given a list of 'words' list of single 'letters' (potentially repeating), and
'score' of every character. return the maximum score of any valid set of
words formed by using the given letters ('words[i]' cannot be used two or
more times). it is not necessary to use all characters in 'letters' and each
letter can only be used once. score of letters a through z is given by
'score[i]' respectively.
"""


class Solution(object):
    def maxScoreWords(self, words, letters, score):
        """
        :type words: List[str]
        :type letters: List[str]
        :type score: List[int]
        :rtype: int
        """
        cnt = [0] * 26
        letters_cnt = [0] * 26
        for c in letters:
            cnt[ord(c) - ord("a")] += 1
        self.ans = 0
        self.backtracking(words, score, cnt, letters_cnt, 0, 0)
        return self.ans

    def backtracking(self, words, score, cnt, letters_cnt, pos, tmp):
        for i in range(26):
            if letters_cnt[i] > cnt[i]:
                return
        self.ans = max(self.ans, tmp)
        for i in range(pos, len(words)):
            for c in words[i]:
                letters_cnt[ord(c) - ord("a")] += 1
                tmp += score[ord(c) - ord("a")]
            self.backtracking(words, score, cnt, letters_cnt, i + 1, tmp)
            for c in words[i]:
                letters_cnt[ord(c) - ord("a")] -= 1
                tmp -= score[ord(c) - ord("a")]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.maxScoreWords(
            words=["dog", "cat", "dad", "good"],
            letters=["a", "a", "c", "d", "d", "d", "g", "o", "o"],
            score=[
                1,
                0,
                9,
                5,
                0,
                0,
                3,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                2,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
            ],
        )
    )
    print(
        obj.maxScoreWords(
            words=["xxxz", "ax", "bx", "cx"],
            letters=["z", "a", "b", "c", "x", "x", "x"],
            score=[
                4,
                4,
                4,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                5,
                0,
                10,
            ],
        )
    )
    print(
        obj.maxScoreWords(
            words=["leetcode"],
            letters=["l", "e", "t", "c", "o", "d"],
            score=[
                0,
                0,
                1,
                1,
                1,
                0,
                0,
                0,
                0,
                0,
                0,
                1,
                0,
                0,
                1,
                0,
                0,
                0,
                0,
                1,
                0,
                0,
                0,
                0,
                0,
                0,
            ],
        )
    )
