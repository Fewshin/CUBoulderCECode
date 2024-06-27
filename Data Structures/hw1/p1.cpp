#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int addToArrayAsc(float sortedArray[], int numElements, float newValue);

int addToArrayAsc (float sortedArray[], int numElements, float newValue) {
  float store;
  if (numElements == 0) {
    sortedArray[0] = newValue;
    return 1;
  }
  for (int i = 0; i <= numElements; i++) {
    if (newValue > sortedArray[i - 1] && newValue <= sortedArray[i]) {
      store = sortedArray[i];
      sortedArray[i] = newValue;
    } else if (newValue <= sortedArray[i]) {
      float temp = sortedArray[i];
      sortedArray[i] = store;
      store = temp;
    } else if (newValue > sortedArray[i]) {

    } else {
      printf("PANIC!\n");
    }
  }
  return numElements + 1;
}