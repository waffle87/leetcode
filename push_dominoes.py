# 838. Push Dominoes

"""
there are 'n' dominoes in a line, and we place each domino vertically
upright. in the beginning, we simultaneously push some of the dominoes either
to the left or to the right. after each second, each domino that is falling
to the left pushes the adjacent domino on the left. similarly, the dominoes
falling to the right push their adjacent dominoes standing on the right. when
a vertical domino has dominoes falling on it from both sides, it stays still
due to the balance of the forces. for the purpose of this question, we will
consider that a falling domino expends no additional force to a falling or
already fallen domino.
"""


class Solution(object):
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        while "R." in dominoes or ".L" in dominoes:
            dominoes = (
                dominoes.replace("R.L", "xxx").replace(".L", "LL").replace("R.", "RR")
            )
        return dominoes.replace("xxx", "R.L")


if __name__ == "__main__":
    obj = Solution()
    print(obj.pushDominoes(dominoes="RR.L"))
    print(obj.pushDominoes(dominoes=".L.R...LR..L.."))
