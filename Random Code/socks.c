#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long arrayManipulation(int n, int queries_rows, int queries_columns, int *queries[]) {
  long * store = (long *) malloc(n);
  for (long i = 0; i < n; i++) {
    *(store + i) = 0;
  }
  for (long i = 0; i < queries_rows; i++) {
    for (long j = queries[i][0] - 1; j < queries[i][1]; j++){
      *(store + j) += queries[i][2];
    }
  }
  long highest = *store;
  for (long i = 0; i < n; i++) {
    if (*(store + i) > highest) highest = *(store + i);
  }
  store = NULL;
  return highest;
}

int main () {
  int num = 10;
  int height = 4;
  int width = 3;
  int quer[4][3] = {{2, 6, 8},{3, 5, 7},{1, 8, 1},{5, 9, 15}};
  printf("%ld\n", arrayManipulation(num, height, width, quer));
  return 0;
}