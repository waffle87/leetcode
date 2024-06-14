# 2433. Find The Original Array of Prefix Xor

"""
given an integer array 'pref' of size 'n'. find and return the array 'arr' of
size 'n' that satisfies 'pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]'. note that
'^' denotes the bitwise xor operator. it can be proven that the answer is
unique
"""

class Solution(object):
    def findArray(self, pref):
        for i in range(len(pref) - 1, 0, -1):
            pref[i] ^= pref[i - 1]
        return pref


if __name__ == "__main__":
    obj = Solution()
    print(obj.findArray([5,2,0,3,1])) # expect: 5 7 2 3 2
    print(obj.findArray([13])) # expect: 13
