# 2029. Stone Game IX

"""
alice and bob continue their games with stones. there is a row of 'n' stones,
and each stone has an associated value. you are given an integer array
'stones', where 'stones[i]' is the value of the i'th stone. alice and bob
take turns, with alice starting first. on each turn, the player may remove
any stone from 'stones'. the player who removes a stone loses if the sum of
the values of all removed stones is divisble by 3. bob will win automatically
if there are no  remaining stones (even if it is alice's turn). assuming both
players play optimally, return true if alice wins and false if bob wins.
"""


class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        freq = [0] * 3
        for i in stones:
            freq[i % 3] += 1
        if ~freq[0] & 1:
            return min(freq[1], freq[2]) >= 1
        return abs(freq[1] - freq[2]) >= 3


if __name__ == "__main__":
    obj = Solution()
    print(obj.stoneGameIX(stones=[2, 1]))
    print(obj.stoneGameIX(stones=[2]))
    print(obj.stoneGameIX(stones=[5, 1, 2, 4, 3]))
