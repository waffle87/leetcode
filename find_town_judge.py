# 997. Find the Town Judge

"""
in a town, there are 'n' people labeled from 1 to 'n'. there is a rumor that
one of these people is secretly the town judge. if the town judge exists, then:
the town judge trusts nobody. everybody (except the judge) trusts the judge.
given: array 'trust' where 'trust[i]' = [ai, bi] representing the the person
labeled ai trusts the person labeled bi. return label of judge, if they exist.
"""


class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """
        cnt = [0] * (n + 1)
        for i, j in trust:
            cnt[i] -= 1
            cnt[j] += 1
        for i in range(1, n + 1):
            if cnt[i] == n - 1:
                return i
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.findJudge(n=2, trust=[[1, 2]]))
    print(obj.findJudge(n=3, trust=[[1, 3], [2, 3]]))
    print(obj.findJudge(n=3, trust=[[1, 3], [2, 3], [3, 1]]))
