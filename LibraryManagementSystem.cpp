#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool available;

    Book(const string& t, const string& a, const string& i)
        : title(t), author(a), ISBN(i), available(true) {}
};

class Borrower {
public:
    string name;
    int borrowedBooks;

    Borrower(const string& n) : name(n), borrowedBooks(0) {}
};

class Transaction {
public:
    Book* book;
    Borrower* borrower;
    time_t checkoutDate;
    time_t returnDate;

    Transaction(Book* b, Borrower* br)
        : book(b), borrower(br), checkoutDate(time(nullptr)), returnDate(0) {}
};

class Library {
public:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;

    void addBook(const string& title, const string& author, const string& ISBN) {
        books.emplace_back(title, author, ISBN);
    }

    Book* findBook(const string& searchKey) {
        for (auto& book : books) {
            if (book.title == searchKey || book.author == searchKey || book.ISBN == searchKey) {
                return &book;
            }
        }
        return nullptr;
    }

    Borrower* findBorrower(const string& name) {
        auto it = find_if(borrowers.begin(), borrowers.end(), [&](const Borrower& b) {
            return b.name == name;
        });
        if (it != borrowers.end()) {
            return &(*it);
        }
        return nullptr;
    }

    void checkoutBook(Book* book, Borrower* borrower) {
        if (book && borrower && book->available) {
            book->available = false;
            borrower->borrowedBooks++;
            transactions.emplace_back(book, borrower);
            cout << "Book checked out successfully." << endl;
        } else {
            cout << "Book not available or borrower not found." << endl;
        }
    }

    void returnBook(Book* book) {
        auto it = find_if(transactions.begin(), transactions.end(), [&](const Transaction& t) {
            return t.book == book && t.returnDate == 0;
        });

        if (it != transactions.end()) {
            it->returnDate = time(nullptr);
            book->available = true;
            it->borrower->borrowedBooks--;
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Transaction not found. Invalid return." << endl;
        }
    }

    void calculateFine(const Transaction& transaction) {
        const double fineRatePerDay = 0.5;
        time_t dueDate = transaction.checkoutDate + 14 * 24 * 60 * 60; 
        time_t currentDate = time(nullptr);

        if (currentDate > dueDate && transaction.returnDate == 0) {
            double fine = fineRatePerDay * difftime(currentDate, dueDate);
            cout << "Fine for overdue book: $" << fine << endl;
        } else {
            cout << "No fine for this transaction." << endl;
        }
    }

    void displayMenu() {
        cout << "\n=== Library Management System ===" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Checkout a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Add a new book" << endl;
        cout << "5. Exit" << endl;
    }

    void run() {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice (1-5): ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    cin.ignore(); 
                    cout << "Enter the title, author, or ISBN to search for a book: ";
                    string searchKey;
                    getline(cin, searchKey);
                    Book* foundBook = findBook(searchKey);
                    if (foundBook) {
                        cout << "Book found: " << foundBook->title << " by " << foundBook->author << endl;
                    } else {
                        cout << "Book not found." << endl;
                    }
                    break;
                }
                case 2: {
                    cin.ignore(); 
                    cout << "Enter borrower name: ";
                    string borrowerName;
                    getline(cin, borrowerName);
                    Borrower* borrower = findBorrower(borrowerName);
                    if (borrower) {
                        cout << "Borrower found: " << borrower->name << endl;

                        cout << "Enter the title, author, or ISBN of the book to checkout: ";
                        string bookSearchKey;
                        getline(cin, bookSearchKey);
                        Book* bookToCheckout = findBook(bookSearchKey);
                        checkoutBook(bookToCheckout, borrower);
                    } else {
                        cout << "Borrower not found." << endl;
                    }
                    break;
                }
                case 3: {
                    cin.ignore();  
                    cout << "Enter the title, author, or ISBN of the book to return: ";
                    string bookSearchKey;
                    getline(cin, bookSearchKey);
                    Book* bookToReturn = findBook(bookSearchKey);
                    if (bookToReturn) {
                        returnBook(bookToReturn);
                    } else {
                        cout << "Book not found." << endl;
                    }
                    break;
                }
                case 4: {
                    cin.ignore(); 
                    cout << "Enter the title of the new book: ";
                    string newTitle;
                    getline(cin, newTitle);
                    cout << "Enter the author of the new book: ";
                    string newAuthor;
                    getline(cin, newAuthor);
                    cout << "Enter the ISBN of the new book: ";
                    string newISBN;
                    getline(cin, newISBN);
                    addBook(newTitle, newAuthor, newISBN);
                    cout << "New book added successfully." << endl;
                    break;
                }
                case 5:
                    cout << "Exiting the Library Management System. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    Library library;

    
    library.addBook("The Catcher in the Rye", "J.D. Salinger", "978-0-316-76948-0");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "978-0-06-112008-4");
    library.addBook("1984", "George Orwell", "978-0-452-28423-4");

    
    library.borrowers.emplace_back("krishna");
    library.borrowers.emplace_back("gaurav");


    library.checkoutBook(library.findBook("1984"), library.findBorrower("Alice"));

    
    library.run();

    return 0;
}
