// 1195. Fizz Buzz Multithreaded
#include "leetcode.h"

/*
 * you have the following functions:
 * 'printFizz' prints the word "fizz" to the console
 * 'printBuzz' prints the word "buzz" to the console
 * 'printFizzBuzz' prints the word "fizzbuzz" to the console
 * 'printNumber' that prints a given integer to the console
 * you are given an instance of the class 'fizzbuzz' that has four functions
 * 'fizz', 'buzz', 'fizzbuzz', and 'number'. the same instance of 'fizzbuzz'
 * will be passed to four different threads.
 * thread a calls 'fizz()' that should output the word "fizz"
 * thread b calls 'buzz()' that should output the word "buzz"
 * thread c calls 'fizzbuzz()' that should output the word "fizzbuzz"
 * thread d calls 'number()' that should output the given integer
 * modify the given class to output the series '[1, 2, "fizz", 4, "buzz", ...]'
 * where the i'th toek of the series is.
 */

typedef struct {
  int n;
  int curr;
  int turn;
} FizzBuzz;

pthread_mutex_t mutex;
pthread_cond_t cond;

FizzBuzz *fizzBuzzCreate(int n) {
  FizzBuzz *obj = (FizzBuzz *)malloc(sizeof(FizzBuzz));
  obj->n = n;
  obj->curr = 1;
  obj->turn = 0;
  return obj;
}

// Don't change the following declarations
void printNumber(int a);
void printFizz();
void printBuzz();
void printFizzBuzz();

int helper(FizzBuzz *obj, int turn) {
  pthread_mutex_lock(&mutex);
  while (obj->turn != turn && obj->curr <= obj->n)
    pthread_cond_wait(&cond, &mutex);
  if (obj->curr > obj->n)
    return -1;
  switch (turn) {
  case 0:
    printNumber(obj->curr);
    break;
  case 1:
    printFizz();
    break;
  case 2:
    printBuzz();
    break;
  case 3:
    printFizzBuzz();
    break;
  }
  obj->curr++;
  if ((obj->curr % 3 == 0) && (obj->curr % 5 == 0))
    obj->turn = 3;
  else if (obj->curr % 3 == 0)
    obj->turn = 1;
  else if (obj->curr % 5 == 0)
    obj->turn = 2;
  else
    obj->turn = 0;
  pthread_cond_broadcast(&cond);
  pthread_mutex_unlock(&mutex);
  return 0;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz *obj) {
  while (1)
    if (helper(obj, 1) == -1)
      break;
  pthread_mutex_unlock(&mutex);
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz *obj) {
  while (1)
    if (helper(obj, 2) == -1)
      break;
  pthread_mutex_unlock(&mutex);
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz *obj) {
  while (1)
    if (helper(obj, 3) == -1)
      break;
  pthread_mutex_unlock(&mutex);
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz *obj) {
  while (1)
    if (helper(obj, 0) == -1)
      break;
  pthread_mutex_unlock(&mutex);
}

void fizzBuzzFree(FizzBuzz *obj) {
  if (obj)
    free(obj);
}

void printNumber(int a) { printf("%d ", a); }

void printFizz() { printf("fizz "); }

void printBuzz() { printf("buzz "); }

void printFizzBuzz() { printf("fizzbuzz "); }

int main() {
  FizzBuzz *obj1 = fizzBuzzCreate(15);
  FizzBuzz *obj2 = fizzBuzzCreate(5);
  pthread_t t1[4], t2[4];
  pthread_create(&t1[0], NULL, (void *)fizz, obj1);
  pthread_create(&t1[1], NULL, (void *)buzz, obj1);
  pthread_create(&t1[2], NULL, (void *)fizzbuzz, obj1);
  pthread_create(&t1[3], NULL, (void *)number, obj1);
  for (int i = 0; i < 4; i++)
    pthread_join(
        t1[i],
        NULL); // expect:
               // [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
  pthread_create(&t2[0], NULL, (void *)fizz, obj2);
  pthread_create(&t2[1], NULL, (void *)buzz, obj2);
  pthread_create(&t2[2], NULL, (void *)fizzbuzz, obj2);
  pthread_create(&t2[3], NULL, (void *)number, obj2);
  for (int i = 0; i < 4; i++)
    pthread_join(t1[i], NULL); // expect: [1,2,"fizz",4,"buzz"]
  fizzBuzzFree(obj1);
  fizzBuzzFree(obj2);
}
