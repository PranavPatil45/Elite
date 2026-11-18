
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    int id;
    char name[50];
    int age;

    void accept()
    {
        cout << "Enter ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Age: ";
        cin >> age;
    }

    void display()
    {
        cout << "ID: " << id << "\tName: " << name << "\tAge: " << age << endl;
    }
};

int main()
{
    int choice;
    Person p;

    do
    {
        cout << "\n\nPERSON MANAGEMENT";
        cout << "\n1. Add New Object";
        cout << "\n2. Display All Objects";
        cout << "\n3. Display Voting Eligible Persons";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ofstream fout("person.dat", ios::binary | ios::app);

            if (!fout)
            {
                cout << "Error opening file!";
                break;
            }

            p.accept();
            fout.write((char *)&p, sizeof(p));
            fout.close();

            cout << "Person added successfully!";
            break;
        }

        case 2:
        {
            ifstream fin("person.dat", ios::binary);

            if (!fin)
            {
                cout << "Error opening file!";
                break;
            }

            cout << "\nAll Person Records:\n";

            while (fin.read((char *)&p, sizeof(p)))
            {
                p.display();
            }

            fin.close();
            break;
        }

        case 3:
        {
            ifstream fin("person.dat", ios::binary);

            if (!fin)
            {
                cout << "Error opening file!";
                break;
            }

            cout << "\nVoting Eligible People:\n";

            while (fin.read((char *)&p, sizeof(p)))
            {
                if (p.age > 17)
                {
                    p.display();
                }
            }

            fin.close();
            break;
        }

        case 4:

            break;

        default:
            cout << "Invalid choice";
        }

    } while (choice != 4);

    return 0;
}
