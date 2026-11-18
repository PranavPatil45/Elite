
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Patient
{
protected:
    int id, age;
    string name;

public:
    Patient(int i, string n, int a)
    {
        if (a <= 0)
            throw "Invalid patient age.";

        id = i;
        name = n;
        age = a;
    }

    int getID() const
    {
        return id;
    }

    virtual bool isEmergency() const
    {
        return false;
    }

    virtual int getPriority() const
    {
        return 0;
    }

    virtual void display() const
    {
        cout << id << "\t" << name << "\t"
             << age << "\tGeneral\t-\n";
    }

    virtual void save(ofstream &file) const
    {
        file << id << "," << name << ","
             << age << ",G,0\n";
    }

    virtual ~Patient() {}
};

class EmergencyPatient : public Patient
{
    int priority;

public:
    EmergencyPatient(int i, string n, int a, int p)
        : Patient(i, n, a)
    {
        if (p < 1 || p > 5)
            throw "Priority must be between 1 and 5.";

        priority = p;
    }

    bool isEmergency() const override
    {
        return true;
    }

    int getPriority() const override
    {
        return priority;
    }

    // Overload < operator
    bool operator<(const EmergencyPatient &p) const
    {
        return priority < p.priority;
    }

    void display() const override
    {
        cout << id << "\t" << name << "\t"
             << age << "\tEmergency\t"
             << priority << "\n";
    }

    void save(ofstream &file) const override
    {
        file << id << "," << name << ","
             << age << ",E," << priority << "\n";
    }
};

// Comparator for priority_queue
struct ComparePriority
{
    bool operator()(Patient *a, Patient *b) const
    {
        return a->getPriority() < b->getPriority();
    }
};

int main()
{
    vector<Patient *> patients;

    priority_queue<Patient *,
                   vector<Patient *>,
                   ComparePriority>
        emergencyQueue;

    ifstream fin("patients.txt");

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
            int id, age, priority;

            if (!getline(ss, field, ','))
                throw "Invalid patient record.";
            id = stoi(field);

            if (!getline(ss, name, ',') ||
                !getline(ss, field, ','))
                throw "Invalid patient record.";
            age = stoi(field);

            if (!getline(ss, type, ',') ||
                !getline(ss, field))
                throw "Invalid patient record.";
            priority = stoi(field);

            Patient *p = nullptr;

            if (type == "G")
            {
                if (priority != 0)
                    throw "General patient priority must be 0.";

                p = new Patient(id, name, age);
            }
            else if (type == "E")
            {
                p = new EmergencyPatient(id, name, age, priority);
            }
            else
            {
                throw "Invalid patient type.";
            }

            bool duplicate = false;

            for (Patient *existing : patients)
            {
                if (existing->getID() == id)
                {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate)
            {
                cout << "Duplicate patient ID skipped: "
                     << id << endl;
                delete p;
            }
            else
            {
                patients.push_back(p);

                if (p->isEmergency())
                    emergencyQueue.push(p);
            }
        }

        fin.close();

        int choice;

        do
        {
            cout << "\n--- HOSPITAL PATIENT MANAGEMENT ---\n";
            cout << "1. Display All Patients\n";
            cout << "2. Process Emergency Patients\n";
            cout << "3. Search Patient by ID\n";
            cout << "4. Save Patient Records\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nID\tName\tAge\tType\t\tPriority\n";

                for (Patient *p : patients)
                    p->display();

                break;

            case 2:
                if (emergencyQueue.empty())
                {
                    cout << "No emergency patients.\n";
                    break;
                }

                cout << "\n--- EMERGENCY PATIENT QUEUE ---\n";

                while (!emergencyQueue.empty())
                {
                    Patient *p = emergencyQueue.top();
                    p->display();
                    emergencyQueue.pop();
                }

                cout << "Emergency queue processed.\n";
                break;

            case 3:
            {
                int searchID;
                bool found = false;

                cout << "Enter Patient ID: ";
                cin >> searchID;

                for (Patient *p : patients)
                {
                    if (p->getID() == searchID)
                    {
                        cout << "\nPatient Found:\n";
                        p->display();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Patient not found.\n";

                break;
            }

            case 4:
            {
                ofstream fout("patients.txt");

                if (!fout)
                    throw "Error opening output file.";

                for (Patient *p : patients)
                    p->save(fout);

                fout.close();

                cout << "Patient records saved successfully.\n";
                break;
            }

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
            }

        } while (choice != 5);
    }
    catch (const char *msg)
    {
        cout << "Exception: " << msg << endl;
    }
    catch (...)
    {
        cout << "Error: Invalid data in patient file.\n";
    }

    for (Patient *p : patients)
        delete p;

    return 0;
}
