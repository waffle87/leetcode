// 2166. Design Bitset
#include "leetcode.h"

/*
 * a bitset is a data structure that compactly stores bits. implement the
 * 'Bitset' class. 'Bitset(int size)' initialises the bitsetwith 'size' bits,
 * all of which are '0' 'void fix(int idx)' updates the value of the bit at the
 * index 'idx' to 1 if the value was already 1, no change occurs 'void unfix(int
 * idx)' updates the value of the bit at the index 'idx' to 0 if the value was
 * already 0, no change occurs 'void flip()' flips the values of each bit in the
 * biset. in other words, all bits with value 0 will now have value 1 and vice
 * versa 'boolean all()' checks if the value of each bit in the bitset is 1.
 * returns true if it satisfies the condition, false otherwise 'boolean one()'
 * checks if there is at least one bit in the bitset withvalue 1. returns true
 * if it satisfies the condition, false otherwise 'int count()' returns the
 * total number of bits in the bitset which have value 1 'string toString()'
 * returns the current composition of the bitset. note that in the resultant
 * string, the character at the i'th index should coincide with the value at the
 * i'th bit of the bitset
 */

typedef struct {
  int ones;
  int size;
  char *digits;
  char *reverse;
} Bitset;

Bitset *bitsetCreate(int size) {
  Bitset *obj = (Bitset *)malloc(sizeof(Bitset));
  obj->ones = 0;
  obj->size = size;
  obj->digits = (char *)malloc((size + 1) * sizeof(char));
  obj->reverse = (char *)malloc((size + 1) * sizeof(char));
  memset(obj->digits, '0', size);
  memset(obj->reverse, '1', size);
  obj->digits[size] = '\0';
  obj->reverse[size] = '\0';
  return obj;
}

void bitsetFix(Bitset *obj, int idx) {
  if (obj->digits[idx] != '1') {
    obj->digits[idx] = '1';
    obj->reverse[idx] = '0';
    obj->ones++;
  }
}

void bitsetUnfix(Bitset *obj, int idx) {
  if (obj->digits[idx] != '0') {
    obj->digits[idx] = '0';
    obj->reverse[idx] = '1';
    obj->ones--;
  }
}

void bitsetFlip(Bitset *obj) {
  char *tmp = obj->digits;
  obj->digits = obj->reverse;
  obj->reverse = tmp;
  obj->ones = obj->size - obj->ones;
}

bool bitsetAll(Bitset *obj) { return obj->ones == obj->size; }

bool bitsetOne(Bitset *obj) { return obj->ones > 0; }

int bitsetCount(Bitset *obj) { return obj->ones; }

char *bitsetToString(Bitset *obj) { return obj->digits; }

void bitsetFree(Bitset *obj) {
  free(obj->digits);
  free(obj->reverse);
  free(obj);
}

int main() {
  Bitset *obj = bitsetCreate(5);
  bitsetFix(obj, 3);
  bitsetFix(obj, 1);
  bitsetFlip(obj);
  printf("%d\n", bitsetAll(obj)); // expect: 0
  bitsetUnfix(obj, 0);
  bitsetFlip(obj);
  printf("%d\n", bitsetOne(obj)); // expect: 1
  bitsetUnfix(obj, 0);
  printf("%d\n", bitsetCount(obj));    // expect: 2
  printf("%s\n", bitsetToString(obj)); // expect: 01010
  bitsetFree(obj);
}
