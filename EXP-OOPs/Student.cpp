#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    static const int SUBJECTS = 5;
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;

public:
    Student()
    {
        rollNo = 0;
        name = "";
        total = 0;
        percentage = 0;
        grade = 'F';
        for (int i = 0; i < SUBJECTS; i++)
        {
            marks[i] = 0;
        }
    }

    Student(int r, string n, float m[])
    {
        rollNo = r;
        name = n;
        for (int i = 0; i < SUBJECTS; i++)
        {
            marks[i] = m[i];
        }
        calculateTotal();
        calculatePercentage();
        calculateGrade();
    }

    void acceptDetails()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, name);

        cout << "Enter marks for " << SUBJECTS << " subjects (out of 100):\n";
        for (int i = 0; i < SUBJECTS; i++)
        {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }

        calculateTotal();
        calculatePercentage();
        calculateGrade();
        cout << "Details accepted successfully!\n";
    }

    void calculateTotal()
    {
        total = 0;
        for (int i = 0; i < SUBJECTS; i++)
        {
            total += marks[i];
        }
    }

    void calculatePercentage()
    {
        int max = SUBJECTS * 100;
        percentage = (total / max) * 100;
    }

    void calculateGrade()
    {
        if (percentage >= 90)
        {
            grade = 'A';
        }
        else if (percentage >= 80)
        {
            grade = 'B';
        }
        else if (percentage >= 70)
        {
            grade = 'C';
        }
        else if (percentage >= 60)
        {
            grade = 'D';
        }
        else if (percentage >= 40)
        {
            grade = 'E';
        }
        else
        {
            grade = 'F';
        }
    }

    void displayResult()
    {
        cout << "\n----------------------------------------\n";
        cout << "           STUDENT RESULT CARD          \n";
        cout << "----------------------------------------\n";
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
        cout << "Marks       : ";
        for (int i = 0; i < SUBJECTS; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Total Marks : " << total << " / " << (SUBJECTS * 100) << endl;
        cout << "Percentage  : " << percentage << "%" << endl;
        cout << "Grade       : " << grade << endl;
        cout << "----------------------------------------\n";
    }
};

int main()
{
    Student s;
    int choice;

    do
    {
        cout << "\n--- Student Management Menu ---\n";
        cout << "1. Enter/Update Student Details\n";
        cout << "2. Display Student Result\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.acceptDetails();
            break;
        case 2:
            s.displayResult();
            break;
        case 3:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
