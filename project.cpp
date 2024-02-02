#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 4;

string bookNames[MAX_BOOKS] = {"Eleven Minutes", "Enma", "Beloved", "Ulysses"};
string authors[MAX_BOOKS] = {"Author1", "Author2", "Author3", "Author4"};
string publishers[MAX_BOOKS] = {"Publisher1", "Publisher2", "Publisher3", "Publisher4"};
string ibans[MAX_BOOKS] = {"10", "20", "30", "40"};
int publishingYears[MAX_BOOKS] = {1990, 1995, 2000, 1992};
int editions[MAX_BOOKS] = {1, 2, 3, 4};
double prices[MAX_BOOKS] = {100.0, 150.0, 120.0, 500.0};
int quantities[MAX_BOOKS] = {4, 5, 6, 4};

string personType;
int rollNo, age;
string gender;

void displayBooks() {
    cout << "We Have Following Books in Library:" << endl;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Book " << i + 1 << " is " << bookNames[i] << endl;
        cout << "Iban No. of Book " << i + 1 << " is: " << ibans[i] << endl;
    }
}

void displayBookDetails(int bookIndex) {
    cout << "Iban No. of Book " << ibans[bookIndex] << " is: " << ibans[bookIndex] << endl;
    cout << "The Name of the Book is: " << bookNames[bookIndex] << endl;
    cout << "The Author of the Book is: " << authors[bookIndex] << endl;
    cout << "The Publisher of the Book is: " << publishers[bookIndex] << endl;
    cout << "The Price of the Book is: " << prices[bookIndex] << endl;
    cout << "The Publishing Year of the Book is: " << publishingYears[bookIndex] << endl;
    cout << "We Have " << quantities[bookIndex] << " Copies of this Book in Library" << endl;
}

void displayPersonDetails() {
    cout << "Roll No. Of The " << personType << " is: " << rollNo << endl;
    cout << "Age Of The " << personType << " is: " << age << endl;
    cout << "Gender Of The " << personType << " is " << gender << endl;
}

int findBookIndex(string iban) {
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (ibans[i] == iban) {
            return i;
        }
    }
    return -1; // Not found
}

void issueBook(int bookIndex, int quantity) {
    if (quantities[bookIndex] >= quantity) {
        quantities[bookIndex] -= quantity;
        cout << "Book Issued Successfully!\n";
    } else {
        cout << "Not Enough Copies Available.\n";
    }
}

void returnBook(int bookIndex, int quantity) {
    quantities[bookIndex] += quantity;
    cout << "Book Returned Successfully!\n";
}

int main() {
    cout << "Welcome To Library\n";
    cout << "Books are only Issueable to Students and Teachers\n";

    cout << "Please Enter 'student' if you are a student or 'teacher' if you are a teacher in Person Type: ";
    cin >> personType;

    cout << "Please Enter Your Roll No. Only in Numeric Value: ";
    cin >> rollNo;
    cout << "Enter Your Age: ";
    cin >> age;
    cout << "Enter Your Gender: ";
    cin >> gender;

    displayBooks();

    string iban;
    cout << "Enter Iban No. for Complete Details of the Book: ";
    cin >> iban;

    int bookIndex = findBookIndex(iban);
    if (bookIndex != -1) {
        displayBookDetails(bookIndex);

        char choice;
        cout << "Enter 'y' if You Want to Issue a Book or 'n' if You Want To Return a Book: ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            int quantity;
            cout << "Enter How Many Copies of the Books You Want To Issue: ";
            cin >> quantity;

            if (quantities[bookIndex] > 0 && quantity <= quantities[bookIndex]) {
                issueBook(bookIndex, quantity);
            } else {
                cout << "Invalid Quantity or Not Enough Copies Available.\n";
            }
        } else if (choice == 'n' || choice == 'N') {
            int quantity;
            cout << "Enter How Many Copies of the Books You Want To Return: ";
            cin >> quantity;

            returnBook(bookIndex, quantity);
        } else {
            cout << "Invalid Choice.\n";
        }
    } else {
        cout << "Book not found.\n";
    }

    displayPersonDetails();

    return 0;
}
