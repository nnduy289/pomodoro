#include "signUp.h"

extern map<string, string> userAccount;

bool signIn(string& username, string& password){
    cout << "Enter user name: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    string myText;
    ifstream myReadFile("account.txt");
    getline(myReadFile, myText);
    stringstream ss(myText);
    string word;
    while(ss >> word){
        if(word == username){
            ss >> word; //skip "Password:"
            ss >> word; //get password
            if(word == password){
                myReadFile.close();
                return true;
            }
        }
    }
    myReadFile.close();
    return false;
}