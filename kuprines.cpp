#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

bool Sverimas (int mase, int sunkMase){ ///Patikrina ar duotos kuprines mase yra didesne nei pacios sunkiausios kuprines mase
    if (mase > sunkMase)
        return true;
    else return false;
}

bool LengvesneKuprine (int mase, int sunkMase){
    int k = 0;
    while (mase <= sunkMase){
        mase += mase;     ///Prie duotos mases pridedama ta pati mase kas cikla
        k++;              ///Jei pridedama daugiau nei 2 kartus, reiskias si mase yra lengvesne daugiau nei 2 kartus ir t.t.
    }
    if (k >= 2)
        return true;
    else return false;
}

int main()
{
    int kupriniu, svoris, k = 0, sunkMase = 0; ///k - kelios kuprines lengvesnes 2 ar daugiau kartu; sunkKupr - sunkiausios kuprines svoris
    ifstream skaityti("U1.txt");
    skaityti >> kupriniu;
    assert(kupriniu >= 1 && kupriniu <= 100);
    for (int i = 0; i < kupriniu; i++){
        skaityti >> svoris;
        if (Sverimas(svoris, sunkMase)){
            sunkMase = svoris;
        }
    }
    skaityti.close();
    skaityti.open("U1.txt"); ///Is naujo atidarau srauta, kad galeciau palyginti kuprines su didziausia kuprine
    skaityti >> kupriniu;
    for (int i = 0; i < kupriniu; i++){
        skaityti >> svoris;
        if (LengvesneKuprine(svoris, sunkMase))
            k++;
    }
    skaityti.close();
    ofstream rasyti ("U1rez.txt");
    rasyti << sunkMase << " " << k;
    rasyti.close();

    return 0;
}
