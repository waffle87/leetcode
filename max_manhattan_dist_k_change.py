# 3443. Maximum Manhattan Distance After K Changes

"""
you are given a sing 's' consisting of the characters 'N', 'S', 'E', and
'W', where 's[i]' indicates movements in an infinite grid, where each letter
is a move of 1 unit in that cardinal direction. initially, you are at the
origin '(0, 0)'. you can change at most 'k' characters to any of the four
directions. find the maximum manhattan distance from the origin that can be
achieved at any time while performing the movements in order.
"""


class Solution(object):
    def maxDistance(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        ans = 0
        for i in [{"N", "E"}, {"N", "W"}, {"S", "E"}, {"S", "W"}]:
            curr_dist, curr_k = 0, k
            for j in s:
                curr_dist += 1
                curr_k -= j not in i
            else:
                curr_dist -= 1
            ans = max(ans, curr_dist)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxDistance(s="NWSE", k=1))
    print(obj.maxDistance(s="NSWWEW", k=3))
