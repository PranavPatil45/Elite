
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Book
{
protected:
    int bookID;
    string title, author;

public:
    Book(int id, string t, string a)
    {
        bookID = id;
        title = t;
        author = a;
    }

    int getID() const
    {
        return bookID;
    }

    string getTitle() const
    {
        return title;
    }

    // Overload == operator
    bool operator==(const Book &b) const
    {
        return bookID == b.bookID;
    }

    virtual void display() const
    {
        cout << bookID << "\t"
             << title << "\t"
             << author << "\t"
             << "Regular Book" << endl;
    }

    virtual void save(ofstream &file) const
    {
        file << bookID << ","
             << title << ","
             << author << ",B\n";
    }

    virtual ~Book() {}
};

class ReferenceBook : public Book
{
    string subject;

public:
    ReferenceBook(int id, string t, string a, string s)
        : Book(id, t, a)
    {
        subject = s;
    }

    void display() const override
    {
        cout << bookID << "\t"
             << title << "\t"
             << author << "\t"
             << "Reference Book\t"
             << subject << endl;
    }

    void save(ofstream &file) const override
    {
        file << bookID << ","
             << title << ","
             << author << ",R,"
             << subject << "\n";
    }
};

int main()
{
    vector<Book *> books;
    ifstream fin("books.txt");

    if (!fin)
    {
        cout << "Input file not found. Starting with an empty library.\n";
    }
    else
    {
        string line;

        while (getline(fin, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string field, title, author, type, subject;
            int id;

            if (!getline(ss, field, ','))
            {
                cout << "Invalid record skipped.\n";
                continue;
            }

            try
            {
                id = stoi(field);
            }
            catch (...)
            {
                cout << "Invalid book ID. Record skipped.\n";
                continue;
            }

            if (!getline(ss, title, ',') ||
                !getline(ss, author, ',') ||
                !getline(ss, type, ','))
            {
                cout << "Invalid record skipped.\n";
                continue;
            }

            Book *b = nullptr;

            if (type == "B")
            {
                b = new Book(id, title, author);
            }
            else if (type == "R")
            {
                if (!getline(ss, subject))
                {
                    cout << "Missing subject. Record skipped.\n";
                    continue;
                }

                b = new ReferenceBook(id, title, author, subject);
            }
            else
            {
                cout << "Invalid book type. Record skipped.\n";
                continue;
            }

            bool duplicate = false;

            for (Book *existing : books)
            {
                if (*existing == *b)
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "Duplicate book ID skipped: " << id << endl;
                delete b;
            }
            else
            {
                books.push_back(b);
            }
        }

        fin.close();
    }

    int choice;

    do
    {
        cout << "\n--- LIBRARY MANAGEMENT ---\n";
        cout << "1. Display All Books\n";
        cout << "2. Search Book by ID\n";
        cout << "3. Add New Book\n";
        cout << "4. Save Books to File\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sort(books.begin(), books.end(),
                 [](Book *a, Book *b)
                 {
                     return a->getTitle() < b->getTitle();
                 });

            cout << "\nID\tTitle\tAuthor\tType\t\tSubject\n";

            for (Book *b : books)
                b->display();

            break;

        case 2:
        {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;

            Book key(id, "", "");
            bool found = false;

            for (Book *b : books)
            {
                if (*b == key)
                {
                    cout << "\nBook Found:\n";
                    b->display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Book not found.\n";

            break;
        }

        case 3:
        {
            int id, type;
            string title, author, subject;

            cout << "Enter Book ID: ";
            cin >> id;

            Book key(id, "", "");
            bool duplicate = false;

            for (Book *b : books)
            {
                if (*b == key)
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "Book ID already exists.\n";
                break;
            }

            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "1. Regular Book\n";
            cout << "2. Reference Book\n";
            cout << "Enter type: ";
            cin >> type;
            cin.ignore();

            if (type == 1)
            {
                books.push_back(new Book(id, title, author));
                cout << "Book added successfully.\n";
            }
            else if (type == 2)
            {
                cout << "Enter Subject: ";
                getline(cin, subject);

                books.push_back(
                    new ReferenceBook(id, title, author, subject));

                cout << "Reference book added successfully.\n";
            }
            else
            {
                cout << "Invalid book type.\n";
            }

            break;
        }

        case 4:
        {
            ofstream fout("books.txt");

            if (!fout)
            {
                cout << "Error opening output file.\n";
                break;
            }

            for (Book *b : books)
                b->save(fout);

            fout.close();

            cout << "Books saved successfully.\n";
            break;
        }

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

        for (Book *b : books)
        delete b;

    return 0;
}
