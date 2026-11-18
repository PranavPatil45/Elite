#include <iostream>
#include <string>
using namespace std;

class TimeDuration
{
private:
    int hours;
    int minutes;
    string taskname;
    int taskid;

public:
    TimeDuration()
    {
        hours = 0;
        minutes = 0;
        taskname = "";
        taskid = 0;
    }
    TimeDuration(int h, int m)
    {
        hours = h;
        minutes = m;
        taskname = "";
        taskid = 0;
        hours += minutes / 60;
        minutes = minutes % 60;
    }
    TimeDuration operator+(const TimeDuration &obj)
    {
        TimeDuration temp;
        temp.hours = this->hours + obj.hours;
        temp.minutes = this->minutes + obj.minutes;
        temp.hours += temp.minutes / 60;
        temp.minutes %= 60;
        return temp;
    }
    TimeDuration operator-(const TimeDuration &obj)
    {
        TimeDuration temp;
        int totalMinutes1 = this->hours * 60 + this->minutes;
        int totalMinutes2 = obj.hours * 60 + obj.minutes;
        int diffMinutes = totalMinutes1 - totalMinutes2;
        if (diffMinutes < 0)
            diffMinutes = 0;
        temp.hours = diffMinutes / 60;
        temp.minutes = diffMinutes % 60;
        return temp;
    }
    bool operator>(const TimeDuration &obj)
    {
        int total1 = this->hours * 60 + this->minutes;
        int total2 = obj.hours * 60 + obj.minutes;
        return total1 > total2;
    }
    bool operator==(const TimeDuration &obj)
    {
        int total1 = this->hours * 60 + this->minutes;
        int total2 = obj.hours * 60 + obj.minutes;
        return total1 == total2;
    }
    TimeDuration &operator++()
    {
        this->minutes++;
        this->hours += this->minutes / 60;
        this->minutes %= 60;
        return *this;
    }
    friend istream &operator>>(istream &in, TimeDuration &obj)
    {
        cout << "Enter Task ID: ";
        in >> obj.taskid;
        cout << "Enter Task Name: ";
        in >> obj.taskname;
        cout << "Enter Hours: ";
        in >> obj.hours;
        cout << "Enter Minutes: ";
        in >> obj.minutes;
        obj.hours += obj.minutes / 60;
        obj.minutes %= 60;
        return in;
    }
    friend ostream &operator<<(ostream &out, const TimeDuration &obj)
    {
        out << "Task ID: " << obj.taskid << ", Task Name: " << obj.taskname
            << ", Duration: " << obj.hours << " hour(s) " << obj.minutes << " minute(s)";
        return out;
    }
};
int main()
{
    const int MAX_TASKS = 100;
    TimeDuration tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    do
    {
        cout << "\n--- Menu-Driven Program ---\n";
        cout << "1. Add task\n";
        cout << "2. Display all tasks\n";
        cout << "3. Display total time spent on all tasks\n";
        cout << "4. Display the task with maximum time spent\n";
        cout << "5. Display the task with minimum time spent\n";
        cout << "6. Display the time difference between two tasks\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (taskCount < MAX_TASKS)
            {
                cin >> tasks[taskCount];
                taskCount++;
                cout << "Task added successfully!\n";
            }
            else
            {
                cout << "Task list is full!\n";
            }
            break;
        }
        case 2:
        {
            if (taskCount == 0)
            {
                cout << "No tasks available.\n";
            }
            else
            {
                cout << "\n--- All Tasks ---\n";
                for (int i = 0; i < taskCount; ++i)
                {
                    cout << i + 1 << ". " << tasks[i] << "\n";
                }
            }
            break;
        }
        case 3:
        {
            if (taskCount == 0)
            {
                cout << "No tasks available.\n";
            }
            else
            {
                TimeDuration total(0, 0);
                for (int i = 0; i < taskCount; ++i)
                {
                    total = total + tasks[i];
                }
                cout << "Total time spent on all tasks: " << total << "\n";
            }
            break;
        }
        case 4:
        {
            if (taskCount == 0)
            {
                cout << "No tasks available.\n";
            }
            else
            {
                int maxIndex = 0;
                for (int i = 1; i < taskCount; ++i)
                {
                    if (tasks[i] > tasks[maxIndex])
                    {
                        maxIndex = i;
                    }
                }
                cout << "Task with maximum time spent:\n"
                     << tasks[maxIndex] << "\n";
            }
            break;
        }
        case 5:
        {
            if (taskCount == 0)
            {
                cout << "No tasks available.\n";
            }
            else
            {
                int minIndex = 0;
                for (int i = 1; i < taskCount; ++i)
                {
                    if (!(tasks[i] > tasks[minIndex]) && !(tasks[i] == tasks[minIndex]))
                    {
                        minIndex = i;
                    }
                }
                cout << "Task with minimum time spent:\n"
                     << tasks[minIndex] << "\n";
            }
            break;
        }
        case 6:
        {
            if (taskCount < 2)
            {
                cout << "Need at least two tasks to calculate a time difference.\n";
            }
            else
            {
                cout << "Enter index of first task (1 to " << taskCount << "): ";
                int idx1, idx2;
                cin >> idx1;
                cout << "Enter index of second task (1 to " << taskCount << "): ";
                cin >> idx2;

                if (idx1 >= 1 && idx1 <= taskCount && idx2 >= 1 && idx2 <= taskCount)
                {
                    TimeDuration diff = (tasks[idx1 - 1] > tasks[idx2 - 1]) ? (tasks[idx1 - 1] - tasks[idx2 - 1]) : (tasks[idx2 - 1] - tasks[idx1 - 1]);
                    cout << "Time difference: " << diff << "\n";
                }
                else
                {
                    cout << "Invalid indices entered.\n";
                }
            }
            break;
        }
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}
