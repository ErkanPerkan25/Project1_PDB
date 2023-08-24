/*******************************************
 * Author: Eric Hansson
 * File: main.cpp
 * Date:
 * Purpose:
 *
********************************************/

#include <iostream>
#include <fstream>

using namespace std;

// add function
/*
void add(vector<string> infoList, ofstream book){
    book << infoList[2] << " " << infoList[3] << " " << infoList[4] << endl;
}
*/
// addBook
// addLibrary

// library function
// find function

int main(int argc, char *argv[]){
    
    ofstream books("booksDB.txt", ios::app);

    ofstream libraries("librariesDB.txt", ios::app);

    while(cin){
        // Input from command line of the program
        char command, subCommand;

        string text;
        cout << ">>> ";
        cin >> command;

        if(command == 'q')
            return 0;

        cin >> subCommand;
        // Gets the command line and stores it in 'input'
        getline(cin,text);
        // Debugging
        /*
        cout << command << endl;
        cout << subCommand << endl;
        cout << input << endl;

        */

        // ISBN and year, or just ISBN?
        // Just ISBN, if there is a book witht the same ISBN
        // there will be now multiple copies

        // if you put in the same book again, either overide it or ignore the add?
        // ignore the add

        //duplicates of books shall be ignored

        // For libraries the name is the uniqe, and if dubplicate ignore it, give prompt for it
        
        // For holding in libaries, if the book does not exist in, prompt that it won't be added
        // Same for if the library does not exist

        //string input;

        // Adding command
        if(command == 'a'){
            //cout << "You want to add a book" << endl;
            if(subCommand == 'b'){
                books << text << endl;
            }
            else if(subCommand == 'l'){
                libraries << text << endl;
            }
            else if(subCommand == 'h')
                cout << "You want to add a book to a specific libary" << endl;

        }

        // The list command
        else if(command == 'l'){
            ifstream readBooks("booksDB.txt");
            ifstream readLib("librariesDB.txt");

            string text;
            if(subCommand == 'b'){
               while(getline(readBooks,text)) 
                   cout << text << endl;
            }
            if (subCommand == 'l'){
               while(getline(readLib,text)) 
                   cout << text << endl;
            }
            readBooks.close();
            readLib.close();
        }

        else if(command == 'f'){
            cout << "You want find something" << endl;
        }


        //cout << input << endl;     
         
        // if "a", then check if it is a book, library, or "h"
        // if book, add all information about it to the file
        // if library, add the library to the file

        // if "l", then check if there is "b" or "l"
        // if "b", list all the books with all it's information
        // if "l", list all the libraries and their information
    }
    books.close();
    libraries.close();

    return 0;
}
