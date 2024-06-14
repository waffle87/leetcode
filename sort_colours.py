# 75. Sort Colors

"""
given an array 'nums' with 'n' objects coloured red, white, or blue, sort
them in place so that objects of the same colour are adjacent with the
colours in the order red, white and blue. we will use the integer 0,1,2 to
represent the colour red, white, and blue respecitvely. you must solve this
problem without the library's sort function.
"""


class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        red, white, blue = 0, 0, len(nums) - 1

        while white <= blue:
            if nums[white] == 0:
                nums[red], nums[white] = nums[white], nums[red]
                white += 1
                red += 1
            elif nums[white] == 1:
                white += 1
            else:
                nums[white], nums[blue] = nums[blue], nums[white]
                blue -= 1


if __name__ == "__main__":
    obj = Solution()
    n1 = [2, 0, 2, 1, 1, 0]
    n2 = [2, 0, 1]
    obj.sortColors(n1)
    obj.sortColors(n2)
    print(n1)
    print(n2)
