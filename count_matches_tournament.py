# 1688. Count of Matches in Tournament

"""
given an integer 'n', the number of teams in a tournament that has strange
rules: if the current number of teams is even, each team get paired with
another team. a total of 'n / 2' matches are played, and 'n / 2' teams
advance to the next round. if the current number of teams is odd, one team
randomly advances in the tournament and the rest gets paired. a total of '(n
- 1) / 2' matches are played, and '(n - 1) / 2 + 1' teams advance to the next
round. return the number of matches played in the tournament until a winner
is decided
"""


class Solution(object):
    def numberOfMatches(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 0
        while n > 1:
            ans += n // 2
            n = (n + 1) // 2
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfMatches(7))  # expect: 6
    print(obj.numberOfMatches(14))  # expect: 13
    print(obj.numberOfMatches(672))  # expect: 671
