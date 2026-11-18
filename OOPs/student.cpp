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
        for (int i = 0; i < SUBJECTS; i++)
        {
            marks[i] = 0.0f;
        }
        total = 0.0f;
        percentage = 0.0f;
        grade = 'F';
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
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Full Name: ";
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
        else if (percentage >= 75)
        {
            grade = 'B';
        }
        else if (percentage >= 60)
        {
            grade = 'C';
        }
        else if (percentage >= 50)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
    }

    void displayResult()
    {

        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
        cout << "Marks in " << SUBJECTS << " subjects: ";
        for (int i = 0; i < SUBJECTS; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Total Marks : " << total << " / " << (SUBJECTS * 100) << endl;
        cout << "Percentage  : " << percentage << "%" << endl;
        cout << "Grade       : " << grade << endl;
    }
};

int main()
{
    Student student1;

    student1.acceptDetails();

    student1.displayResult();

    return 0;
}