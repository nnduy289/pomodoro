#include "signUpIn.h"
#include "../Timer/timer.h"
#include <vector>

vector<string> vecToDo;


//get option from 1 
int getOptionFromUser(){
    int counter = 0;
    int optionNumber;
    string option;
    bool flagIsInt;
    do{
        flagIsInt = true;
        getline(cin, option);
        stringstream ss;
        string word;
        while(ss >> word){
            counter++;
            if(counter > 1){
                cout << "Invalid option\n";
                flagIsInt = false;
                break;
            }
        }
        //if flag is true, continue check each alphabet in string, otherwise loop again
        if(flagIsInt){
            for(int i = 0; i < option.length(); i++){
                if(option[i] < '0' || option[i] > '9'){
                cout << "Invalid option\n";
                flagIsInt = false;
                break;
                }
            }
        }
    
    
    }while(!flagIsInt);
    optionNumber = stoi(option);
    if(optionNumber >= 1){
        return optionNumber;
    }else{
        getOptionFromUser();
    }
}

void showMenu(){
    
}

void showMenuTimer(){
    cout << "======================" << '\n';
    cout << "=========TIMER==========" << '\n';
    cout << "1. Set time for flow" << '\n';
    cout << "2. Set time for relax" << '\n';
    cout << "3. Start YOUR POM ?" << '\n';
    cout << "4. Exit" << '\n';
    cout << "======================" << '\n';
    cout << "Choose your option: ";
}

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
        int         counterStreak;
        int         time;
    
    public:
        void setUserName(string &userName);
        string getUserName();
        void setPassWord(string &passWord);
        string getPassWord();
        
        void setToDoList();
        void getToDoList();
        void removeToDoList();
      
        void setTimer();
        void startTimer();
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
        cout << "Empty ToDoList, please add your work to do!" << '\n';
        return;
    }
    for(it = vecToDo.begin(); it != vecToDo.end(); it++){
        cout << ++counter << ". " << *it << '\n';
    }
}

void User::removeToDoList(){
    if(vecToDo.size() == 0){
        cout << "Don't have anything to remove here, add your work please!\n";
        return;
    }
    getToDoList();
    cout << "What thing you want to remove ? \n";
    cout << "Choose the line: ";
    int option;
    do{
        option = getOptionFromUser();
        if(option > vecToDo.size()){
            cout << "Please Enter exact line want to erase: ";
        }
    } 
    while(option > vecToDo.size());
        
    vecToDo.erase(vecToDo.begin()+ option -1);
    getToDoList();
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

void User::setTimer(){
    this->time = getOptionFromUser();
}

void User::startTimer(){
    countDownTimer(this->time);
}

void handleUserAfterSignIn(string &username, string &password){
    User pom;
    pom.setUserName(username);
    pom.setPassWord(password);

    // while(true){
    //     showMenuTodo();
    //     int option = getOptionFromUser();
    //     switch(option){
    //         case 1:
    //             cout << "What do you want to do ? Type below:\n";
    //             pom.setToDoList();
    //             break;
    //         case 2:
    //             pom.removeToDoList();
    //             break;
    //         case 3:
    //             pom.getToDoList();
    //             break;
    //         case 4:
    //             return;
    //         default:
    //             break;
            
    //     }
    // }
     while(true){
        showMenuTimer();
        int option = getOptionFromUser();
        switch(option){
            case 1:
                cout << "How many time do you want to set? Type below:\n";
                pom.setTimer();
                break;
            case 2:
                break;
            case 3:
                cout << "START~!!!\n";
                pom.startTimer();
                break;
            case 4:
                return;
            default:
                break;
            
        }
    }
}