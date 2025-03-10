# 3306. Count of Substrings Containing Every Vowel and K Consonants II

"""
you are given a string 'word' and a non-negative integer 'k'. return the
total number of substrings of 'word' that contain every vowel at least once
and exactly 'k' constants
"""


class Solution(object):
    def countOfSubstrings(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        freq = [{}, {}]
        for v in "aeiou":
            freq[0][v] = 1
        ans, curr, cnt, extra, left = 0, 0, 0, 0, 0
        for right, r_char in enumerate(word):
            if r_char in freq[0]:
                freq[1][r_char] = freq[1].get(r_char, 0) + 1
                if freq[1][r_char] == 1:
                    cnt += 1
            else:
                curr += 1
            while curr > k:
                l_char = word[left]
                if l_char in freq[0]:
                    freq[1][l_char] -= 1
                    if freq[1][l_char] == 0:
                        cnt -= 1
                else:
                    curr -= 1
                left += 1
                extra = 0
            while (
                cnt == 5
                and curr == k
                and left < right
                and word[left] in freq[0]
                and freq[1][word[left]] > 1
            ):
                extra += 1
                freq[1][word[left]] -= 1
                left += 1
            if curr == k and cnt == 5:
                ans += extra + 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.countOfSubstrings(word="aeioqq", k=1))
    print(obj.countOfSubstrings(word="aeiou", k=0))
    print(obj.countOfSubstrings(word="ieaouqqieaouqq", k=1))
