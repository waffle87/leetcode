# 564. Find the Closest Palindrome

"""
given a string 'n' representing an integer, return the closest integer (not
including itself), which is a palindrome. if there is a tie, return the
smaller one. the closest is defined as the absolute difference minimised
between two integers.
"""


class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        if int(n) <= 10 or (int(n) % 10 == 0 and int(n[1:]) == 0):
            return str(int(n) - 1)
        elif int(n) == 11 or (int(n) % 10 == 1 and n[0] == "1" and int(n[1:-1]) == 0):
            return str(int(n) - 2)
        elif n[0] == "9" and n[0] * len(n) == n:
            return str(int(n) + 2)
        else:

            def get_panindrome(base, is_even_length=True):
                if is_even_length:
                    return base + "".join(reversed(base))
                else:
                    return base[:-1] + base[-1] + "".join(reversed(base[:-1]))

            even_size = len(n) % 2 == 0
            palindrome_base = (
                int(n[0 : len(n) // 2]) if even_size else int(n[0 : len(n) // 2 + 1])
            )
            is_n_palindrome = get_panindrome(str(palindrome_base), even_size) == n
            base_candidates = (
                [palindrome_base - 1, palindrome_base + 1]
                if is_n_palindrome
                else [palindrome_base - 1, palindrome_base, palindrome_base + 1]
            )
            diff = float("inf")
            for base_candidate in base_candidates:
                candidate = int(get_panindrome(str(base_candidate), even_size))
                if abs(candidate - int(n)) < diff:
                    diff = abs(candidate - int(n))
                    min_base_candidate = str(base_candidate)
            return get_panindrome(min_base_candidate, even_size)


if __name__ == "__main__":
    obj = Solution()
    print(obj.nearestPalindromic("123"))
    print(obj.nearestPalindromic("1"))
