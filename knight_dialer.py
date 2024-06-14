# 935. Knight Dialer

"""
the chess knight has a unique movement, it may move two squares vertically
and one square horizontally, or two squares horizontally andone square
vertically with both forming the shape of an L. the possible movements of
chess knights ares shown in below diagram. given an integer 'n', return how
many distinct phone number of length 'n' we can dial. you are allowed to
place the knight on any numeric cell initially and then you should perform 'n
- 1' jumps to dial a number of length 'n'. all jumps should be valid jumps.
as the answer may be very large, return answer modulo 10^9 + 7
"""


class Solution(object):
    def knightDialer(self, n):
        """
        :type n: int
        :rtype: int
        """
        x1 = x2 = x3 = x4 = x5 = x6 = x7 = x8 = x9 = x0 = 1
        for i in range(n - 1):
            x1, x2, x3, x4, x5, x6, x7, x8, x9, x0 = (
                x6 + x8,
                x7 + x9,
                x4 + x8,
                x3 + x9 + x0,
                0,
                x1 + x7 + x0,
                x2 + x6,
                x1 + x3,
                x2 + x4,
                x4 + x6,
            )
        return (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x0) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.knightDialer(1))  # expect: 10
    print(obj.knightDialer(2))  # expect: 20
    print(obj.knightDialer(3131))  # expect: 136006598
