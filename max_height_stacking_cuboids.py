# 1691. Maximum Height by Stacking Cuboids

"""
given 'n' cuboids where the dimensions of the i'th cuboid is 'cuboids[i] =
[width_i, length_i, height_i]' (0-indexed). choosee a subset of 'cuboids' and
place them on each other. you can place cuboid 'i' on cuboid 'j' if 'width_i
<= width_j', and similarily for length and height. you can rearrange any
cuboid's dimensions by rotating it to put it on another cuboid. return the
maximum height of the stacked 'cuboids'.
"""


class Solution(object):
    def maxHeight(self, cuboids):
        """
        :type cuboids: List[List[int]]
        :rtype: int
        """
        cuboids = [[0, 0, 0]] + sorted(map(sorted, cuboids))
        dp = [0] * len(cuboids)
        for i in range(1, len(cuboids)):
            for j in range(i):
                if all(cuboids[j][k] <= cuboids[i][k] for k in range(3)):
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2])
        return max(dp)


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxHeight(cuboids=[[50, 45, 20], [95, 37, 53], [45, 23, 12]]))
    print(obj.maxHeight(cuboids=[[38, 25, 45], [76, 35, 3]]))
    print(
        obj.maxHeight(
            cuboids=[
                [7, 11, 17],
                [7, 17, 11],
                [11, 7, 17],
                [11, 17, 7],
                [17, 7, 11],
                [17, 11, 7],
            ]
        )
    )
