# 1115. Print FooBar Alternately
from threading import Semaphore

"""
suppose you are given the following code:
class FooBar {
public void foo() {
  for (int i = 0; i < n; i++) {
    print("foo");
  }
}

public void bar() {
  for (int i = 0; i < n; i++) {
    print("bar");
  }
}
}
the same instance of 'FooBar' will be passed to two different threads: thread
'a' will call 'foo()' and thread 'b' will call 'bar()'. modify the given
program to output "foobar" 'n' times.
"""


def printFoo():
    print("foo")


def printBar():
    print("bar")


class FooBar(object):
    def __init__(self, n):
        self.n = n
        self.s_foo = Semaphore(1)
        self.s_bar = Semaphore(0)

    def foo(self, printFoo):
        """
        :type printFoo: method
        :rtype: void
        """
        for i in range(self.n):
            self.s_foo.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.s_bar.release()

    def bar(self, printBar):
        """
        :type printBar: method
        :rtype: void
        """
        for i in range(self.n):
            self.s_bar.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.s_foo.release()


if __name__ == "__main__":
    f1 = FooBar(1)
    f2 = FooBar(2)
    f1.foo()
    f1.bar()
    f2.foo()
    f2.bar()
