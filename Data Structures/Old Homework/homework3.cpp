//Problem 1: Complete the definition for the append function.

bool append(string* &str_arr, string s, int &numEntries, int &arraySize) {
    //why are tabs 4 spaces?
    if (numEntries > arraySize) { return 0; }
    else if (numEntries == arraySize) {
        arraySize *= 2;
        string* temp = new string [arraySize];
        for (int i = 0; i < numEntries; i++) {
            *(temp + i) = *(str_arr + i);
        }
        *(temp + numEntries) = s;
        numEntries++;
        str_arr = temp;
        return 1;
    }
    else {
        *(str_arr + numEntries) = s;
        numEntries++;
        return 0;
    }
}

//Problem 2: Complete the definition of searchNetwork function below.

Country* CountryNetwork::searchNetwork(string countryName)
{
    // TODO
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL) {
        if (head->name == countryName) {
            return head;
        }
        else { return NULL; }
    }
    else {
        Country* temp = head;
        while(temp->name != countryName) {
            if (temp->next == NULL) {
                return NULL;
            }
            temp = temp->next;
        }
        return temp;
    }
}

//Problem 2: Complete the definition of insertCountry function below.

void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    // TODO
    if (head == NULL) {
        printf("adding: %s (HEAD)\n", countryName.c_str());
        Country* temp = new Country;
        temp->next = NULL;
        temp->name = countryName;
        temp->message = "";
        temp->numberMessages = 0;
        head = temp;
    }
    else if (previous == NULL) {
        printf("adding: %s (HEAD)\n", countryName.c_str());
        Country* temp = new Country;
        temp->next = head;
        temp->name = countryName;
        temp->message = "";
        temp->numberMessages = 0;
        head = temp;
    }
    else {
        printf("adding: %s (prev: %s)\n", countryName.c_str(), previous->name.c_str());
        Country* temp = new Country;
        temp->next = previous->next;
        temp->name = countryName;
        temp->message = "";
        temp->numberMessages = 0;
        previous->next = temp;   
    }
}

//Problem 2: Complete the definition of loadDefaultSetup() function below. 

void CountryNetwork::loadDefaultSetup()
{
    // TODO
    insertCountry(NULL, "United States");
    insertCountry(CountryNetwork::searchNetwork("United States"), "Canada");
    insertCountry(CountryNetwork::searchNetwork("Canada"), "Brazil");
    insertCountry(CountryNetwork::searchNetwork("Brazil"), "India");
    insertCountry(CountryNetwork::searchNetwork("India"), "China");
    insertCountry(CountryNetwork::searchNetwork("China"), "Australia");
}

// Problem 2: Complete the definition of transmitMsg function below.

void CountryNetwork::transmitMsg(string receiver, string message)
{
    // TODO
    Country * temp = head;
    temp->message = message;
    temp->numberMessages++;
    printf("%s [# messages received: %d] received: %s\n", temp->name.c_str(), temp->numberMessages, temp->message.c_str());
    while (temp->name != receiver) {
        temp = temp->next;
        temp->numberMessages++;
        temp->message = message;
        printf("%s [# messages received: %d] received: %s\n", temp->name.c_str(), temp->numberMessages, temp->message.c_str());
    }
}

//Problem 2: Enter the contents of main.cpp and  CountryNetwork.cpp of your Homework 3. 

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void displayMenu();  

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;

    // TODO
    displayMenu();
    string sto;
    getline(cin, sto);
    int temp = sto.c_str()[0] - '0';
    while (temp != 5) {
        cin.clear();
        if (temp == 1) {
            CountryNet.loadDefaultSetup();
            CountryNet.printPath();
        }
        else if (temp == 2) {
            CountryNet.printPath();
        }
        else if (temp == 3) {
            printf("Enter name of the country to receive the message:\n");
            string country;
            getline(cin, country);
            printf("Enter the message to send:\n");
            if (CountryNet.searchNetwork(country) != NULL) {
                string mess;
                getline(cin, mess);
                CountryNet.transmitMsg(country, mess);
            }
            else{
                printf("Country not found\n");
            }
        }
        else if(temp == 4) {
            string nu;
            printf("Enter a new country name:\n");
            getline(cin, nu);
            string country;
            printf("Enter the previous country name (or First):\n");
            getline(cin, country);
            while (CountryNet.searchNetwork(country) == NULL && country != "First") {
                printf("INVALID(previous country name)...Please enter a VALID previous country name!\n");
                getline(cin, country);
            }
            //printf("adding: %s (prev: %s)\n", nu.c_str(), country.c_str());
            if (country == "First") {
                CountryNet.insertCountry(NULL, nu);
            }
            else {
                CountryNet.insertCountry(CountryNet.searchNetwork(country), nu);
            }
            CountryNet.printPath();
        }
        if (strlen(sto.c_str()) < 2) displayMenu();
        getline(cin, sto);
        temp = sto.c_str()[0] - '0';
    }
    printf("Quitting...\n");
    printf("Goodbye!");
    return 0;
}


