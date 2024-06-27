/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

void displayMenu();  // declaration for main's helper-function
bool append(string* &str_arr, string s, int &numEntries, int &arraySize);

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
                printf("\nCountry not found\n");
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