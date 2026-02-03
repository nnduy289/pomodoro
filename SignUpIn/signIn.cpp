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
        cout << "Enter valid number (number > 0): ";
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
            if(flagIsInt){
                optionNumber = stoi(option);
                if(optionNumber <= 0){
                    flagIsInt = false;
                }else return optionNumber;
            }
        }
    }while(!flagIsInt);
}

void showMenu(){
    cout << "======================" << '\n';
    cout << "=====================" << '\n';
    cout << "1. Set your ToDoList" << '\n';
    cout << "2. Set your daily Goal (time)" << '\n';
    cout << "3. See your streak!" << '\n';
    cout << "4. Exit" << '\n';
    cout << "======================" << '\n';
    cout << "Choose your option: ";
}

void showMenuTimer(){
    cout << "======================" << '\n';
    cout << "=========TIMER==========" << '\n';
    cout << "1. Set your Pomo" << '\n';
    cout << "2. Set your daily goal time!\n";
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
        int         counterStreak = 0;
        int         timeFocus = 0;
        int         timeRelax = 0;
        int         dailyTotalTime = 0;
        int         dailyGoalTime = 0;
        bool        flagPomoDone = false;
        
    public:
        void setUserName(string &userName);
        string getUserName();
        void setPassWord(string &passWord);
        string getPassWord();
        
        void setToDoList();
        void getToDoList();
        void removeToDoList();
      
        void setTimer();
        int getTimer();
        void startTimer();

        void setDailyGoalTime();
        int getDialyGoalTime();

        void restoreStreakFromFile();
        void saveStreakToFile();
        void setStreak();
        int getStreak();
        void checkStreak();
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
        if(option > vecToDo.size() || option == 0){
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
    while(getline(myReadFile, myText)){
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
    }
    myReadFile.close();
    return false;
}

void User::setTimer(){
    cout << "Time focus: ";
    this->timeFocus = getOptionFromUser();
    cout << "Time relax: ";
    this->timeRelax = getOptionFromUser();
}

void User::startTimer(){
    cout << "Focus!!!\n";
    countDownTimer(this->timeFocus);
    cout << "Relax~~~\n";
    countDownTimer(this->timeRelax);
}

int User::getTimer(){
    return this->timeFocus;
}

void User::setDailyGoalTime(){
    this->dailyGoalTime = getOptionFromUser();
}

int User::getDialyGoalTime(){
    return this->dailyGoalTime;
}

void User::checkStreak(){
    restoreStreakFromFile();
    
    this->dailyTotalTime += this->timeFocus;
    if(this->dailyTotalTime >= this->dailyGoalTime && this->dailyGoalTime > 0){
        this->counterStreak++;

        cout << "Congratulations! You have achieved your daily goal time!\n";
        cout << "Your current streak is: " << this->counterStreak << " days!\n";
    }else{
        cout << "You have not achieved your daily goal time yet. Keep trying!\n";
        cout << "Your current streak remains: " << this->counterStreak << " days.\n";
    }
    saveStreakToFile();
}
int User::getStreak(){
    restoreStreakFromFile();
    return this->counterStreak;
}

void User::saveStreakToFile(){
    ofstream myFile("streak.txt");
    myFile << this->userName << " " << this->counterStreak << '\n';
    myFile.close();
}

void User::restoreStreakFromFile(){
    string myText;
    ifstream myReadFile("streak.txt");
    while(getline(myReadFile, myText)){
        stringstream ss(myText);
        string word;
        ss >> word;
        if(word == this->userName){
            ss >> word;
            this->counterStreak = stoi(word);
            myReadFile.close();
            return;
        }
    }
    myReadFile.close();
}

void User::setStreak(){
    this->counterStreak = getOptionFromUser();
}

void userTimer(User &pom){
    while(true){
        showMenuTimer();
        int option = getOptionFromUser();
        
        switch(option){
            case 1:
                pom.setTimer();
                break;
            case 2:
                cout << "Set your daily goal time (in minutes): ";
                pom.setDailyGoalTime();
                break;
            case 3:
                if(pom.getTimer() <= 0){
                    pom.setTimer();
                }
                cout << "START~!!!\n";
                pom.startTimer();
                pom.checkStreak();
                break;
            case 4:
                return;
            default:
                break;
        }
    }
}
void userTodo(User &pom){
    while(true){
    showMenuTodo();
        int option = getOptionFromUser();
            switch(option){
            case 1:
                cout << "What do you want to do ? Type below:\n";
                pom.setToDoList();
                break;
            case 2:
                pom.removeToDoList();
                break;
            case 3:
                pom.getToDoList();
                break;
            case 4:
                return;
            default:
                break;
            
        }
    }    
}
void handleUserAfterSignIn(string &username, string &password){
    User pom;
    pom.setUserName(username);
    pom.setPassWord(password);

    while(true){
        showMenu();
        int option = getOptionFromUser();
        switch (option)
        {
        case 1:
            userTodo(pom);
            break;
        case 2:
            userTimer(pom);
            break;
        case 3:
            cout << "Your current streak is: " << pom.getStreak() << " days!\n";
            break;
        case 4:
            return;
        default:
            cout << "Invalid option, type again\n";
            break;
        }
    }
     
}