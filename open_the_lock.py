# 752. Open the Lock
from collections import deque

"""
you have a lock in front of you with 4 circular wheels. each wheel has 10
slots 0-9. the wheels can rotate freely and wrap around. the lock initially
starts at 0000, a sting representing the state of the 4 wheels. given a list
of 'deadends', meaning the lock displays any of these codes, the wheels of
the lock will stop turning and you will be unable to open it. given 'target'
representing the value of the wheels that will unlock the lock, return the
minimum total number of turns required to open the lock, or -1 if it is
impossible
"""


class Solution(object):
    def neighbours(self, code):
        for i in range(4):
            x = int(code[i])
            for diff in (-1, 1):
                y = (x + diff + 10) % 10
                yield code[:i] + str(y) + code[i + 1 :]

    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        dead_set = set(deadends)
        if "0000" in dead_set:
            return -1
        q = deque(["0000"])
        steps = 0
        while q:
            for _ in range(len(q)):
                curr = q.popleft()
                if curr == target:
                    return steps
                for i in self.neighbours(curr):
                    if i in dead_set:
                        continue
                    dead_set.add(i)
                    q.append(i)
            steps += 1
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.openLock(deadends=["0201", "0101", "0102", "1212", "2002"], target="0202")
    )
    print(obj.openLock(deadends=["8888"], target="0009"))
    print(
        obj.openLock(
            deadends=["8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"],
            target="8888",
        )
    )
