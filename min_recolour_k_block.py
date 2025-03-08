# 2379. Minimum Recolors to Get K Consecutive Black Blocks

"""
you are given a 0-indexed string 'blocks' of length 'n' where 'blocks[i]' is
either 'W' or 'B', representing the colour of the i'th block. the characters
'W' and 'B' denote the colours white and black, respectively. you are also
given an integer 'k', which is the desired number of consecutive black
blocks. in one operation, you can recolour a white block such that it becomes
a black block. return the minimum number of operations needed such that there
is at least one occurence of 'k' consecutive black blocks.
"""


class Solution(object):
    def minimumRecolors(self, blocks, k):
        """
        :type blocks: str
        :type k: int
        :rtype: int
        """
        n, min_op, flips, cnt, i = len(blocks), float("inf"), 0, 0, 0
        for j in range(n):
            if blocks[j] == "W":
                flips += 1
                cnt += 1
            elif blocks[j] == "B":
                cnt += 1
            if cnt == k:
                min_op = min(min_op, flips)
                if blocks[i] == "W":
                    flips -= 1
                    cnt -= 1
                else:
                    cnt -= 1
                i += 1
        return min_op


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumRecolors(blocks="WBBWWBBWBW", k=7))
    print(obj.minimumRecolors(blocks="WBWBBBW", k=2))
