/*
This file is basically the same as the hash_table
The only difference is the hash table has chaining
*/


#include <iostream>
#include "hashnode.h"
using namespace std;

int Hash(string name){
    int hash_code = name.length();
    return hash_code;
}

// Might change this global varaible later
hash_node * hash_table[10];

void fill_hash_table(){
    for (int i=0; i < 10; i++){
        hash_table[i] = NULL;
    }
}

void print_table(){
    cout << "**************************" << endl;
    for (int i=1; i < 11; i++){
        if (hash_table[i] == NULL){
            cout << i << ": (Empty)" << endl;
        }
        else{
            cout << i << ": " << hash_table[i]->name << endl;
        }
    }
}


void insert(hash_node *person){
    int index = Hash(person->name);
    if (hash_table[index] == NULL)
        hash_table[index] = person;
    else {
        // starting at 1 because adding 0 would be unnessary
        for (int i=1; i < 10; i++){
            int finding_spot = (i + index) % 10;
            if(hash_table[finding_spot] == NULL)
                hash_table[finding_spot] = person;
                return;
        }
    }
}

// Bravo on how the project is set up
// I didn't realize until I ran the program that the contains function no longer works
// Because of the chaining the names don't automaticaly match...
// This just became O(n)
bool contains(string name){
    int index = Hash(name);
    if (hash_table[index]->name == name){
        cout << name << " is in the table." << endl;
        return true;
    }
    for (int i=1; i < 10; i++){
        int finding_spot = (i + index) % 10;
        if (hash_table[finding_spot]->name == name){
            cout << name << " is in the table." << endl;
            return true;
        }
        else{
            cout << "Name not found." << endl;
            return false;
        }
    }
}

int main(){

// Testing the Hash funcion...
//     cout << "Name = Alan, length = " << Hash("Alan") << endl;
//     cout << "Name = Justin, length = " << Hash("Justin") << endl;
//     cout << "Name = Jace, length = " << Hash("Jace") << endl;
//     cout << "Name = Jessica, length = " << Hash("Jessica") << endl;

    hash_node alan;
    alan.name = "Alan";
    hash_node justin;
    justin.name = "Justin";
    hash_node jace;
    jace.name = "Jace";
    hash_node jessica;
    jessica.name = "Jessica";

    fill_hash_table();
    // commenting out the empty table
    // print_table();
    insert(&alan);
    insert(&justin);
    insert(&jessica);
    print_table();


    // This shows that index four of the array is being overwritten per assignment 7 criteria
    insert(&jace);
    print_table();
    cout << contains("Jace") << endl;
    cout << contains("Alan") << endl;
}
