/*******************************************
 * Author: Eric Hansson
 * File: main.cpp
 * Date:
 * Purpose:
 *
********************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// add function
void add(vector<string> infoList){

}
// addBook
// addLibrary

// library function
// find function

int main(int argc, char *argv[]){
    
    ofstream books("bookdb.txt");
    ofstream libraries("librarydb.txt");

    while(cin){
        // Input from command line of the program
        string input, temp;
        vector<string> inputList;

        cout << ">>> ";
        // Gets the command line and stores it in 'input'
        getline(cin,input);

        stringstream stream(input);
        
        while(stream >> temp){
            inputList.push_back(temp);
        }


        if(inputList[0] == "a" && inputList[1] == "b"){
            //cout << "You want to add a book" << endl;
            books << inputList[2] << " " << inputList[3] << " " << inputList[4] << endl;
        }
        if(inputList[0] == "a" && inputList[1] == "l"){
            cout << "You want to add a library" << endl;
        }
        if(inputList[0] == "a" && inputList[1] == "h"){
            cout << "You want to add a book to a specific libary" << endl;
        }

        if(inputList[0] == "l"){
            cout << "You want list something" << endl;
        }

        if(inputList[0] == "f"){
            cout << "You want find something" << endl;
        }


        //cout << input << endl;     
         
        // if "a", then check if it is a book, library, or "h"
        // if book, add all information about it to the file
        // if library, add the library to the file

        // if "l", then check if there is "b" or "l"
        // if "b", list all the books with all it's information
        // if "l", list all the libraries and their information
        if(input == "q")
            return 0;
    }
    book.close();

    return 0;
}
