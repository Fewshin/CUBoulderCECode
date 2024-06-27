#include <iostream> // predefined header file (defined for you)
#include <string>
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	head = nullptr;
}

SLL::~SLL(){
	Node* crawler;

	while(head!=nullptr){
		crawler = head->next;
		delete head;
		head = crawler;
	}
}


void SLL::displayList(){
	Node* crawler = head;
	while( crawler != nullptr ){
		cout << crawler->key << "->";
		crawler = crawler->next;
	}

	cout << "END" << endl;
}


void SLL::insert(Node* afterMe, char newValue){

	if(head == nullptr){
		// first case: empty list
		// add new node and make head point to it
		head = new Node;
		head->key = newValue;
		head->next = nullptr; // what if we forget this line?
	}
	else if(afterMe == nullptr){
		// This condition implies that the list is not empty, but
		// the caller wants to add node before the head node
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = head;
		head = newNode;
		// at this point, we can test our code for this use case

	}
	else{
		Node* newNode = new Node;
		newNode->key = newValue;
		newNode->next = afterMe->next;
		afterMe->next = newNode;
	}


}

bool SLL::palindrome(){
/*
    * TODO your function definition goes here
*/
  Node * store = head;
  int size = 0;

  while (store != NULL) { //Finding number of nodes, by doing store != NULL instead of store->next != NULL we can get an accurate count
    store = store->next;
    size++;
  }

  // char * foreWord = new char[size]; //Array of chars
  // char * backWord = new char[size]; //Another array of chars

  // store = head; //resetting store

  // for (int i = 0; i < size; i++) {
  //   foreWord[i] = store->key; //Putting in the letters starting at the front
  //   backWord[size - 1 - i] = store->key; //Putting in the letter starting at the back
  //   store = store->next; //Moving to the next node
  // }
  // if (strcmp(foreWord, backWord) == 0) { //Imagine having the String datatype this post was brought to you by the C gang.
  //   return true;
  // } else {
  //   return false;
  // }
  //Just read instructions, I'm too annoyed to let all my previous work go unrecognized.

  int i = 0;
  for (int i = 0; i < size; i++) {
    char frontChar = atIndex(i); //Pulling characters starting from the front
    char backChar = atIndex(size - 1 - i); //Pulling characters starting from the back
    if (frontChar == '\0' || backChar == '\0') { //Checking if something has gone wrong and exiting if it has.
      printf("Null Char Found\n");
      return false;
    }
    if (frontChar != backChar) { //Comparing values to see if it's a palindrome
      return false;
    }
  }
  return true; //If you made it this far you're probably a palindrome congrats.
}

char SLL::atIndex(int i){ //Why i? I feel like n is better given i is standard in for loops, very dangerous.
  Node * store = head;
  if (i < 0) { //Negative value check
    printf("Invalid Index, Negative Value\n"); //Detailed error message
    return '\0'; 
  }
  for (int j = 0; j < i; j++) {
    if (store != NULL) {
      store = store->next;
    } else { //Esssentially if store == NULL, that means the index is invalid
      printf("Invalid Index, Index Too Large\n"); //Detailed error message
      return '\0';
    }
  }
	return store->key;
}



