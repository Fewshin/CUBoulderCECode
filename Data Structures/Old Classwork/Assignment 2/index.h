#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std; 

struct wordItem {
  string word;
  int count;
};

wordItem* arrayDoubler (wordItem* in, int *size);
bool isStopWord(string word, string ignoreWords[]);
void getStopWords(const char *ignoreWordFileName, string ignoreWords[]);
int getTotalNumberNonStopWords(wordItem uniqueWords[], int length);
void arraySort(wordItem uniqueWords[], int length);
void printNext10(wordItem uniqueWords[], int N, int totalNumWords);