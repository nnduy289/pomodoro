#ifndef SIGNUPIN_H
#define SIGNUPIN_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

string enterFromUser(string &username);
bool checkValidInfo(string &info);
bool checkExistInfo(string &info);
void signUp(string& username, string& password);

int getOptionFromUser();


bool signIn(string& username, string& password);
void saveToFile(string& username, string& password);
void handleUserAfterSignIn(string &username, string &password);
#endif