# 1652. Defuse the Bomb

"""
you have a bomb to defuse, and your time is running out. your informer will
provide you with a circular array 'code' of length 'n' and key 'k'. to
decrypt the code, you must replace every number. all the numbers are replace
simultaneously. if 'k > 0', replace the i'th number with the sum of the next
'k' numbers. if 'k < 0', replace the i'th number with the sum of the previous
'k' numbers. if 'k == 0', replace the i'th number with 0. as 'code' is
circular, the next element of 'code[n - 1]' is 'code[0]' and the previous
element of 'code[0]' is 'code[n - 1]'. given the circular array 'code' and an
integer 'k', return the decrypted code to defuse the bomb
"""


class Solution(object):
    def decrypt(self, code, k):
        """
        :type code: List[int]
        :type k: int
        :rtype: List[int]
        """
        if k == 0:
            return [0 for i in code]
        ans, code = code, code * 2
        for i in range(len(ans)):
            if k > 0:
                ans[i] = sum(code[i + 1 : i + k + 1])
            else:
                ans[i] = sum(code[i + len(ans) + k : i + len(ans)])
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.decrypt(code=[5, 7, 1, 4], k=3))
    print(obj.decrypt(code=[1, 2, 3, 4], k=0))
    print(obj.decrypt(code=[2, 4, 9, 3], k=-2))
