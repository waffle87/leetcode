# 2610. Convert an Array Into a 2D Array With Conditions

"""
given an integer array 'nums', you should create a 2d array from 'nums'
satisfying the following conditions. the 2d array should contain only the
elements of the array 'nums'. each row in the 2d array contains distinct
integers. the number of rows in the 2d array should be minimal. return the
resulting array. if there are multiple answers, return any of them. note that
the 2d array can have a different number of elements on each row.
"""

class Solution(object):
    def findMatrix(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        um = {}
        ans = []
        for i in nums:
            um[i] = um.get(i, 0) + 1
        while um:
            tmp = []
            to_erase = []
            for f, s in um.items():
                tmp.append(f)
                s -= 1
                if s == 0:
                    to_erase.append(f)
                um[f] = s
            ans.append(tmp)
            for i in to_erase:
                del um[i]
        return ans

if __name__ == "__main__":
    obj = Solution()
    print(obj.findMatrix(nums = [1,3,4,1,2,3,1])) # expect: [[1,3,4,2],[1,3],[1]]
    print(obj.findMatrix(nums = [1,2,3,4])) # expect: [[4,3,2,1]]
