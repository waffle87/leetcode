# 1630. Arithmetic Subarrays

"""
a sequence of numbers is called arithmetic if it consists of at least two
elements and the difference between every two consecutive elements is the
same. more formally, a sequence 's' is arithmetic if and only if 's[i + 1] -
s[i] == s[1] - s[0]' for all valid 'i'. you are given an array of 'n'
integers 'nums' and two arrays of 'm' integers each 'l' and 'r' respectively
representingthe 'm' range queries where the i'th query isthe range '[l[i],
r[i]]'. all the arrays are 0-indexed. return a list of boolean elements 'ans'
where 'ans[i]' is true if the subarray 'nums[l[i]], nums[l[i] + 1], ...,
nums[r[i]]' can be rearrange to form an arithmetic sequence and false
otherwise
"""


class Solution(object):
    def is_arithmetic(self, nums, l, r):
        max_val, min_val = float("-inf"), float("inf")
        for i in range(l, r + 1):
            max_val = max(nums[i], max_val)
            min_val = min(nums[i], min_val)
        length = r - l + 1
        if (max_val - min_val) % (length - 1) != 0:
            return False
        diff = (max_val - min_val) // (length - 1)
        if diff == 0:
            return True
        visited = [False] * length
        for i in range(l, r + 1):
            val = nums[i]
            if (val - min_val) % diff != 0:
                return False
            else:
                pos = (val - min_val) // diff
                if visited[pos]:
                    return False
                visited[pos] = True
        return True

    def checkArithmeticSubarrays(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: List[int]
        :type r: List[int]
        :rtype: List[bool]
        """
        ans = []
        for i in range(len(l)):
            ans.append(self.is_arithmetic(nums, l[i], r[i]))
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.checkArithmeticSubarrays(nums=[4, 6, 5, 9, 3, 7], l=[0, 0, 2], r=[2, 3, 5])
    )
    print(
        obj.checkArithmeticSubarrays(
            nums=[-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10],
            l=[0, 1, 6, 4, 8, 7],
            r=[4, 4, 9, 7, 9, 10],
        )
    )
