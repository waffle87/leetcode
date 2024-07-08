# 1823. Find the Winner of the Circular Game

"""
there are 'n' friends that are playing a game. the friends are sitting in a
circule and are numbered from 1 to 'n' in clockwise order. more formally,
moving clockwise from the i'th friend brings you to the '(i + 1)'th friend
for '1 <= i < n', and moving clockwise from the n'th friend brings you to the
1st friend. given the number of friends, 'n' and an integer 'k', return the
winner of the game.
"""


class Solution(object):
    def findTheWinner(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        ans = 0
        for i in range(1, n + 1):
            ans = (ans + k) % i
        return ans + 1


if __name__ == "__main__":
    obj = Solution()
    print(obj.findTheWinner(5, 2))
    print(obj.findTheWinner(6, 5))
