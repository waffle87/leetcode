# 2833. Furthest Point From Origin

"""
you are given a string 'moves' of length 'n' consisting only of characters L
R and _. the string represents your movement on a number line starting from
the origin. in the i'th move, you can choose one of the following directions:
move to the left if 'moves[i] = L' or 'moves[i] = _', and move to the right
'moves[i] = R' or 'moves[i] = _'. return the distance from the origin of the
furthest point you can get to after 'n' moves.
"""


class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        return abs(sum((c == "R") - (c == "L") for c in moves)) + moves.count("_")


if __name__ == "__main__":
    obj = Solution()
    print(obj.furthestDistanceFromOrigin(moves="L_RL__R"))
    print(obj.furthestDistanceFromOrigin(moves="_R__LL_"))
    print(obj.furthestDistanceFromOrigin(moves="_______"))
