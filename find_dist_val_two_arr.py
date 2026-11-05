# 1385. Find the Distance Value Between Two Arrays

"""
given two integer arrays 'arr1' and 'arr2', and the integer 'd', return the
distance value between two arrays. the distance value is defined as the
number of elements 'arr1[i]' such that there is not any element 'arr2[j]'
where 'arr1[i] - arr2[j] <= d'.
"""


class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        return sum(all(abs(a - b) > d for b in arr2) for a in arr1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findTheDistanceValue(arr1=[4, 5, 8], arr2=[10, 9, 1, 8], d=2))
    print(
        obj.findTheDistanceValue(arr1=[1, 4, 2, 3], arr2=[-4, -3, 6, 10, 20, 30], d=3)
    )
    print(obj.findTheDistanceValue(arr1=[2, 1, 100, 3], arr2=[-5, -2, 10, -3, 7], d=6))
