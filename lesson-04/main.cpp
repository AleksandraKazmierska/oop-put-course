#include <iostream>
using namespace std;

class Rectangle
{
private:
    float width;
    float height;

public:
    //default constructor
    Rectangle() : width{0.0}, height{0.0} {}

    // main constructor
    Rectangle(float width,float height) : width{width},height{height} {}

    //delegating constructor
    Rectangle(float size) : Rectangle(size,size) {}


    float area()
    {
        return width * height;
    }
};

int main ()
{
    Rectangle r1;

    Rectangle r2{5.0,10.0};

    Rectangle r3{3.0};



    cout<<"Area r1:"<<r1.area()<<endl;

    cout<<"Area r2:" <<r2.area()<<endl;

    cout<<"Area r3:"<< r3.area ()<<endl;

    return 0;
}
