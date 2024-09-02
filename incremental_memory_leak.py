# 1860. Incremental Memory Leak

"""
you are given two integer 'memory1' and 'memory2' representing the available
memory in bits on two memory sticks. there is currently a faulty program
running that consumes an increasing amount of memory every second. at the
i'th second (starting from 1), 'i' bits of memory are allocated to the stick
with more available memory (or from the first memory stick if both have the
same available memory). if neither stick has at least 'i' bits of available
memory, the program crashes. return an array containing '[crash_time,
memory1_crash, memory2_crash]', where 'crash_time' is the time when the
program crashed and 'memory1_crash' and 'memory2_crash' are the available
bits of memory in the first and second sticks respectively
"""


class Solution(object):
    def memLeak(self, memory1, memory2):
        """
        :type memory1: int
        :type memory2: int
        :rtype: List[int]
        """
        i = 1
        while max(memory1, memory2) >= i:
            if memory1 >= memory2:
                memory1 -= i
            else:
                memory2 -= i
            i += 1
        return [i, memory1, memory2]


if __name__ == "__main__":
    obj = Solution()
    print(obj.memLeak(2, 2))
    print(obj.memLeak(8, 11))
