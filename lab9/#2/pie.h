//
// Created by QDieu on 14.06.2018.
//

#ifndef LAB9_2_PIE_H
#define LAB9_2_PIE_H
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

class Pie{
public:
    Pie();
    ~Pie();
    Pie(const Pie &obj);
    Pie (int taste);
    Pie(string name, int taste);

    static int count;
    static Pie comparePie(const Pie &a, const Pie &b);

    void setTaste(int taste);
    string getName () const;
    int getTaste () const;

    Pie& operator= (const Pie &obj);

private:
    string _name;
    int _taste;
};

#endif //LAB9_2_PIE_H
