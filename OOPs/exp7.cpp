
#include <iostream>
#define PI 3.14159
using namespace std;

class Shape
{
public:
    virtual double area() const = 0;

    void displayArea() const
    {
        cout << "Area: " << area() << '\n';
    }

    virtual ~Shape() = default;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override
    {
        return PI * radius * radius;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override
    {
        return length * width;
    }
};

int main()
{

    Circle circle(5.0);
    Rectangle rectangle(4.0, 3.0);

    Shape *shapes[] = {&circle, &rectangle};
    for (const Shape *shape : shapes)
    {
        shape->displayArea();
    }

    return 0;
}
