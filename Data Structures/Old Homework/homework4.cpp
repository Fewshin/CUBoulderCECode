//Copy your deleteCountry function into the box below.

void CountryNetwork::deleteCountry(string countryName) {
    //TODO: Complete this function
    Country* ptr = head;
    Country* sto = ptr;
    if (head->name == countryName) {
        head = head->next;
    }
    else {
        while (ptr != NULL && ptr->name != countryName) {
            sto = ptr;
            ptr = ptr->next;
        }
        if (ptr != NULL) sto->next = ptr->next;
        else printf("Country does not exist.\n");   
    }
}

//Copy your deleteEntireNetwork function into the box below. If you invoke deleteCountry, you must include that function as well.

void CountryNetwork::deleteEntireNetwork()
{
    //TODO: Complete this function
    Country * temp = head;
    Country * sto = temp;
    head = NULL;
    while (temp != NULL) {
        printf("deleting: %s\n", temp->name.c_str());
        temp = NULL;
        sto = sto->next;
        temp = sto;
    }
    if (head == NULL) printf("Deleted network\n");
}

//Copy your createLoop function into the box below.

Country* CountryNetwork::createLoop(string countryName)
{
    //TODO: Complete this function
    Country * ptr = head;
    Country * sto = ptr;
    while (ptr != NULL) {
        sto = ptr;
        ptr = ptr->next;
    }
    sto->next = head;
}

//Copy your detectLoop function into the box below.

bool CountryNetwork::detectLoop() {
    //TODO: Complete this function
    Country* ptr = head;
    Country* sto = ptr;
    while (ptr != NULL && ptr->name != head->name) {
        sto = ptr;
        ptr = ptr->next;
    }
    if (ptr->name == head->name || sto->next != NULL) return 1;
    else return 0;
}