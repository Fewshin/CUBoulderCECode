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