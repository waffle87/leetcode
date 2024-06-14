# 1619. Mean of Array After Removing Some Elements
import statistics 

"""
givn an integer array 'arr', return the mean of the remaining integers after
removing the smallest 5% and the largest 5% of the elements. answers within
10^-5 of the actual answer will be considered accepted.
"""


class Solution(object):
    def trimMean(self, arr):
        """
        :type arr: List[int]
        :rtype: float
        """
        arr.sort()
        n = int(0.05 * len(arr))
        return statistics.mean(arr[n : len(arr) - n])


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.trimMean(arr=[1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3])
    )
    print(
        obj.trimMean(
            arr=[
                6,
                0,
                7,
                0,
                7,
                5,
                7,
                8,
                3,
                4,
                0,
                7,
                8,
                1,
                6,
                8,
                1,
                1,
                2,
                4,
                8,
                1,
                9,
                5,
                4,
                3,
                8,
                5,
                10,
                8,
                6,
                6,
                1,
                0,
                6,
                10,
                8,
                2,
                3,
                4,
            ]
        )
    )
    print(
        obj.trimMean(arr=[6, 2, 7, 5, 1, 2, 0, 3, 10, 2, 5, 0, 5, 5, 0, 8, 7, 6, 8, 0])
    )
