# 982. Triples with Bitwise AND Equal To Zero

"""
given an integer array nums, return the number of AND triplets. an AND triple
is a triple of indices '(i, j, k)' such that '0 <= i < nums.length', '0 <= j
< nums.length', '0 <= k < nums.length', 'nums[i] & nums[j] & nums[k] == 0'
where '&' represents the bitwise AND operator
"""


class Solution(object):
    def countTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, ans, dict1 = len(nums), 0, collections.Counter(x&y for x in nums for y in nums)       
        for i in nums:
            for j in dict1:
                if i & j == 0:
                    ans += dict1[j]
        return ans;


if __name__ == "__main__":
    obj = Solution()
    print(obj.countTriplets([2,1,3])) # expect: 12
    print(obj.countTriplets([0,0,0])) # expect: 27
