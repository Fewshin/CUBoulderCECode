#include <stdlib.h>
#include <stdio.h>
#include "a1p1.h"

int insert(float **in, float val, int count) {
  if (val == NULL || in == NULL) return -1;
  *in = (float*)realloc(*in, count + 1);
  if (count == NULL || count == 0) {
    **in = val;
    return 0;
  }
  if (count == 1) {
    if (**in > val) {
      *(*in + 1) = **in;
      **in = val;
    }
    else *(*in + 1) = val;
  }
  *in = (float*)realloc(*in, count + 1);
  float * sto = (float*) malloc(0);
  int ind, sSize;
  for (int i = 0; i < count; i++) {
    if (*(*in + i) > val) {
      if (*(*in + i - 1) < val) {
        sSize = count - i + 1;
        sto = (float*)realloc(sto, sSize);
        for (int j = 0; j < count + 1 - i; j++){
          *(sto + j) = *(*in + i + j);
        }
        *(*in + i) = val;
        ind = i;
      }
    }
    else {
      *(*in + i) = *(*in + i);
    }
  }
  for (int i = 0; i < sSize; i++) {
    *(*in + ind + 1 + i) = *(sto + i);
  }
  return count + 1;
}

int logArray (float *in, int size) {
  if (in == NULL) return -1;
  for (int i = 0; i < size; i++) {
    printf("%f : %d\n", in[i], i);
  }
  return 0;
}

int main (int argc, char **argv) {
  if (argc != 2) {
    printf("Error, you need 2 arguments, you included %d\n", argc);
    return -1;
  }
  FILE * in = fopen(argv[1], "r");
  if (in == NULL) return -1;
  float * buff = (float*) malloc(0);
  float sto[1];
  int count = 0;
  while (*sto != EOF) {
    fscanf(in, "%f", sto);
    printf("Sto: %f\n", *sto);
    insert(&buff, *sto, count);
    logArray(buff, count);
    count++;
  }
  logArray(buff, count);
  fclose(in);
  return 0;
}

// float * makeDynamic (float * in, int size) {
//   float * out = (float *) malloc(size);
//   for (int i = 0; i < size; i++) {
//     *(out + i) = *(in + i);
//   }
//   return out;
// }