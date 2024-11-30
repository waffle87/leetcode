# 818. Race Car

"""
your car starts at position 0 and speed +1 on an infinite number line. your
car can go into negative positions. your car drives automatically according
to a sequence of instructions 'A' (accelerate), and 'R' (reverse). given a
target position 'target', return the length of the shortest sequence of
instructions to get there.
"""


class Solution(object):
    dp = {0: 0}

    def racecar(self, target):
        """
        :type target: int
        :rtype: int
        """
        if target in self.dp:
            return self.dp[target]
        n = target.bit_length()
        if 2**n - 1 == target:
            self.dp[target] = n
        else:
            self.dp[target] = self.racecar(2**n - 1 - target) + n + 1
            for m in range(n - 1):
                self.dp[target] = min(
                    self.dp[target],
                    self.racecar(target - 2 ** (n - 1) + 2**m) + n + m + 1,
                )
        return self.dp[target]


if __name__ == "__main__":
    obj = Solution()
    print(obj.racecar(3))
    print(obj.racecar(6))
