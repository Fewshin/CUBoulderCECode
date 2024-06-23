#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include "index.h"

using namespace std; 

wordItem* arrayDoubler (wordItem* in, int *size) {
  int newSize = *size * 2;
  wordItem* out = (wordItem*) malloc(newSize);
  for (int i = 0; i < *size; i++) {
    *(out + i) = *(in + i);
  }
  *size = newSize;
  return out;
} 

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]) {
  FILE * in = fopen(ignoreWordFileName, "r");
  int count = 0;
  char store[64];
  while (fgets(store, 64, in) != NULL) {
    if (store[strlen(store) - 1] == '\n') {
      store[strlen(store) - 1] = '\0';
    }
    ignoreWords[count] = string(store);
    count++;
  }
}

bool isStopWord(string word, string ignoreWords[]) {
  for (int i = 0; i < 50; i++) {
    if (ignoreWords[i] == word) {
      return -1;
    }
  }
  return 0;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    count += uniqueWords[i].count;
  }
  return count;
}

void arraySort(wordItem uniqueWords[], int length) {
  wordItem store;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (uniqueWords[i].count > uniqueWords[j].count) {
        store = *(uniqueWords + j);
        *(uniqueWords + j) = *(uniqueWords + i);
        *(uniqueWords + i) = store;
      }
    }
  }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords) {
  for (int i = N; i < N + 10; i++) {
    printf("%0.4f - %s\n", (float) round(10000 *round(100000 * uniqueWords[i].count/totalNumWords)/100000)/10000, uniqueWords[i].word.c_str());
  }
}

int main (int argc, char** argv) {
  if (argc != 4) {
    printf("%s\n", "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>");
    return -1;
  }
  FILE * in = fopen(argv[2], "r");
  if (in == NULL) {
    printf("%s\n", "Invalid input file.");
    return -1;
  }
  string ignore[50];
  getStopWords(argv[3], ignore);
  int count = 0;
  char store[64];
  wordItem* words = (wordItem*) malloc(100);
  int size = 100;
  while (fgets(store, 64, in) != NULL) {
    if (isStopWord(store, ignore)) {
      count++;
    }
    else {
      if (size == count)  {
        words = arrayDoubler(words, &size);
      }
      (words + count)->word = string(store);
      count++;
    }
  } 
  return 0;
}