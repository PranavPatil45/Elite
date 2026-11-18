
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    float marks;

    void accept()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const
    {
        cout << rollNo << "\t" << name << "\t" << marks << endl;
    }
};

int main()
{
    vector<Student> students;
    int choice, roll;
    Student s;

    do
    {
        cout << "\n--- Student Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Sort Students by Marks\n";
        cout << "5. Display Student with Highest Marks\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.accept();
            students.push_back(s);
            cout << "Student added successfully.\n";
            break;

        case 2:
            if (students.empty())
            {
                cout << "No student records found.\n";
                break;
            }

            cout << "\nRoll No\tName\tMarks\n";
            for (vector<Student>::iterator it = students.begin();
                 it != students.end(); ++it)
            {
                it->display();
            }
            break;

        case 3:
        {
            cout << "Enter Roll Number to Search: ";
            cin >> roll;

            bool found = false;

            for (vector<Student>::iterator it = students.begin();
                 it != students.end(); ++it)
            {
                if (it->rollNo == roll)
                {
                    cout << "\nStudent Found:\n";
                    it->display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";

            break;
        }

        case 4:
            sort(students.begin(), students.end(),
                 [](const Student &a, const Student &b)
                 {
                     return a.marks > b.marks;
                 });

            cout << "Students sorted by marks in descending order.\n";
            break;

        case 5:
            if (students.empty())
            {
                cout << "No student records found.\n";
                break;
            }

            {
                vector<Student>::iterator it =
                    max_element(students.begin(), students.end(),
                                [](const Student &a, const Student &b)
                                {
                                    return a.marks < b.marks;
                                });

                cout << "\nStudent with Highest Marks:\n";
                it->display();
            }
            break;

        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
