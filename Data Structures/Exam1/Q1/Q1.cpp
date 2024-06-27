/*
CSCI 2270 - Spring 2021
Midterm 1
Question 1 starter code.

*/


#include <iostream>

using namespace std;

/*
    * TODO your function header goes here
*/
void trim(int ** a0, int &test_length, int target);

void testPrint(int *p0, int length);

int main(){
   
    int a_test[] = {3, 2, 5 ,1, 0, 8, 4};
    int test_length = 7;
   
   
    /*
    Test 1
    */
    cout << "\n---------------------\n";
    
    int * a0 = new int[test_length];
    for(int i = 0; i<test_length; i++){
        a0[i] = a_test[i];
    }

    int target = 0; 
    
    /*
        * TODO your function call goes here. It should look like:
       
    */ 
    int ** hold = &a0; //double pointer is easier
    trim(hold, test_length, target);

    cout << "Test 1: \n"  << "expected >> 3 2 5 1 " << endl;
    testPrint(a0, test_length);
    delete [] a0;

    return 0;
}




/*
    * TODO your function definition goes here
*/
void trim(int ** a0, int &test_length, int target) {
  for (int i = 0; i < test_length; i++) {
    if (*(*a0 + i) == target) {
      int * store = new int[i]; //Array doesn't need to be i + 1 because we're excluding the current value
      int ** storePointer = &store; //Pointer to the above array
      for (int j = 0; j < i; j++) { 
        *(store + j) = *(*a0 + j); //Copying over information
      }
      delete [] *a0; //freeing the newly unused space
      *a0 = *storePointer; //The reason I used a double pointer
      test_length = i; //updating array size
      break;//Don't care about rest of the array
    }
  }
  return;
}



void testPrint(int *p0, int length){
    
    cout << "result   >> ";

    for(int i = 0; i<length; i++){
        cout << p0[i] << " ";
    }
    cout << "\n---------------------\n\n" << endl;
}