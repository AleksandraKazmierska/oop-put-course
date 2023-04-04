#include <iostream>

using namespace std;

//INTERFACE
class Animal
{
public:
    virtual string Species()=0;
    virtual int Age()=0;
    virtual void MakeSound()=0;
    
};

class Dog : public Animal
{
private:
    string species;
    int age;
    
public:
    Dog(string s , int a) : species(s), age(a) {}
    string Species() override
    {
        return species;
    }
    int Age() override
    {
        return age;
    }
    void MakeSound() override
    {
         cout << "woof"<< endl;
        
    }
};

class Cow : public Animal
{
private:
    string species;
    int age;
    
public:
    Cow(string s, int a) : species(s), age(a){}
    string Species() override
    {
        return species;
    }
    int Age() override
    {
        return age;
    }
    void MakeSound() override
    {
        cout << "moo"<< endl;
        
    }
};


int main()
{
    Dog a1("Dog", 3);
    cout << a1.Species()<<endl;
    cout << a1.Age()<< endl;
    a1.MakeSound(); 
    
    cout<< "\n";
    
    Cow a2("Cow", 5);
    cout << a2.Species()<<endl;
    cout << a2.Age()<< endl;
     a2.MakeSound();


}
