# 3753. Total Waviness of Numbers in Range II

"""
you are given two integers representing an inclusive range. the waviness of a
number is defined as the total count of its peaks and valleys. a digit is a
peak if it is strictly greater than both of its immediate neighbours. a digit
is a valley if it is strictly less than both of its immediate neighbours. the
first and last digits of a number cannot be peaks or valleys. any number with
fewer than 3 digits has a waviness of 0. return the total sum of waviness for
all numbers in the range.
"""


class Solution:
    def solve(self, num: int) -> int:
        if num < 100:
            return 0
        s = str(num)
        n = len(s)
        curr_states = [(10, 10, 1, 1, 1, 0)]
        for pos in range(n):
            limit = int(s[pos])
            cnt = [[[[0] * 11 for _ in range(11)] for _ in range(2)] for _ in range(2)]
            sum_arr = [
                [[[0] * 11 for _ in range(11)] for _ in range(2)] for _ in range(2)
            ]
            for prev, curr, tight, lead, c, s_val in curr_states:
                max_digit = limit if tight else 9
                for digit in range(max_digit + 1):
                    new_lead = 1 if (lead and digit == 0) else 0
                    new_prev = curr
                    new_curr = 10 if new_lead else digit
                    new_tight = 1 if (tight and digit == max_digit) else 0
                    add = 0
                    if not new_lead and prev != 10 and curr != 10:
                        if (prev < curr and curr > digit) or (
                            prev > curr and curr < digit
                        ):
                            add = c
                    cnt[new_tight][new_lead][new_prev][new_curr] += c
                    sum_arr[new_tight][new_lead][new_prev][new_curr] += s_val + add
            next_states = []
            for tight in range(2):
                for lead in range(2):
                    for prev in range(11):
                        for cur in range(11):
                            c = cnt[tight][lead][prev][cur]
                            if c != 0:
                                next_states.append(
                                    (
                                        prev,
                                        cur,
                                        tight,
                                        lead,
                                        c,
                                        sum_arr[tight][lead][prev][cur],
                                    )
                                )
            curr_states = next_states
        ans = 0
        for _, _, _, _, _, s_val in curr_states:
            ans += s_val
        return ans

    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.solve(num2) - self.solve(num1 - 1)


if __name__ == "__main__":
    obj = Solution()
    print(obj.totalWaviness(num1=120, num2=130))
    print(obj.totalWaviness(num1=198, num2=202))
    print(obj.totalWaviness(num1=4848, num2=4848))
