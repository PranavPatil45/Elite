#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Person
{
    int id;
    string name;
    int age;
};
int main()
{
    Person people[100];
    Person temp;
    int choice, n = 0;

    ifstream file("ages.txt");
    if (!file.is_open())
    {
        cout << "Error could not open file" << endl;
        return 1;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string id, name, age;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        people[n].id = stoi(id);
        people[n].name = name;
        people[n].age = stoi(age);
        n++;
    }
    file.close();

    do
    {
        cout << "\n--- MENU ---";
        cout << "\n1. Display Youngest to Oldest";
        cout << "\n2. Display Oldest to Youngest";
        cout << "\n3. Who can vote?";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (people[j].age > people[j + 1].age)
                    {
                        temp = people[j];
                        people[j] = people[j + 1];
                        people[j + 1] = temp;
                    }
                }
            }

            cout << "\nID\tName\tAge\n";
            for (int i = 0; i < n; i++)
            {
                cout << people[i].id << "\t"
                     << people[i].name << "\t"
                     << people[i].age << endl;
            }
            break;
        case 2:
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (people[j].age < people[j + 1].age)
                    {
                        temp = people[j];
                        people[j] = people[j + 1];
                        people[j + 1] = temp;
                    }
                }
            }
            cout << "\nID\tName\tAge\n";
            for (int i = 0; i < n; i++)
            {
                cout << people[i].id << "\t"
                     << people[i].name << "\t"
                     << people[i].age << endl;
            }
            break;
        case 3:
            cout << "\nPeople eligible to vote:\n";
            cout << "\nID\tName\tAge\n";

            for (int i = 0; i < n; i++)
            {
                if (people[i].age >= 18)
                {
                    cout << people[i].id << "\t"
                         << people[i].name << "\t"
                         << people[i].age << endl;
                }
            }
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}