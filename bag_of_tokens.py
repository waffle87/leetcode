# 948. Bag of Tokens

"""
you have an initial power of 'power', an initial score of 0, and a bag of
'tokens' where 'tokens[i]' is the value of the i'th token (0-indexed). your
goal is to maximise your total score by potentially playing each token in one
of two ways: -if your current power is at least 'tokens[i]', you may play the
i'th token face up, losing 'tokens[i]' power and gaining one score
- if your current score is at least one, you may play the i'th token face
down, gaining 'tokens[i]' power and losing score 1 each token may be played
at most once and in any order. you do not have to play all the tokens. return
the largest possible score you can achieve after playing any number of token.
"""


class Solution(object):
    def bagOfTokensScore(self, tokens, power):
        """
        :type tokens: List[int]
        :type power: int
        :rtype: int
        """
        tokens.sort()
        s, ans, l, r = 0, 0, 0, len(tokens) - 1
        while l <= r:
            if power >= tokens[l]:
                power -= tokens[l]
                s += 1
                l += 1
                ans = max(ans, s)
            elif s > 0:
                power += tokens[r]
                s -= 1
                r -= 1
            else:
                break
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.bagOfTokensScore(tokens=[100], power=50))  # expect: 0
    print(obj.bagOfTokensScore(tokens=[200, 100], power=150))  # expect: 1
    print(obj.bagOfTokensScore(tokens=[100, 200, 300, 400], power=200))  # expect: 2
