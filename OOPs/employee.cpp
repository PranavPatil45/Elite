
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Employee
{
protected:
    int id;
    string name;

public:
    Employee(int i, string n)
    {
        id = i;
        name = n;
    }

    int getID() const
    {
        return id;
    }

    virtual double getSalary() const = 0;

    virtual void display(ostream &out) const
    {
        out << id << "\t" << name << "\t";
    }

    virtual void save(ofstream &file) const = 0;

    virtual ~Employee() {}
};

// Overload << operator
ostream &operator<<(ostream &out, const Employee &e)
{
    e.display(out);
    return out;
}

class PermanentEmployee : public Employee
{
    double basicSalary, allowance;

public:
    PermanentEmployee(int i, string n, double b, double a)
        : Employee(i, n)
    {
        if (b < 0 || a < 0)
            throw "Salary and allowance cannot be negative.";

        basicSalary = b;
        allowance = a;
    }

    double getSalary() const override
    {
        return basicSalary + allowance;
    }

    void display(ostream &out) const override
    {
        Employee::display(out);
        out << "Permanent\t"
            << basicSalary << "\t"
            << allowance << "\t"
            << getSalary() << endl;
    }

    void save(ofstream &file) const override
    {
        file << id << "," << name << ",P,"
             << basicSalary << "," << allowance << "\n";
    }
};

class ContractEmployee : public Employee
{
    int workingDays;
    double dailyWage;

public:
    ContractEmployee(int i, string n, int days, double wage)
        : Employee(i, n)
    {
        if (days < 0 || wage < 0)
            throw "Working days and wage cannot be negative.";

        workingDays = days;
        dailyWage = wage;
    }

    double getSalary() const override
    {
        return workingDays * dailyWage;
    }

    void display(ostream &out) const override
    {
        Employee::display(out);
        out << "Contract\t"
            << workingDays << "\t"
            << dailyWage << "\t"
            << getSalary() << endl;
    }

    void save(ofstream &file) const override
    {
        file << id << "," << name << ",C,"
             << workingDays << "," << dailyWage << "\n";
    }
};

int main()
{
    vector<Employee *> employees;
    ifstream fin("employees.txt");

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
            string field, name, type;
            int id;

            if (!getline(ss, field, ','))
                throw "Invalid employee record.";

            id = stoi(field);

            if (!getline(ss, name, ',') ||
                !getline(ss, type, ','))
                throw "Invalid employee record.";

            if (type == "P")
            {
                double basic, allowance;

                if (!getline(ss, field, ','))
                    throw "Missing basic salary.";

                basic = stod(field);

                if (!getline(ss, field))
                    throw "Missing allowance.";

                allowance = stod(field);

                employees.push_back(
                    new PermanentEmployee(id, name, basic, allowance));
            }
            else if (type == "C")
            {
                int days;
                double wage;

                if (!getline(ss, field, ','))
                    throw "Missing working days.";

                days = stoi(field);

                if (!getline(ss, field))
                    throw "Missing daily wage.";

                wage = stod(field);

                employees.push_back(
                    new ContractEmployee(id, name, days, wage));
            }
            else
            {
                throw "Invalid employee type.";
            }
        }

        fin.close();

        // Sort by salary in descending order
        sort(employees.begin(), employees.end(),
             [](Employee *a, Employee *b)
             {
                 return a->getSalary() > b->getSalary();
             });

        // Display all employees
        cout << "\n--- EMPLOYEE PAYROLL ---\n";
        cout << "ID\tName\tType\t\tDetails\t\tSalary\n";

        for (Employee *e : employees)
            cout << *e;

        // Search employee by ID
        int searchID;
        cout << "\nEnter Employee ID to search: ";
        cin >> searchID;

        vector<Employee *>::iterator it =
            find_if(employees.begin(), employees.end(),
                    [searchID](Employee *e)
                    {
                        return e->getID() == searchID;
                    });

        if (it != employees.end())
        {
            cout << "\nEmployee Found:\n";
            cout << **it;
        }
        else
        {
            cout << "Employee not found.\n";
        }

        // Display highest-paid employee
        if (!employees.empty())
        {
            cout << "\n--- HIGHEST PAID EMPLOYEE ---\n";
            cout << *employees.front();
        }

        // Save records to output file
        ofstream fout("payroll.txt");

        if (!fout)
            throw "Error creating output file.";

        for (Employee *e : employees)
            e->save(fout);

        fout.close();

        cout << "\nEmployee records saved to payroll.txt\n";
    }
    catch (const char *msg)
    {
        cout << "Error: " << msg << endl;
    }
    catch (...)
    {
        cout << "Error: Invalid data in the input file.\n";
    }

    for (Employee *e : employees)
        delete e;

    return 0;
}
