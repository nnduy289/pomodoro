#include "signUpIn.h"

ofstream myFile;
map<string, string> userAccount;

string enterFromUser(string &info){
    bool flagValid;
    do{
        getline(cin, info);
        flagValid = checkValidInfo(info);
        if(!flagValid)
            cout << "Invalid info, do it again" << '\n';
    }while(!flagValid);
    
    return info;
}

bool checkValidInfo(string &info){
    stringstream ss(info);
    string word;
    int8_t counter = 0;

    //check length of username and password
    if(info.length() < 8 || info.length() > 32){
        return false;
    }
    while(ss >> word){
        counter++;
    }
    if(counter > 1)
        return false;
    return true; 

}
bool checkExistInfo(string &info){
    string myText;
    ifstream myReadFile("account.txt");
    while(getline(myReadFile, myText)){
        stringstream ss(myText);
        string word;
        while(ss >> word){
            if(word == info){
                myReadFile.close();
                return true;
            }
        }
    }
    myReadFile.close();
    return false;
}

void saveToFile(string& username, string& password){
    myFile.open("account.txt", ios::app);
    myFile << "User name: " << username << " Password: " << password << '\n';
    myFile.close();  
}

//sign up
void signUp(string& username, string& password){
    cout << "Enter user name: ";
    enterFromUser(username);
    if(checkExistInfo(username)){
        cout << "Exist user name, use other name!" << '\n';
        return;
    }
    cout << "Valid user name!" << '\n';
    cout << "Enter password: ";
    enterFromUser(password);

    cout << "Sign up successfully!" << '\n';
    userAccount.insert(make_pair(username, password));
    saveToFile(username, password);
}