
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    int bookID;
    string title;
    string author;
    float price;
    bool available; // Encapsulated data member

public:
    // Default constructor
    Book()
    {
        bookID = 0;
        title = "";
        author = "";
        price = 0;
        available = true;
    }

    // Parameterized constructor
    Book(int id, string t, string a, float p)
    {
        bookID = id;
        title = t;
        author = a;
        price = p;
        available = true;
    }

    // Accept book details
    void acceptDetails()
    {
        cout << "\nEnter Book ID: ";
        cin >> bookID;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter Book Price: ";
        cin >> price;

        available = true;
    }

    // Return book ID for searching
    int getBookID()
    {
        return bookID;
    }

    // Display complete book information
    void display()
    {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPrice: " << price;

        cout << "\nAvailability: ";

        if (available)
            cout << "Available";
        else
            cout << "Issued";

        cout << "\n--------------------------";
    }

    // Issue a book
    void issueBook()
    {
        if (available)
        {
            available = false;
            cout << "\nBook issued successfully!";
        }
        else
        {
            cout << "\nBook is already issued!";
        }
    }

    // Return a book
    void returnBook()
    {
        if (!available)
        {
            available = true;
            cout << "\nBook returned successfully!";
        }
        else
        {
            cout << "\nBook is already available!";
        }
    }
};

int main()
{
    Book b[50];

    int n = 0;
    int choice, id, i;
    bool found;

    do
    {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Enter Book Details";
        cout << "\n2. Display All Books";
        cout << "\n3. Issue a Book";
        cout << "\n4. Return a Book";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter number of books: ";
            cin >> n;

            if (n > 50 || n < 1)
            {
                cout << "Invalid number of books!";
                n = 0;
                break;
            }

            for (i = 0; i < n; i++)
            {
                cout << "\nEnter details of Book " << i + 1;
                b[i].acceptDetails();
            }
            break;

        case 2:
            if (n == 0)
            {
                cout << "\nNo books available!";
                break;
            }

            for (i = 0; i < n; i++)
            {
                b[i].display();
            }
            break;

        case 3:
            cout << "\nEnter Book ID to issue: ";
            cin >> id;

            found = false;

            for (i = 0; i < n; i++)
            {
                if (b[i].getBookID() == id)
                {
                    b[i].issueBook();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nBook ID not found!";

            break;

        case 4:
            cout << "\nEnter Book ID to return: ";
            cin >> id;

            found = false;

            for (i = 0; i < n; i++)
            {
                if (b[i].getBookID() == id)
                {
                    b[i].returnBook();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nBook ID not found!";

            break;

        case 5:
            cout << "\nExiting Library Management System...";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 5);

    return 0;
}
