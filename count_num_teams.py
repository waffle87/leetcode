# 1395. Count Number of Teams

"""
there are 'n' soldiers standing in a line. each soldier is assigned a unique
'rating' value. you have to form a team of 3 soldiers amongst them under the
following rules
- choose 3 soldiers with index '(i, j, k)' with rating '(rating[i],
rating[j], rating[k])'
- a team is valid if '(rating[i] < rating[j] < rating[k])' or '(rating[i] >
rating[j] > rating[k])' where '(0 <= i < j < k < n))' return the number of
teams you can form given the conditions (soldiers can be part of multiple
teams)
"""


class Solution(object):
    def numTeams(self, rating):
        """
        :type rating: List[int]
        :rtype: int
        """
        asc, dsc = 0, 0
        for i, v in enumerate(rating):
            llc, rgc, lgc, rlc = 0, 0, 0, 0
            for l in rating[:i]:
                if l < v:
                    llc += 1
                if l > v:
                    lgc += 1
            for r in rating[i + 1 :]:
                if r > v:
                    rgc += 1
                if r < v:
                    rlc += 1
            asc += llc * rgc
            dsc += lgc * rlc
        return asc + dsc


if __name__ == "__main__":
    obj = Solution()
    print(obj.numTeams(rating=[2, 5, 3, 4, 1]))
    print(obj.numTeams(rating=[2, 1, 3]))
    print(obj.numTeams(rating=[1, 2, 3, 4]))
