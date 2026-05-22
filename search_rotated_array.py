# 33. Search in Rotated Sorted Array

"""
there is an integer array 'nums' sorted in ascending order (with distinct
values). prior to being passed to your function, 'nums' is possibly rotated
at an unknown pivot index 'k(1 <= k < nums.length)' such tht the resulting
array is '[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ...,
nums[k - 1]]' (0-indxed). for example, '[0,1,2,4,5,6,7]' might be rotated at
pivot index 3 and become '[4,5,6,7,0,1,2]'. given the array 'nums' after the
possible rotation and an integer 'target', return the index of 'target' if it
is in 'nums', or -1 otherwise. you must write an algorithm with 'O(log n)'
runtime complexity
"""


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums) - 1
        while low < high:
            mid = (low + high) // 2
            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid
        rot = low
        low = 0
        high = len(nums) - 1
        while low <= high:
            mid = (low + high) // 2
            real_mid = (mid + rot) % len(nums)
            if nums[real_mid] == target:
                return real_mid
            if nums[real_mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.search(nums=[4, 5, 6, 7, 0, 1, 2], target=0))
    print(obj.search(nums=[4, 5, 6, 7, 0, 1, 2], target=3))
    print(obj.search(nums=[1], target=0))
