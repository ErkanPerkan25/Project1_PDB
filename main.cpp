/*******************************************
 * Author: Eric Hansson
 * File: main.cpp
 * Date:
 * Purpose:
 *
********************************************/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    string input;

    while(cin){
        cout << ">>> ";
        cin >> input;

        if(input == "q")
            return 0;
    }

    return 0;
}
