#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int *rollno;
    string name;

    Student(int r)
    {
        rollno = new int(r);
        name = "Unknown";
    }

    Student(const Student &obj)
    {
        rollno = new int(*(obj.rollno));
        name = obj.name;
    }

    ~Student()
    {
        delete rollno;
    }
};

int main()
{
    Student s1(101);
    s1.name = "Batman";
    Student s2 = s1;

    cout << "s1 rollno: " << *s1.rollno << ", name: " << s1.name << endl;
    cout << "s2 rollno: " << *s2.rollno << ", name: " << s2.name << endl;

    Student *s3 = new Student(102);
    s3->name = "Ironman";
    Student *s4 = new Student(*s3);

    *s1.rollno = 501;
    s1.name = "Bruce Wayne";

    *(s3->rollno) = 502;
    s3->name = "Tony Stark";

    cout << "\nAfter Modification:" << endl;
    cout << "s1 rollno: " << *s1.rollno << ", name: " << s1.name << endl;
    cout << "s2 rollno: " << *s2.rollno << ", name: " << s2.name << endl;
    cout << "s3 rollno: " << *(s3->rollno) << ", name: " << s3->name << endl;
    cout << "s4 rollno: " << *(s4->rollno) << ", name: " << s4->name << endl;

    delete s3;
    delete s4;
    return 0;
}