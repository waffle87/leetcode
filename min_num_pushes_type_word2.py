# 3016. Minimum Number of Pushes to Type Word II

"""
you are given a string 'word' containing lowercase english letters. telephone
keypads have keys mapped with distinct collections of lowercase english
letters, which can be used to form words by pushing them. for example, the
key 2 is mapped with [a, b, c], we need to push the key one time to type 'a',
two times to type 'b', and three times to type 'c'. it is allowed to remap
the keys numbered 2 to 9 to distinct collections of letters. the keys can be
remapped to any amount of letters, but each letter must be mapped to exactly
one key. you need to find the minimum number of times the keys will be pushed
to type the string 'word'. return the minimum number of pushes needed to type
'word' after remapping the keys.
"""


class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt, ans = [0] * 26, 0
        for i in word:
            cnt[ord(i) - ord("a")] += 1
        cnt.sort(reverse=True)
        for i in range(26):
            ans += cnt[i] * (i // 8 + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumPushes(word="abcde"))
    print(obj.minimumPushes(word="xyzxyzxyzxyz"))
    print(obj.minimumPushes(word="aabbccddeeffgghhiiiiii"))
