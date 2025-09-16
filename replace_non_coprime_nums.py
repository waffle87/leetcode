# 2197. Replace Non-Coprime Numbers in Array
from math import gcd

"""
you are given an array of integers 'nums'. perform the following steps: find
any two adjacent numbers in 'nums' that are non-coprime, if no such numbers
are found, stop the process. otherwise, delete the two numbers and replace
them with their lcm. repeat this process as long as you keep finding two
adjacent non-coprime integers. return the final modified array. it can be
shown that replacing adjacent non-coprime numbers in any arbitrary order will
lead to the same result. two values 'x' and '' aree non-coprime if 'gcd(x, y)
> 1' where 'gcd(x, y)' is the greatest common denomiator
"""


class Solution(object):
    def replaceNonCoprimes(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for i in nums:
            while ans:
                g = gcd(ans[-1], i)
                if g == 1:
                    break
                i = (ans.pop() * i) // g
            ans.append(i)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.replaceNonCoprimes(nums=[6, 4, 3, 2, 7, 6, 2]))
    print(obj.replaceNonCoprimes(nums=[2, 2, 1, 1, 3, 3, 3]))
