//
// Created by QDieu on 14.06.2018.
//

#include "pie.h"

int Pie::count=0;

string randName()
{
    srand(time(0));
    int name = rand()%3+1;
    if(name == 1) return "meat";
    else if(name == 2) return "potato";
    else if(name == 3) return "mushrooms";
}
int randTaste()
{
    srand(time(0));
    return rand()%100+1;
}

Pie::Pie()
{
    cout << "Pie constructor" << endl;
    _taste=randTaste();
    _name = randName();
    count++;
}

Pie::Pie(const Pie &obj)
{
    cout<<"Pie copy constructor" << endl;
    _name = obj._name;
    _taste = obj._taste;
    count++;
}
Pie::Pie(int taste)
{
    cout << "Pie Constructor" << endl;
    _taste = taste;
    _name = randName();
    count++;
}
Pie::Pie(string name, int taste)
{
    cout << "Pie Constructor" << endl;
    _taste = taste;
    _name = name;
    count++;
}
Pie::~Pie()
{
    cout << "Pie destructor" << endl;
}
string Pie::getName() const
{
    return _name;
}
int Pie::getTaste() const
{
    return _taste;
}

void Pie::setTaste(int taste)
{
    _taste = taste;
}
Pie& Pie::operator=(const Pie &obj)
{
    if (this==&obj) return *this;
    _taste=obj._taste;
    _name=obj._name;
    return *this;
}
