# 3069. Distribute Elements Into Two Arrays I

"""
you are given a 1-indexed array of distinct integers 'nums' of length 'n'.
you need to distribute all the elements of 'nums' between two arrays 'arr1'
and 'arr2' using 'n' operations. in the first operation, append 'nums[1]' to
'arr1'. in the second operation, append 'nums[2]' to 'arr2'. afterwards, in
the i'th operation, if the last element of 'arr1' is greater than the last
element of 'arr2', append 'nums[i]' to 'arr1'. otherwise, append 'nums[i]' to
'arr2'. the array 'result' is formed by concatenating the arrays 'arr1' and
'arr2'. return the array 'result'.
"""


class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr = ([nums[0]], [nums[1]])
        for i in nums[2:]:
            arr[arr[0][-1] <= arr[1][-1]].append(i)
        return arr[0] + arr[1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.resultArray(nums=[2, 1, 3]))
    print(obj.resultArray(nums=[5, 4, 3, 8]))
