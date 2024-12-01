# 1346. Check If N and Its Double Exist

"""
given an array 'arr' of integers, check if there exists two indices 'i' and
'j' such that 'i != j', '0 <= i, j < arr.length', and 'arr[i] == 2 * arr[j]'
"""


class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        seen = set()
        for i in arr:
            if 2 * i in seen or i / 2 in seen:
                return True
            seen.add(i)
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.checkIfExist(arr=[10, 2, 5, 3]))
    print(obj.checkIfExist(arr=[3, 1, 7, 11]))
