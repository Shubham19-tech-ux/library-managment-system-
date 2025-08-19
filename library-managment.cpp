
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    string author;
};

// Library class
class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        Book newBook = {id, title, author};
        books.push_back(newBook);
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "Books in the library:\n";
        for (const auto &book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
        }
    }

    void searchBook(int id) {
        for (const auto &book : books) {
            if (book.id == id) {
                cout << "Book found: ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(); // To ignore the newline character
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            cout << "Enter Book ID to search: ";
            cin >> id;
            library.searchBook(id);
            break;
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

