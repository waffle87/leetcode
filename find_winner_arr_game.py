# 1535. Find the Winner of an Array Game

"""
given an integer array 'arr' of distinct integers and an integer 'k', a game
will be played between the first two elements of the array (ie. 'arr[0]' and
'arr[1]'). in eah round of the game, we compare 'arr[0]' with 'arr[1]', the
larger integer wins and remains at position 0, and the smaller integer moves
to the end of the array. the game ends when an integer wins 'k' consecutive
rounds. return the integer which will win the game. it is guaranteed that
there will be a winner of the game.
"""


class Solution(object):
    def getWinner(self, arr, k):
        curr = arr[0]
        win = 0
        for i in range(1, len(arr)):
            if arr[i] > curr:
                curr = arr[i]
                win = 0
            win += 1
            if win == k:
                break
        return curr


if __name__ == "__main__":
    obj = Solution()
    print(obj.getWinner([2, 1, 3, 5, 4, 6, 7], 2))  # expect: 5
    print(obj.getWinner([3, 2, 1], 2))  # expect: 3
