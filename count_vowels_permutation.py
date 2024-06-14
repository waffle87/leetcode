# 1220. Count Vowels Permutation


class Solution(object):
    def countVowelPermutation(self, n):
        a, e, i, o, u = 1, 1, 1, 1, 1
        for _ in range(n - 1):
            a, e, i, o, u = e + i + u, a + i, e + o, i, i + o
        return (a + e + i + o + u) % (10**9 + 7)


if __name__ == "__main__":
    obj = Solution()
    print(obj.countVowelPermutation(1))  # expect: 5
    print(obj.countVowelPermutation(2))  # expect: 10
    print(obj.countVowelPermutation(5))  # expect: 68
