#include <iostream>

using namespace std;

class Rectangle
{
private:
    int a = 10;
    int b = 5;

public:
    int Length()
    {
        return a;
    }

    int Height ()
    {
        return b;
    }
};

class Calculations
{

public:
    int Area (Rectangle rectangle)
    {
       return rectangle.Length() * rectangle.Height();
    }

    int Circumrefence (Rectangle rectangle)
    {
        return 2*(rectangle.Length()) + 2*(rectangle.Height());
    }
};

int main()
{
 Rectangle rectangle;
Calculations calculation;
cout << calculation.Area(rectangle);

    return 0;
}
