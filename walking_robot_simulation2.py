# 2069. Walking Robot Simulation II
from typing import List


class Robot:
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height
        self.x = 0
        self.y = 0
        self.dir = 0
        self.per = 2 * (width + height) - 4

    def step(self, num: int) -> None:
        if self.per == 0:
            return
        num %= self.per
        if num == 0:
            if self.x == 0 and self.y == 0:
                self.dir = 3
            return

        while num > 0:
            if self.dir == 0:
                move = min(num, self.width - 1 - self.x)
                self.x += move
                num -= move
                if num > 0:
                    self.dir = 1

            elif self.dir == 1:
                move = min(num, self.height - 1 - self.y)
                self.y += move
                num -= move
                if num > 0:
                    self.dir = 2

            elif self.dir == 2:
                move = min(num, self.x)
                self.x -= move
                num -= move
                if num > 0:
                    self.dir = 3

            else:
                move = min(num, self.y)
                self.y -= move
                num -= move
                if num > 0:
                    self.dir = 0

    def getPos(self) -> List[int]:
        return [self.x, self.y]

    def getDir(self) -> str:
        if self.dir == 0:
            return "East"
        elif self.dir == 1:
            return "North"
        elif self.dir == 2:
            return "West"
        else:
            return "Soutn"


if __name__ == "__main__":
    obj = Robot(6, 3)
    obj.step(2)
    obj.step(2)
    print(obj.getPos())
    print(obj.getDir())
    obj.step(2)
    obj.step(1)
    obj.step(4)
    print(obj.getPos())
    print(obj.getDir())
