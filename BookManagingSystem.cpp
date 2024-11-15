#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 10;

struct Book
{
    string title;
    string author;
};

void addBook(Book books[], int &count)
{
    if (count >= MAX_BOOKS)
    {
        cout << "Book list is full.cannot add more books" << endl;
        return;
    }
    cout << "Enter book title:";
    cin.ignore();
    getline(cin, books[count].title);

    cout << "Enter book author:";
    getline(cin, books[count].author);

    count++;
    cout << "book added successfully" << endl;
}

void viewBooks(const Book books[], int count)
{
    if (count == 0)
    {
        cout << "No books to display." << endl;
        return;
    }
    cout << "Your Book List:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << ". " << books[i].title << " by " << books[i].author << endl;
    }
}

void searchBook(const Book books[], int count)
{
    if (count == 0)
    {
        cout << "No books to search." << endl;
        return;
    }

    string title;
    cout << "Enter book title to search:";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (books[i].title == title)
        {
            cout << "Found:" << books[i].title << "by" << books[i].author << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found." << endl;
    }
}

int main()
{
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add a Book\n";
        cout << "2. View Books\n";
        cout << "3. Search for a Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook(books, count);
            break;
        case 2:
            viewBooks(books, count);
            break;
        case 3:
            searchBook(books, count);
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}