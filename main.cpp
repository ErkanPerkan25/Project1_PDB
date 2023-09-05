/*******************************************
 * Author: Eric Hansson
 * File: main.cpp
 * Date: 09/5/2023
 * Purpose: To build a program which creates files that stores data in to them.
 * The data is in forms of books, libraries, and holdings. You can insert
 * data in to the files and also read from the files.
 *
********************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// Function to find a ISBN in a line
bool findISBN(const string &line, const string &isbn){
    return line.find(isbn) != string::npos;
}

// Function to find Library by it's name in a line
bool findLib(const string &line, const string &lib){
    return line.find(lib) != string::npos;
}

int main(int argc, char *argv[]){

    // Creates output files where data will be stored 
    ofstream books("booksDB.txt", ios::app);
    ofstream libraries("librariesDB.txt", ios::app);
    ofstream holdings("holdingsDB.txt", ios::app);

    // Command line, where we can add, look, and find books and libraries
    while(cin){
        // Input from command line of the program
        char command, subCommand;

        // The prompt of the command line
        cout << ">>> ";
        // Reads in the first command
        cin >> command;

        // If q, then exit the program
        if(command == 'q')
            return 0;

        // Reads in the second command
        cin >> subCommand;

        // For libraries the name is the uniqe, and if dubplicate ignore it, give prompt for it
        
        // For holding in libaries, if the book does not exist in, prompt that it won't be added
        // Same for if the library does not exist

        // Command for adding books, libraries, and holdings
        if(command == 'a'){
            // To be read in for either a book, library, or holdning
            string isbn, author, bookTitle, library, city, zipCode;
            int year;

            // Command to add a book to book database
            if(subCommand == 'b'){
                // Reads in the ISBN, Year, Author, and the title for a book
                cin >> isbn;
                cin >> year;
                cin >> author;
                getline(cin,bookTitle);

                // Gets the book database file
                ifstream booklist("booksDB.txt");
                string line;
                
                // To check if a book already exist in the database
                bool bookExist = false;

                // Goes through the database to see if the book already exists
                while(getline(booklist,line)){
                    // Finds the isbn in the line, break, it already exists 
                    if(findISBN(line,isbn)){
                        bookExist = true;
                        break;
                    }
                }

                // If book exist, don't add it
                if(bookExist){
                }
                // Book don't exist, add it
                else{
                    books << isbn << " " << year << " " << author << "  " << bookTitle << endl;
                }

            }

            else if(subCommand == 'l'){
                // Reads in the library, city and zipcode
                cin >> library;
                cin >> city;
                cin >> zipCode;

                // Gets the libraries database file
                ifstream liblist("librariesDB.txt");
                // Varibale to read the lines in the database file
                string line;

                // To check if a library exists already
                bool libExist = false;
                
                // For libraries the name is the uniqe, and if dubplicate ignore it, give prompt for it
                while(getline(liblist,line)){
                    if(findLib(line,library)){
                        libExist = true;
                        liblist.close();
                        break;
                    }
                }
                
                //If library don't exist add it
                if(!libExist){
                    libraries << library << " " << city << " " << zipCode << endl;
                }

            }

            // Command to add books to a holding
            else if(subCommand == 'h'){
                // To read in and store the values for holdings
                string isbn, lib, lineHold, lineBook;
                // Reads in the ISBN and Library name
                cin >> isbn;
                cin >> lib;

                // Read in from the book database and holdings database
                ifstream file("booksDB.txt");
                ifstream hold("holdingsDB.txt");
                
                int copyNum = 1;
    
                // Goes through the holdings Database, and get the count of copies of the book
                while(getline(hold,lineHold)){
                    if(lineHold.find(isbn) != string::npos && lineHold.find(lib) != string::npos){
                        copyNum++;
                    }
                }

                // Addes the book to the holding database
                while(getline(file,lineBook)){
                    if(lineBook.find(isbn) != string::npos){
                        holdings << lib << ": " << lineBook << " Copy Number: " << copyNum << endl;
                    }
                }

                // Closes the input files
                file.close();
                hold.close();
            }
        }

        // Command to list books and libraries
        else if(command == 'l'){
            // Gets the book database and library database
            ifstream readBooks("booksDB.txt");
            ifstream readLib("librariesDB.txt");

            string text;
            // If it is books, print out the books
            if(subCommand == 'b'){
               while(getline(readBooks,text)) 
                   cout << text << endl;
            }

            // If it is the libraries, print out the libraries
            if(subCommand == 'l'){
               while(getline(readLib,text)) 
                   cout << text << endl;
            }
            // Closes the input files
            readBooks.close();
            readLib.close();
        }

        // Command to find a boook by its ISBN
        else if(command == 'f'){
            // To store ISBN and to read a line
            string isbn, line;

            // Reads in the ISBN
            cin >> isbn;
            
            // Get the holdings datanase
            ifstream holdFile("holdingsDB.txt");

            while(getline(holdFile,line)){
                // If you find the ISBN number on the line, print it out
                if(line.find(isbn) != string::npos){
                    cout << line << endl;
                }
            }
            // Closes the input file 
            holdFile.close();
        }
    }
    //Closes the output files
    books.close();
    libraries.close();
    holdings.close();

    return 0;
}
