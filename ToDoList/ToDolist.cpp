#include "../SignUpIn/signUp.h"

void showMainMenu(){
    cout << "======================" << '\n';
    cout << "1. Sign Up" << '\n';
    cout << "2. Sign In" << '\n';
    cout << "3. Exit" << '\n';
    cout << "======================" << '\n';
    cout << "Choose your option: ";
}

int main(void){
        string username, password;
        string myText;
        int option;
    while(true){
        showMainMenu();
        cin >> option;
        cin.ignore(); //clear buffer
        switch(option){
            case 1:
                signUp(username, password);
                break;
            case 2:
                if(signIn(username, password)){
                    cout << "Sign in successfully!" << '\n';
                }
                else{
                    cout << "Sign in failed!" << '\n';
                }
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid option, do it again!" << '\n';
        }
    }
}