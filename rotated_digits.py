# 788. Rotated Digits

"""
an integer 'x' is good if after rotating each digit individually by 180
degrees, we get a valid number that is different from 'x'. each digit must be
rotated - we cannot choose to leave it alone. a number is valid if each digit
remains after rotation. given the integer 'n', return the number of good
integers in the range '[1, n]'.
"""


class Solution:
    def rotatedDigits(self, n: int) -> int:
        cnt = 0
        for i in range(1, n + 1):
            check = i
            valid, changed = True, False
            while check > 0 and valid:
                digit = check % 10
                if digit in (3, 4, 7):
                    valid = False
                elif digit in (2, 5, 6, 9):
                    changed = True
                check //= 10
            if valid and changed:
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.rotatedDigits(n=10))
    print(obj.rotatedDigits(n=1))
    print(obj.rotatedDigits(n=2))
