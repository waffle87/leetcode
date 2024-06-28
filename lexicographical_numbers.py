# 386. Lexicographical Numbers

"""
given an integer 'n', return all the numbers in the range '[1, n]' sorted in
lexicographical order. you must write an algorithm that runs in O(n) time
complexity and uses O(1) extra space.
"""


class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ans = [1]
        while len(ans) < n:
            tmp = ans[-1] * 10
            while tmp > n:
                tmp /= 10
                tmp += 1
                while tmp % 10 == 0:
                    tmp /= 10
            ans.append(tmp)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.lexicalOrder(13))
    print(obj.lexicalOrder(2))
