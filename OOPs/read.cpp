#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{

    ifstream file("data.txt");
    string line, value;

    if (!file.is_open())
    {
        cout << "Unable to open file" << endl;
        return 1;
    }

    while (getline(file, line))
    {
        stringstream ss(line);

        while (getline(ss, value, ','))
        {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}
