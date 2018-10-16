#include <string>
#include <ctime>
#include <iostream>
#include "baker.h"

using namespace std;

int bake(Baker baker1, Baker baker2){
    int limitPie = 30;
    int bake1, bake2;
    for (int i =0; i<25; i++)
    {
        bake1 = rand()%3+1;
        if (bake1 == 1) baker1.CreatePie();
        else if (bake1 == 2) baker1.eatPie();
        else baker1.givePie(baker2);

        bake2 = rand()%3+1;
        if (bake2 == 1) baker2.CreatePie();
        else if (bake2 == 2) baker2.eatPie();
        else baker2.givePie(baker1);

        if(baker1.getCounter()+baker2.getCounter() >= limitPie) return 300;
    }
    return 200*(baker1.getCounter()+baker2.getCounter())/30;
}

int main() {
    Baker baker1, baker2;
    int wins=0,exp;
        for (int i=0;i<10;i++)
        {
            baker1.CreatePie();
            baker2.CreatePie();
        }
    exp = bake(baker1,baker2);
    if (exp == 300) wins++;
    baker1.ExpAndProf(exp/2);
    baker2.ExpAndProf(exp/2);
    for (int i=0;i<10;i++)
    {
        baker1.eatPie();
        baker2.eatPie();
    }
    return 0;
}
