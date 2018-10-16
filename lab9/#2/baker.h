//
// Created by QDieu on 14.06.2018.
//

#ifndef LAB9_2_BAKER_H
#define LAB9_2_BAKER_H
#include "pie.h"

class Baker{
public:
    Baker();
    ~Baker();
    Baker(const Baker &obj);
    void CreatePie();
    void givePie(Baker &baker);
    void eatPie();

    Baker& operator=(const Baker &obj);
    void ExpAndProf(int exp);

    int getCounter() const;
private:
    int _profess, _exp, _satiety, _counter;
    Pie *pies;
};


#endif //LAB9_2_BAKER_H
