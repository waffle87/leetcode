# 1122. Relative Sort Array

"""
given two arrays 'arr1' and 'arr2', the elements of 'arr2' are distinct and
all elements in 'arr2' are also in 'arr1'. sort the elements of 'arr1' such
that the relative ordering of items in 'arr1' are the same as in 'arr2'.
elements that do not appear in 'arr2' should be placed at the end of 'arr1'
in ascending order.
"""
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        return sorted(arr1, key=(arr2 + sorted(arr1)).index)
        
if __name__ == "__main__":
    obj = Solution()
    print(obj.relativeSortArray(arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]))
    print(obj.relativeSortArray(arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]))
