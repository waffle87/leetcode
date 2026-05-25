# 1871. Jump Game VII

"""
you are given a 0-indexed binary string 's' and two integers 'minJump' and
'maxJump'. in the beginning, you are standing at index '0', which is equal to
0. you can move from index 'i' to index 'j' if the following conditions are
fulfilled: 'i + minJump <= j <= min(i + maxJump, s.length - 1)' and 's[j] ==
0'. return true if you can reach index 's.length - 1' in 's' or false
otherwise.
"""

from collections import deque


class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        q, total = deque([0]), 0
        while q:
            i = q.popleft()
            for j in range(max(i + minJump, total + 1), min(i + maxJump + 1, len(s))):
                if s[j] == "0":
                    if j == len(s) - 1:
                        return True
                    q.append(j)
            total = max(total, i + maxJump)
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.canReach(s="011010", minJump=2, maxJump=3))
    print(obj.canReach(s="01101110", minJump=2, maxJump=3))
