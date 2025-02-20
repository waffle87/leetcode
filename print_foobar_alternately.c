// 1115. Print FooBar Alternately
#include "leetcode.h"
#include <semaphore.h>

/*
 * suppose you are given the following code:
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
 * the same instance of 'FooBar' will be passed to two different threads: thread
 * 'a' will call 'foo()' and thread 'b' will call 'bar()'. modify the given
 * program to output "foobar" 'n' times.
 */

typedef struct {
  int n;
  sem_t s_foo;
  sem_t s_bar;
} FooBar;

// Function declarations. Do not change or remove this line
void printFoo();
void printBar();

FooBar *fooBarCreate(int n) {
  FooBar *obj = (FooBar *)malloc(sizeof(FooBar));
  obj->n = n;
  sem_init(&obj->s_foo, 0, 0);
  sem_init(&obj->s_bar, 0, 1);
  return obj;
}

void foo(FooBar *obj) {
  for (int i = 0; i < obj->n; i++) {
    sem_wait(&obj->s_bar);
    // printFoo() outputs "foo". Do not change or remove this line.
    printFoo();
    sem_post(&obj->s_foo);
  }
}

void bar(FooBar *obj) {
  for (int i = 0; i < obj->n; i++) {
    sem_wait(&obj->s_foo);
    // printBar() outputs "bar". Do not change or remove this line.
    printBar();
    sem_post(&obj->s_bar);
  }
}

void fooBarFree(FooBar *obj) {
  sem_destroy(&obj->s_foo);
  sem_destroy(&obj->s_bar);
  if (obj)
    free(obj);
}

int main() {
  FooBar *f1 = fooBarCreate(1);
  FooBar *f2 = fooBarCreate(2);
  foo(f1);
  bar(f1);
  foo(f2);
  bar(f2);
  fooBarFree(f1);
  fooBarFree(f2);
}

void printFoo() { printf("foo"); }

void printBar() { printf("bar"); }