/************************************************
      Definitions from CountryNetwork.cpp
************************************************/
/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    // TODO
    head = NULL;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    // TODO
    if (head == NULL) {
        printf("adding: %s (HEAD)\n", countryName.c_str());
        Country* temp = new Country;
        temp->next = NULL;
        temp->name = countryName;
        temp->message = "";
        temp->numberMessages = 0;
        head = temp;
    }
    else if (previous == NULL) {
        printf("adding: %s (HEAD)\n", countryName.c_str());
        Country* temp = new Country;
        temp->next = head;
        temp->name = countryName;
        temp->message = "";
        temp->numberMessages = 0;
        head = temp;
    }
    else {
        printf("adding: %s (prev: %s)\n", countryName.c_str(), previous->name.c_str());
        Country* temp = new Country;
        temp->next = previous->next;
        temp->name = countryName;
        temp->message = "";
        temp->numberMessages = 0;
        previous->next = temp;   
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    // TODO
    insertCountry(NULL, "United States");
    insertCountry(CountryNetwork::searchNetwork("United States"), "Canada");
    insertCountry(CountryNetwork::searchNetwork("Canada"), "Brazil");
    insertCountry(CountryNetwork::searchNetwork("Brazil"), "India");
    insertCountry(CountryNetwork::searchNetwork("India"), "China");
    insertCountry(CountryNetwork::searchNetwork("China"), "Australia");
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    // TODO
    if (head == NULL) {
        printf("Empty list");
        return NULL;
    }
    else if (head->next == NULL) {
        if (head->name == countryName) {
            return head;
        }
        else { 
            return NULL; 
        }
    }
    else {
        Country* temp = head;
        while(temp->name != countryName) {
            if (temp->next == NULL) {
                return NULL;
            }
            temp = temp->next;
        }
        return temp;
    }
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    // TODO
    Country * temp = head;
    temp->message = message;
    temp->numberMessages++;
    printf("%s [# messages received: %d] received: %s\n", temp->name.c_str(), temp->numberMessages, temp->message.c_str());
    while (temp->name != receiver) {
        temp = temp->next;
        temp->numberMessages++;
        temp->message = message;
        printf("%s [# messages received: %d] received: %s\n", temp->name.c_str(), temp->numberMessages, temp->message.c_str());
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    // TODO
    printf("== CURRENT PATH ==\n");
    if (head == NULL) {
        printf("nothing in path\n===\n");
    }
    else {
        Country* temp = head;
        while (temp->next != NULL) {
            printf("%s -> ", temp->name.c_str());
            temp = temp->next;
        }
        printf("%s -> ", temp->name.c_str());
        printf("NULL\n===\n");
    }
}

/************************************************
           Definitions for main.cpp
************************************************/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

void displayMenu();  // declaration for main's helper-function
bool append(string* &str_arr, string s, int &numEntries, int &arraySize);




/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

bool append(string* &str_arr, string s, int &numEntries, int &arraySize) {
    //why are tabs 4 spaces?
    if (numEntries > arraySize) { return 0; }
    else if (numEntries == arraySize) {
        arraySize *= 2;
        string* temp = new string [arraySize];
        for (int i = 0; i < numEntries; i++) {
            *(temp + i) = *(str_arr + i);
        }
        *(temp + numEntries) = s;
        numEntries++;
        str_arr = temp;
        return 1;
    }
    else {
        *(str_arr + numEntries) = s;
        numEntries++;
        return 0;
    }
}