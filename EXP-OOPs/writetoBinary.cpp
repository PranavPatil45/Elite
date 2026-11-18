
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Person
{
public:
    int id;
    char name[50];
    int age;
};

int main()
{
    ifstream fin("person.csv");
    ofstream fout("person.dat", ios::binary);

    if (!fin || !fout)
    {
        cout << "Error opening file!";
        return 1;
    }

    string line, id, name, age;

    while (getline(fin, line))
    {
        stringstream ss(line);
        Person p;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');

        p.id = stoi(id);

        int i;
        for (i = 0; i < name.length() && i < 49; i++)
        {
            p.name[i] = name[i];
        }
        p.name[i] = '\0';

        p.age = stoi(age);

        fout.write((char *)&p, sizeof(p));
    }

    fin.close();
    fout.close();

    cout << "Data written to binary file";

    return 0;
}
