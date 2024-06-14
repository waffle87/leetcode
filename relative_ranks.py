# 506. Relative Ranks

"""
given an integer array score of size 'n' where 'score[i]' is the score of the
i'th athlete in a competition. all the scores are guaranteed to be unique.
the athletes are placed based on their scores where the first place athlete
has the highest score, the second place athlet has the second highest score,
and so on. return an array 'ans' of size 'n' where 'ans[i]' is the rank of
the i'th athlete.
"""


class Solution(object):
    def findRelativeRanks(self, score):
        """
        :type score: List[int]
        :rtype: List[str]
        """
        sort = sorted(score)[::-1]
        rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + map(
            str, range(4, len(score) + 1)
        )
        return map(dict(zip(sort, rank)).get, score)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findRelativeRanks(score=[5, 4, 3, 2, 1]))
    print(obj.findRelativeRanks(score=[10, 3, 8, 9, 4]))
