# 1668. Maximum Repeating Substring

"""
for a string 'sequence', a string 'word' is 'k'-repeating if 'word'
concatenated 'k' times is a substring of 'sequence'. the 'word's maximum
'k'-repeating value is the highest value 'k' where 'word' is 'k'-repeating in
'sequence'. if 'word' is not a substring of 'sequence', 'word's maximum
'k'-repeating value is 0. given strings 'sequence' and 'word', return the
maximum 'k'-repeating value of 'word' in 'sequence'.
"""


class Solution(object):
    def maxRepeating(self, sequence, word):
        """
        :type sequence: str
        :type word: str
        :rtype: int
        """
        n, m = len(sequence), len(word)
        max_repeat = n
        failure = [0] * (m * max_repeat + 1)
        repeat_words = word * max_repeat + "$"
        ans, j = 0, 0
        for i in range(1, len(repeat_words)):
            while j > 0 and repeat_words[j] != repeat_words[i]:
                j = failure[j - 1]
            j += repeat_words[j] == repeat_words[i]
            failure[i] = j
        j = 0
        for i, c in enumerate(sequence):
            while j > 0 and repeat_words[j] != c:
                j = failure[j - 1]
            j += repeat_words[j] == c
            ans = max(ans, j // m)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maxRepeating("ababc", "ab"))  # expect: 2
    print(obj.maxRepeating("ababc", "ba"))  # expect: 1
    print(obj.maxRepeating("ababc", "ac"))  # expect: 0
