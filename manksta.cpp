#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct Pratimai{
    string pavadinimas = "";
    int atliktaKartu = 0;
};

bool PalygintiPratimuAtlikima(Pratimai &a, Pratimai &b){
    return a.atliktaKartu > b.atliktaKartu; ///Tikrina kuris pratimas atliktas daugiau kartu
}

int main()
{
    int pratimuSk, veiksmuSk; ///pratimu skaicius - kiek atlikta pratimu, veiksmu skaicius - kiek kartu atliktas pratimas
    string pavadinimas;
    bool reikiaNaujoV; ///Naudojamas tikrinant ar reikia naujos vietos vektoryje naujam pratimui
    int skirtingiPratimai = 1; ///Kaupia skaiciu kuris parodo, kiek unikaliu pratimu atliko Vytautas, bet naudojamas vektoriams kurti
    ifstream skaityti ("U2.txt");
    skaityti >> pratimuSk;
    assert(pratimuSk >= 1 && pratimuSk <= 100);
    vector<Pratimai> pratimas;
    pratimas.push_back(Pratimai());
    //--------------------------------------------------------------
    skaityti >> pavadinimas >> veiksmuSk; ///Uzpildom pirmaji vektoriu, pagal kuri tikrinsim kitus
    assert (pavadinimas.length() <= 20); ///Patikrina ar pratimo pavadinimas neuzima daugiau nei 20
    pratimas[0].pavadinimas = pavadinimas;
    pratimas[0].atliktaKartu += veiksmuSk;
    for (int i = 0; i < pratimuSk-1; i++){ ///nuskaitoji ir paskirstomi likusieji pratimai
        reikiaNaujoV = true;
        skaityti >> pavadinimas >> veiksmuSk;
        assert (pavadinimas.length() <= 20); ///Patikrina ar pratimo pavadinimas neuzima daugiau nei 20 simboliu
        for (int j = 0; j < skirtingiPratimai; j++){
            if (pavadinimas == pratimas[j].pavadinimas){
                pratimas[j].atliktaKartu += veiksmuSk;
                reikiaNaujoV = false;
                break;
            }
        }
         if (reikiaNaujoV){ ///Jeigu tai naujas pratimas, tai sukuriamas naujas vektorius
                pratimas.push_back(Pratimai());
                skirtingiPratimai++; ///Prisideda naujas pratimas
                pratimas[skirtingiPratimai-1].pavadinimas = pavadinimas;
                pratimas[skirtingiPratimai-1].atliktaKartu += veiksmuSk;
        }
    }
    skaityti.close();
    //--------------------------------------------------------------
    sort(pratimas.begin(), pratimas.end(), PalygintiPratimuAtlikima);
    ofstream rasyti ("U2rez.txt");
    for (int i = 0 ; i < skirtingiPratimai; i++){
        rasyti.width(20);
        rasyti << left << pratimas[i].pavadinimas << " " << pratimas[i].atliktaKartu << endl;
    }
    rasyti.close();

    return 0;
}
