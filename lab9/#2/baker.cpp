//
// Created by QDieu on 14.06.2018.
//
#include "baker.h"

Baker::Baker()
{
    cout << "Baker Constructor" << endl;
    _exp=0;
    _profess=0;
    _satiety=100;
    _counter=0;
    pies=new Pie[100];
}

Baker::Baker(const Baker &obj)
{
    cout << "Baker Copy Constructor" << endl;
    _exp=obj._exp;
    _profess=obj._profess;
    _satiety=obj._satiety;
    _counter=obj._counter;
    pies= new Pie[100];
    for (int i = 0; i < obj._counter; i++)
    {
        pies[i] = obj.pies[i];
    }
}
void Baker::CreatePie()
{
    int taste;
    if (_satiety>50)
        if (_profess>60)
            taste=80;
        else taste = 55;
    else taste = 20;
    this->pies[this->_counter++].setTaste(taste);
}
void Baker::givePie(Baker &baker)
{
    baker.pies[baker._counter++]=this->pies[--this->_counter];
    this->_satiety-=30;
    if(this->_satiety<0) this->_satiety=0;
}
void Baker::eatPie()
{
    _satiety+=pies[--_counter].getTaste();
}
Baker &Baker::operator= (const Baker &obj)
{
    if (this==&obj)return *this;
    _profess=obj._profess;
    _exp=obj._exp;
    _satiety=obj._satiety;
    return *this;
}
Baker::~Baker(){
    cout << "Desctructor Baker" << endl;
    delete [] pies;
}
void Baker::ExpAndProf(int exp)
{
    _exp+=exp;
    _profess+=exp/15;
}
int Baker::getCounter()const
{
    return _counter;
}
