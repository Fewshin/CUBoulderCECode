#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

struct wordRecord {
  string word;
  int count;
};

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]) {
  FILE * in = fopen(ignoreWordFileName, "r");
  int ret;
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

bool isIgnoreWord(string word, string ignoreWords[]) {
  for (int i = 0; i < 50; i++) {
    if (ignoreWords[i] == word) {
      return -1;
    }
  }
  return 0;
}

int getTotalNumberNonIgnoreWords(wordRecord uniqueWords[], int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    count += uniqueWords[i].count;
  }
  return count;
}

void sortArray(wordRecord uniqueWords[], int length) {
  wordRecord * temp = (wordRecord*) malloc(length);
  wordRecord store;
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

void printTenFromN(wordRecord uniqueWords[], int N, int totalNumWords) {
  for (int i = N; i < N + 10; i++) {
    printf("%0.5f - %s\n", (float) uniqueWords[i].count/totalNumWords, uniqueWords[i].word.c_str());
  }
}

int main(int argc, char * argv[]) {
  if (argc < 4) {
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" <<endl;
    return -1;
  }
  string ignoreWords[50];
  wordRecord * uniqueWords = new wordRecord[100];
  int wordCount = 0;
  int wordMax = 100;
  int doubleCount = 0;
  getIgnoreWords(argv[3], ignoreWords);
  FILE * in = fopen(argv[2], "r");
  int parseCount = 0;
  char store[64];
  while (fgets(store, 64, in) != NULL) {
    bool inArray = false;
    if (store[strlen(store) - 1] == '\n') {
      store[strlen(store) - 1] = '\0';
    }
    for (int i = 0; i < wordCount; i++) {
      if (store == uniqueWords[i].word) {
        uniqueWords[i].count++;
        inArray = true;
      }
    }
    if (inArray == false && !isIgnoreWord(store, ignoreWords)) {
      if (wordCount == wordMax) {
        wordRecord * temp = new wordRecord[wordMax * 2];
        wordMax = wordMax * 2;
        doubleCount++;
        for (int i = 0; i < wordMax; i++) {
          memcpy(temp, uniqueWords, sizeof(temp));
        }
        uniqueWords = temp;
      }
      uniqueWords[wordCount].word = store;
      uniqueWords[wordCount].count = 0;
      wordCount++;
    }
  }
  sortArray(uniqueWords, wordCount);
  printf("Array Doubled: %d\n", doubleCount);
  printf("Distinct non-common words: %d\n", wordCount);
  printf("Total non-common words: %d\n", getTotalNumberNonIgnoreWords(uniqueWords, wordCount));
  printf("Probability of next 10 words from rank %d\n", atoi(argv[1]));
  printf("---------------------------------------\n");
  printTenFromN(uniqueWords, atoi(argv[1]), wordCount);
  return 0;
}