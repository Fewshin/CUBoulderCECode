#include <iostream>
#include "bst.hpp"

BST::BST() {
	root = NULL;
}

BST::~BST() {
	deleteTree(root);
	root = NULL;
}
void BST::deleteTree(Node* node) {
	if (node != NULL) {
		deleteTree(node->leftChild);
		deleteTree(node->rightChild);
		delete node;
	}
}

/*
** Implement the following function to return the count of comparisons, 
**   you may implement helper functions.
*/
int BST::searchCounter(int target) {
	// your code here!
  Node * store = root; 
  int count = 0; //Counts how many nodes I am visiting.
  while (store != NULL) {
    count++; //Increments by one, we have successfully visited a node.
    //Below code decides what direction to go.
    if (target < store->key) {
      store = store->leftChild;
    } else if (target > store->key) {
      store = store->rightChild;
    } else {
      //count++;
      store = NULL; //If the key equal to the target we need to escape the loop.
    }
  }
  return count;
}
