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
void find(string ISBN, ifstream file){
    
}

// library function
// find function

int main(int argc, char *argv[]){
    
    ofstream books("booksDB.txt", ios::app);

    ofstream libraries("librariesDB.txt", ios::app);

    ofstream holdings("holdingsDB.txt", ios::app);

    while(cin){
        // Input from command line of the program
        char command, subCommand;

        cout << ">>> ";
        cin >> command;

        if(command == 'q')
            return 0;

        cin >> subCommand;
        // Gets the command line and stores it in 'input'

        // if you put in the same book again, either overide it or ignore the add?
        // ignore the add

        //duplicates of books shall be ignored

        // For libraries the name is the uniqe, and if dubplicate ignore it, give prompt for it
        
        // For holding in libaries, if the book does not exist in, prompt that it won't be added
        // Same for if the library does not exist

        // Command for adding books, libraries, and holdings
        if(command == 'a'){
            string isbn, author, bookTitle, library, city, zipCode;
            int year;
            //cout << "You want to add a book" << endl;
            // Just ISBN, if there is a book witht the same ISBN
            // there will be no multiple copies
            // if you put in the same book again, either overide it or ignore the add?
            // ignore the add
            if(subCommand == 'b'){
                cin >> isbn;
                cin >> year;
                cin >> author;
                getline(cin,bookTitle);

                books << isbn << " " << year << " " << author << "  " << bookTitle << endl;
            }
            // For libraries the name is the uniqe, and if dubplicate ignore it, give prompt for it
            else if(subCommand == 'l'){
                cin >> library;
                cin >> city;
                cin >> zipCode;

                libraries << library << " " << city << " " << zipCode << endl;
            }
            // For holding in libaries, if the book does not exist in, prompt that it won't be added
            // Same for if the library does not exist
            else if(subCommand == 'h'){
                string isbn, lib, line;
                ifstream file("booksDB.txt");
                cin >> isbn;
                cin >> lib;
                int copyNum = 1;
                while(getline(file,line)){
                    if(line.find(isbn) != string::npos){
                        holdings << lib << ": " << line << " Copy Number: " << copyNum <<endl;
                    }
                    else if(!line.find(isbn)){
                        holdings << lib << ": " << line << " Copy Number: " << copyNum++ << endl;
                    }
                }
                // find the book by it's ISBN and check if there is a copy of it
                // else add the book as the first copy
                //holdings << lib << ": " << line << endl;
                file.close();
            }
        }

        // Command to list books and libraries
        else if(command == 'l'){
            ifstream readBooks("booksDB.txt");
            ifstream readLib("librariesDB.txt");

            string text;
            if(subCommand == 'b'){
               while(getline(readBooks,text)) 
                   cout << text << endl;
            }

            if(subCommand == 'l'){
               while(getline(readLib,text)) 
                   cout << text << endl;
            }
            readBooks.close();
            readLib.close();
        }

        // Command to find a boook by its ISBN
        else if(command == 'f'){
            string isbn, line;
            cin >> isbn;
            ifstream holdFile("holdingsDB.txt");

            while(getline(holdFile,line)){
                if(line.find(isbn) != string::npos){
                    cout << line << endl;
                    
                }
            }
                
            holdFile.close();
        }


    }
    books.close();
    libraries.close();
    holdings.close();

    return 0;
}
