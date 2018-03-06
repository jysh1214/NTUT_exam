#include <iostream>
#include <string.h>

using namespace std;

class Animal{
    public:
    virtual void speak() = 0;
};

class Bird: public Animal{
    public:
    virtual void speak(){cout<<"twitter"<<endl;}
};

class Mammal: public Animal{
    public:
    virtual void speak(){cout<<"can't speak"<<endl;}
    void bark(){cout<<"can't bark"<<endl;}
};

class Cat: public Mammal{
    public:
    void speak(){cout<<"meow!";}
    virtual void purr(){cout<<"purrrrr"<<endl;}
};

class Dog: public Mammal{
    public:
    virtual void speak(){cout<<"woof!"<<endl;}
    void bark(){cout<<"wooooof!"<<endl;}
};

int main(int argc, char *argv[]){
    Dog *d = new Dog();
    Mammal *m = d;
    cout<<"Problem 5-1: ";
    m->bark();                    // Problem 5-1
    Animal *a = m;
    cout<<"Problem 5-2: ";
    a->speak();                   // Problem 5-2
    Mammal mm = *d;
    cout<<"Problem 5-3: ";
    mm.speak();                   // Problem 5-3
    cout<<"Problem 5-4: ";
    mm.bark();                    // Problem 5-4 
    Animal *aa = new Cat();
    Bird *b = dynamic_cast<Bird *>(aa);
    char cast_result[25]; 
    if(b) strcpy(cast_result, "Variable was a Bird");
    else  strcpy(cast_result, "It was not a Bird");
    cout<<"Problem 5-5: ";
    cout<<cast_result<<endl;      // Problem 5-5 
    return 0;
}   
