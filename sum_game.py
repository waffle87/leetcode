# 1927. Sum Game

"""
alice and bob take turns playing a game, with alice starting first. you are
given a string 'num' of even length consisting of digits and '?' characters.
on each turn, a player will do the following if there is still at least one
'?' in 'num': choose an index 'i' where 'num[i] == ?', replace 'num[i]' with
any digit between 0 and 9. the game ends when there are no more '?'
characters in 'num'. for bob to win, the sum of the digits in the first half
of 'num' must be equal to the sum of the digits in the second half. for alice
to win, the sums must not be equal. assuming both play optimally, return true
if alice will and false if bob will win.
"""


class Solution:
    def sumGame(self, num: str) -> bool:
        s, q = [0, 0], [0, 0]
        n = len(num)
        for i in range(n):
            j = i // (n // 2)
            if num[i] == "?":
                q[j] += 1
            else:
                s[j] += int(num[i])
        return (q[0] + q[1]) & 1 == 1 or (s[0] - s[1]) != (q[1] - q[0]) * 4.5


if __name__ == "__main__":
    obj = Solution()
    print(obj.sumGame(num="5023"))
    print(obj.sumGame(num="25??"))
    print(obj.sumGame(num="?3295???"))
