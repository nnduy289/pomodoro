#ifndef SIGNUP_H
#define SIGNUP_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

class User{
    private:
        string      userName;
        string      passWord;
        int32_t     counterStreak;
    
    public:
        void setUserName(string &userName);
        string getUserName();
        void setPassWord(string &passWord);
        string getPassWord();
};

string enterFromUser(string &username);
bool checkValidInfo(string &info);
bool checkExistInfo(string &info);
void signUp(string& username, string& password);

bool signIn(string& username, string& password);
void saveToFile(string& username, string& password);
#endif