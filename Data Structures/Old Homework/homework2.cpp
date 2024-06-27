// Copy your getStopWords function into the box below. 
// Your answer should look like:

// void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
// {
//     // Your code here
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]) {
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

// Copy your isStopWord function into the box below. 
// Your answer should look like:bool isStopWord(string word, string ignoreWords[])

// bool isStopWord(string word, string ignoreWords[])
// {
//     // Your code here
// }

bool isStopWord(string word, string ignoreWords[]) {
  for (int i = 0; i < 50; i++) {
    if (ignoreWords[i] == word) {
      return -1;
    }
  }
  return 0;
}

// Copy your getTotalNumberNonStopWords function into the box below. 
// Your answer should look like:

// int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
// {
//     // Your code here
// }
// For example:

// Test	Result
// HarryPotter.txt
// 50331

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    count += uniqueWords[i].count;
  }
  return count;
}

// Copy your arraySort function into the box below, with the provided prototype. 
// Your answer should look like:

// void arraySort(wordItem uniqueWords[], int length)
// {
//     // Your code here
// }

void arraySort(wordItem uniqueWords[], int length) {
  wordItem * temp = (wordItem*) malloc(length);
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

// Copy your printNext10 function into the box below. 
// Your answer should look like:

// void printNext10(wordItem wordItemList[], int startRank, int totalWords)
// {
//     // Your code here
// }

void printNext10(wordItem uniqueWords[], int N, int totalNumWords) {
  for (int i = N; i < N + 10; i++) {
    printf("%0.4f - %s\n", (float) round(10000 *round(100000 * uniqueWords[i].count/totalNumWords)/100000)/10000, uniqueWords[i].word.c_str());
  }
}