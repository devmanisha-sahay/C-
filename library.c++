#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

Book library[100];   // store up to 100 books
int countBooks = 0;

void addBook() {
    if (countBooks < 100) {
        cout << "Enter Book ID: ";
        cin >> library[countBooks].id;
        cin.ignore(); // clear buffer
        cout << "Enter Book Title: ";
        getline(cin, library[countBooks].title);
        cout << "Enter Author Name: ";
        getline(cin, library[countBooks].author);
        countBooks++;
        cout << "Book added successfully!\n";
    } else {
        cout << "Library is full!\n";
    }
}

void viewBooks() {
    if (countBooks == 0) {
        cout << "No books in library.\n";
        return;
    }
    cout << "\n--- Library Books ---\n";
    for (int i = 0; i < countBooks; i++) {
        cout << "ID: " << library[i].id
             << " | Title: " << library[i].title
             << " | Author: " << library[i].author << endl;
    }
}

void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    for (int i = 0; i < countBooks; i++) {
        if (library[i].id == id) {
            cout << "Book Found!\n";
            cout << "ID: " << library[i].id
                 << " | Title: " << library[i].title
                 << " | Author: " << library[i].author << endl;
            return;
        }
    }
    cout << "Book not found!\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: cout << "Exiting... Goodbye!\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}