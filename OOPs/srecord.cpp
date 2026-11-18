
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

class Person
{
protected:
    int rollNo;
    string name;

public:
    Person()
    {
        rollNo = 0;
        name = "";
    }
};

class Student : public Person
{
    int marks[3];
    int total;

public:
    Student()
    {
        marks[0] = marks[1] = marks[2] = 0;
        total = 0;
    }

    void accept(int r, string n, int m1, int m2, int m3)
    {
        if (m1 < 0 || m1 > 100 ||
            m2 < 0 || m2 > 100 ||
            m3 < 0 || m3 > 100)
        {
            throw invalid_argument("Marks must be between 0 and 100.");
        }

        rollNo = r;
        name = n;

        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;

        total = m1 + m2 + m3;
    }

    int getRollNo() const
    {
        return rollNo;
    }

    int getTotal() const
    {
        return total;
    }

    // Overload < operator
    bool operator<(const Student &s) const
    {
        return total > s.total;
    }

    void display() const
    {
        cout << rollNo << "\t"
             << name << "\t"
             << marks[0] << "\t"
             << marks[1] << "\t"
             << marks[2] << "\t"
             << total << endl;
    }

    void writeToFile(ofstream &file) const
    {
        file << rollNo << ","
             << name << ","
             << marks[0] << ","
             << marks[1] << ","
             << marks[2] << ","
             << total << "\n";
    }
};

int main()
{
    vector<Student> students;
    ifstream fin("students.txt");

    if (!fin)
    {
        cout << "Error opening input file.\n";
        return 1;
    }

    string line;

    try
    {
        while (getline(fin, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string field;
            string name;
            int roll, m1, m2, m3;

            if (!getline(ss, field, ','))
                throw runtime_error("Invalid record format.");

            roll = stoi(field);

            if (!getline(ss, name, ',') ||
                !getline(ss, field, ','))
                throw runtime_error("Invalid record format.");

            m1 = stoi(field);

            if (!getline(ss, field, ','))
                throw runtime_error("Invalid record format.");

            m2 = stoi(field);

            if (!getline(ss, field))
                throw runtime_error("Invalid record format.");

            m3 = stoi(field);

            Student s;
            s.accept(roll, name, m1, m2, m3);

            students.push_back(s);
        }

        fin.close();

        // Sort in descending order using overloaded <
        sort(students.begin(), students.end());

        // Display merit list
        cout << "\n--- STUDENT MERIT LIST ---\n";
        cout << "Roll\tName\tM1\tM2\tM3\tTotal\n";

        for (vector<Student>::iterator it = students.begin();
             it != students.end(); ++it)
        {
            it->display();
        }

        // Search by roll number
        int roll;
        cout << "\nEnter roll number to search: ";
        cin >> roll;

        bool found = false;

        for (vector<Student>::iterator it = students.begin();
             it != students.end(); ++it)
        {
            if (it->getRollNo() == roll)
            {
                cout << "\nStudent Found:\n";
                cout << "Roll\tName\tM1\tM2\tM3\tTotal\n";
                it->display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Student not found.\n";

        // Save sorted merit list
        ofstream fout("merit_list.txt");

        if (!fout)
            throw runtime_error("Error creating output file.");

        fout << "Roll,Name,Marks1,Marks2,Marks3,Total\n";

        for (vector<Student>::iterator it = students.begin();
             it != students.end(); ++it)
        {
            it->writeToFile(fout);
        }

        fout.close();

        cout << "\nMerit list saved to merit_list.txt\n";
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
        fin.close();
        return 1;
    }

    return 0;
}
