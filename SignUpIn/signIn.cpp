#include "signUpIn.h"
#include <vector>

vector<string> vecToDo;

void showMenuTodo(){
    cout << "======================" << '\n';
    cout << "=========TO DO LIST==========" << '\n';
    cout << "1. Add what you want to do!" << '\n';
    cout << "2. Remove what you have done!" << '\n';
    cout << "3. Get your to do list!" << '\n';
    cout << "4. Exit" << '\n';
    cout << "======================" << '\n';
    cout << "Choose your option: ";
}

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
        
        void setToDoList();
        void getToDoList();
        void removeToDoList();
      //  void setTimer();
};

void User::setUserName(string &userName){
    this->userName = userName;
}
string User::getUserName(){
    return this->userName;
}
void User::setPassWord(string &passWord){
    this->passWord = passWord;
}

string User::getPassWord(){
    return this->passWord;
}

void User::setToDoList(){
    string whatToDo;
    getline(cin, whatToDo);
    vecToDo.push_back(whatToDo);
}

void User::getToDoList(){
    vector<string>::iterator it;
    int counter = 0;
    if(vecToDo.size() == 0){
        cout << "Please add your work to do!" << '\n';
        return;
    }
    for(it = vecToDo.begin(); it != vecToDo.end(); it++){
        cout << ++counter << ". " << *it << '\n';
    }
}

void User::removeToDoList(){
    char option;
    cout << "What thing you want to remove ? \n";
    do{
        cin >> option;
        cin.ignore();
        if(option < '1' || option > '9'){
            cout << "Invalid option\n";
        }
    }while(option < '1' || option > '9');
    int num = option - 48;
    vecToDo.erase(vecToDo.begin()+ num -1);
}

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

void handleUserAfterSignIn(string &username, string &password){
    User pom;
    pom.setUserName(username);
    pom.setPassWord(password);

    while(true){
        showMenuTodo();
        int option;
        cin >> option; //cần viết một hàm để check input nhập vào từ user vụ option này
        cin.ignore();
        switch(option){
            case 1:
                pom.setToDoList();
                break;
            case 2:
                pom.removeToDoList();
                break;
            case 3:
                pom.getToDoList();
            case 4:
                return;
            default:
                break;
            
        }
    }
}