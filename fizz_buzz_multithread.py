# 1195. Fizz Buzz Multithreaded
import threading

"""
you have the following functions:
'printFizz' prints the word "fizz" to the console
'printBuzz' prints the word "buzz" to the console
'printFizzBuzz' prints the word "fizzbuzz" to the console
'printNumber' that prints a given integer to the console
you are given an instance of the class 'fizzbuzz' that has four functions
'fizz', 'buzz', 'fizzbuzz', and 'number'. the same instance of 'fizzbuzz'
will be passed to four different threads.
thread a calls 'fizz()' that should output the word "fizz"
thread b calls 'buzz()' that should output the word "buzz"
thread c calls 'fizzbuzz()' that should output the word "fizzbuzz"
thread d calls 'number()' that should output the given integer
modify the given class to output the series '[1, 2, "fizz", 4, "buzz", ...]'
where the i'th toek of the series is.
"""


class FizzBuzz(object):
    def __init__(self, n):
        self.n = n
        self.f = threading.Lock()
        self.b = threading.Lock()
        self.fb = threading.Lock()
        self.f.acquire()
        self.b.acquire()
        self.fb.acquire()
        self.main = threading.Lock()

    # printFizz() outputs "fizz"
    def fizz(self, printFizz):
        """
        :type printFizz: method
        :rtype: void
        """
        while True:
            self.f.acquire()
            if self.n == 0:
                return
            printFizz()
            self.main.release()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz):
        """
        :type printBuzz: method
        :rtype: void
        """
        while True:
            self.b.acquire()
            if self.n == 0:
                return
            printBuzz()
            self.main.release()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz):
        """
        :type printFizzBuzz: method
        :rtype: void
        """
        while True:
            self.fb.acquire()
            if self.n == 0:
                return
            printFizzBuzz()
            self.main.release()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in range(1, self.n + 1):
            self.main.acquire()
            if i % 15 == 0:
                self.fb.release()
            elif i % 3 == 0:
                self.f.release()
            elif i % 5 == 0:
                self.b.release()
            else:
                printNumber(i)
                self.main.release()
        self.main.acquire()
        self.n = 0
        self.f.release()
        self.b.release()
        self.fb.release()
        return
