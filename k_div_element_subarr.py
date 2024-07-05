# 2261. K Divisible Elements Subarrays

"""
given an integer array 'nums' and two integers 'k' and 'p', return the number
of distinct subarrays which have at most 'k' elements that are divisible by
'p'. two arrays 'nums1' and 'nums2' ae said to be distinct if they are of
different lengths of there exists at least one index 'i' where 'nums1[i] !=
nums2[i]'. a subarray is defined as a non empty contiguous sequence of
elements in an array
"""


class Solution(object):
    def countDistinct(self, nums, k, p):
        """
        :type nums: List[int]
        :type k: int
        :type p: int
        :rtype: int
        """
        n, sub_arr = len(nums), set()
        for i in range(n):
            cnt, tmp = 0, ""
            for j in range(i, n):
                if nums[j] % p == 0:
                    cnt += 1
                tmp += str(nums[i])
                if cnt > k:
                    break
                sub_arr.add(tmp)
        return len(sub_arr)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countDistinct(nums=[2, 3, 3, 2, 2], k=2, p=2))
    print(obj.countDistinct(nums=[1, 2, 3, 4], k=4, p=1))
