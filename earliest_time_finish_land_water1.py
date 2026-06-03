# 3633. Earliest Finish Time for Land and Water Rides I
from typing import List

"""
you are given two categories of theme park attractions. land rides and water
rides. a tourist must experience exactly one ride from each category. return
the earliest possible time at which the tourist can finish both rides.
"""


class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        def solve(start1, duration1, start2, duration2):
            finish1, finish2 = float("inf"), float("inf")
            for i in range(len(start1)):
                finish1 = min(finish1, start1[i] + duration1[i])
            for i in range(len(start2)):
                finish2 = min(finish2, max(start2[i], finish1) + duration2[i])
            return finish2

        land_water = solve(landStartTime, landDuration, waterStartTime, waterDuration)
        water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration)
        return min(land_water, water_land)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.earliestFinishTime(
            landStartTime=[2, 8],
            landDuration=[4, 1],
            waterStartTime=[6],
            waterDuration=[3],
        )
    )
    print(
        obj.earliestFinishTime(
            landStartTime=[5], landDuration=[3], waterStartTime=[1], waterDuration=[10]
        )
    )
