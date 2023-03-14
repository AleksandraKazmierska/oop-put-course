#include <iostream>

using namespace std;

class Human
{
    public: 
    string name;
    int age;
    int weight;
    
};

class Dog
{
    public:
    string breed;
    int age;
    string colour;
    
};

int main() {
    
    Human a;
    a.name = "John";
    a.age = 20;
    a.weight = 70;
    
    Human c;
    c.name= "Anne";
    c.age = 30;
    c.weight = 50;
    
    
    Dog b;
    b.breed = "beagle";
    b.age = 7;
    b.colour = "brown";
    
