#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int roll;
    string name;
    int marks[4];
    int total;
};

int main()
{
    Student s[100], temp;
    int n = 0, choice, subject;

    string subjects[4] = {"Subject 1", "Subject 2", "Subject 3", "Subject 4"};

    ifstream file("students.txt");

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    while (n < 100 &&
           file >> s[n].roll >> s[n].name >> s[n].marks[0] >> s[n].marks[1] >> s[n].marks[2] >> s[n].marks[3])
    {
        s[n].total = 0;

        for (int j = 0; j < 4; j++)
        {
            s[n].total += s[n].marks[j];
        }

        n++;
    }

    file.close();

    if (n == 0)
    {
        cout << "No student found" << endl;
        return 1;
    }

    do
    {
        cout << "\n1. Subject wise Merit List\n";
        cout << "2. Overall Merit List\n";
        cout << "3. Topper of a Selected Subject\n";
        cout << "4. Topper in All Subjects\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nSelect Subject (1-4): ";
            cin >> subject;

            if (subject < 1 || subject > 4)
            {
                cout << "Invalid subject!" << endl;
                break;
            }

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (s[j].marks[subject - 1] < s[j + 1].marks[subject - 1])
                    {
                        temp = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = temp;
                    }
                }
            }

            cout << "\nMerit List - " << subjects[subject - 1] << "\n";
            cout << "Roll\tName\tMarks\n";

            for (int i = 0; i < n; i++)
            {
                cout << s[i].roll << "\t"
                     << s[i].name << "\t"
                     << s[i].marks[subject - 1] << endl;
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
            {
                cout << s[i].roll << "\t"
                     << s[i].name << "\t"
                     << s[i].total << endl;
            }
            break;

        case 3:
            cout << "\nSelect Subject (1-4): ";
            cin >> subject;

            if (subject < 1 || subject > 4)
            {
                cout << "Invalid subject!" << endl;
                break;
            }

            {
                int topper = 0;

                for (int i = 1; i < n; i++)
                {
                    if (s[i].marks[subject - 1] >
                        s[topper].marks[subject - 1])
                    {
                        topper = i;
                    }
                }

                cout << "\nTopper of " << subjects[subject - 1] << ": " << s[topper].name << " (" << s[topper].marks[subject - 1] << ")" << endl;
            }
            break;

        case 4:
            cout << "\nSubject-wise Toppers\n";

            for (int j = 0; j < 4; j++)
            {
                int topper = 0;

                for (int i = 1; i < n; i++)
                {
                    if (s[i].marks[j] > s[topper].marks[j])
                    {
                        topper = i;
                    }
                }

                cout << subjects[j] << ": " << s[topper].name << " " << s[topper].marks[j] << endl;
            }
            break;

        case 5:

            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}