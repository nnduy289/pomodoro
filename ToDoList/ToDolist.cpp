#include "../SignUpIn/signUp.h"

int main(void){
    while(1){
        cout << "Hello  World" << '\n';
        string username, password;
        string myText;
        signUp(username, password);

        ifstream myReadFile("account.txt");
        while(getline(myReadFile, myText)){
            cout << myText << '\n';
        }
        myReadFile.close();
    }
    
}