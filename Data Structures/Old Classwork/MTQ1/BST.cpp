#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10

/*
PUBLIC METHODS:
*/

// Constructor definitions:
// Default:
BST::BST(){
    root = nullptr;
}

void BST::addNode(int data){
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

void BST::print2DUtil(int space)
{
    print2DUtilHelper(root, space);
}

/*
PRIVATE METHODS:
*/


//  TODO:
//  Write a function decrementLeaves that goes through a Binary Search Tree 
//  and subtracts 1 from each of the leaf nodes. Feel free to implement an 
//  additional helper function.
int recursiveDecrement (Node * input) {
  if (input == NULL) return 0;//Safely escapes if we call a node that doesn't exist.
  if (input->right == NULL && input->left == NULL) {
    input->key--;//Reducing the value of the key.
    return 1;//We have found a leaf.
  }
  else {
    int count = 0;
    count += recursiveDecrement(input->right);
    count += recursiveDecrement(input->left);
    if (count > 0) { //checking to see if a leaf was found.
      if (input->right != NULL) {
        if (input->right->key <= input->key) {
          printf("Deleting right side node: %d\n", input->right->key);
          delete[] input->right;
          input->right = nullptr;
        }
      }
      if (input->left != NULL) {
        if (input->left->key >= input->key) {
          printf("Deleting left side node: %d\n", input->left->key);
          delete[] input->left;
          input->left = nullptr;
        }
      }
    }
    return 0;//Not a leaf so we return 0
  }
}

void BST::decrement(){
    // Write your code here.
  recursiveDecrement(root);
}  


//   This function will add the data in the tree rooted at currNode.
//   Call this function from insert().


Node* BST:: addNodeHelper(Node* currNode, int data){
    if(currNode == nullptr){
       return createNode(data);      
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
        currNode->right->parent = currNode;
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
        currNode->left->parent = currNode;
    }
    return currNode;
}


// Create a new node, setting key value to  input data
// and all pointers to null.
Node* BST:: createNode(int data){
    Node* newNode = new Node;
    newNode->key = data;
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* BST::getRoot(){
    return root;
}


/*
   Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space){
    // Base case
    if (currNode == nullptr)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}





