
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
    int roll;
    char name[30];
    int marks[4];
    int total;

    void calculateTotal()
    {
        total = 0;

        for (int i = 0; i < 4; i++)
            total += marks[i];
    }

    void display()
    {
        cout << roll << "\t" << name << "\t" << total << endl;
    }
};

int main()
{
    Student s[100], temp;
    int n = 0;

    ifstream fin("students.txt");

    if (!fin)
    {
        cout << "Error opening file!";
        return 1;
    }

    while (n < 100 &&
           fin >> s[n].roll >> s[n].name >> s[n].marks[0] >> s[n].marks[1] >> s[n].marks[2] >> s[n].marks[3])
    {
        s[n].calculateTotal();
        n++;
    }

    fin.close();

    if (n == 0)
    {
        cout << "No student records found!";
        return 1;
    }

    int choice, sub;

    do
    {
        cout << "\n\n--- STUDENT MERIT MENU ---";
        cout << "\n1. Subject-wise merit list";
        cout << "\n2. Overall merit list";
        cout << "\n3. Topper of selected subject";
        cout << "\n4. Topper in all subjects";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter subject number (1-4): ";
            cin >> sub;

            if (sub < 1 || sub > 4)
            {
                cout << "Invalid subject!";
                break;
            }

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].marks[sub - 1] <
                        s[j + 1].marks[sub - 1])
                    {
                        temp = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = temp;
                    }
                }
            }

            cout << "\nRoll\tName\tMarks\n";

            for (int i = 0; i < n; i++)
            {
                cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].marks[sub - 1] << endl;
            }
            break;

        case 2:

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].total < s[j + 1].total)
                    {
                        temp = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = temp;
                    }
                }
            }

            cout << "\nOverall Merit List\n";
            cout << "Roll\tName\tTotal\n";

            for (int i = 0; i < n; i++)
                s[i].display();

            break;

        case 3:
            cout << "Enter subject number (1-4): ";
            cin >> sub;

            if (sub < 1 || sub > 4)
            {
                cout << "Invalid subject!";
                break;
            }

            {
                int topper = 0;

                for (int i = 1; i < n; i++)
                {
                    if (s[i].marks[sub - 1] >
                        s[topper].marks[sub - 1])
                    {
                        topper = i;
                    }
                }

                cout << "\nTopper of Subject " << sub << ": "
                     << s[topper].name << " - "
                     << s[topper].marks[sub - 1] << " marks";
            }

            break;

        case 4:
            cout << "\nTopper of Each Subject:\n";

            for (int i = 0; i < 4; i++)
            {
                int topper = 0;

                for (int j = 1; j < n; j++)
                {
                    if (s[j].marks[i] > s[topper].marks[i])
                        topper = j;
                }

                cout << "Subject " << i + 1 << ": "
                     << s[topper].name << " - "
                     << s[topper].marks[i] << " marks\n";
            }

            break;

        case 5:

            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}
