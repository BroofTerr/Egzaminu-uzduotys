#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

struct Staciakampiai{
    int koordX; ///Staciakampio pradzios koordtinates
    int koordY;
    int plotis; ///Staciakampio dimensijos
    int ilgis;
    int spalva[3]; ///RGB tipo staciakampio spalva
};

void spalvinti(int (&piesinys)[99][99][3], Staciakampiai &staciakampis){ ///pakeis piesinio rgb reiksmes
    int langeliuSpalvinta = staciakampis.ilgis*staciakampis.plotis; ///Nustato kiek langeliu isviso pakeis, arba, nuspalvins staciakampis
    for (int sp = 0; sp < langeliuSpalvinta; sp++){ ///sp - spalvinti(veiksmas) spalvins kiek reikia langeliu
        for (int pavY = staciakampis.koordY; pavY < staciakampis.koordY+staciakampis.plotis; pavY++){    ///Parenkamos staciakampiu pradzios koordinates ir spalvinama tiek langeliu kiek reikia pagal x ir y asis
            for (int pavX = staciakampis.koordX; pavX < staciakampis.koordX+staciakampis.ilgis; pavX++){
                for (int rgb = 0; rgb < 3; rgb++){ ///Spalvu keitimas
                    piesinys[pavY][pavX][rgb] = staciakampis.spalva[rgb];
                }
            }
        }
    }
}

int main()
{
    ifstream skaityti("U2.txt");
    int piesinys[99][99][3]; ///piesinys (y;x;rgb spalva)
    for (int y = 0; y < 99; y++){ ///piesinys uzpildomas balta spalva (RGB (255 255 255) )
        for (int x = 0; x < 99; x++){
            for (int rgb = 0; rgb < 3; rgb++){
                piesinys[y][x][rgb] = 255;
            }
        }
    }
    int stSkaicius; ///Staciakampiu skaicius
    int piesIlgis = 0, piesPlotis = 0; ///Piesinio ilgis bei plotis, kuris bus apskaiciuotas pagal didziausius staciakampiu ilgius ir plocius.
    skaityti >> stSkaicius;
    assert(stSkaicius >= 1 && stSkaicius <= 100); ///Patikrina ar staciakampiu skaicius priklauso intervalui [1;100]
    Staciakampiai stac[stSkaicius];
    for (int i = 0; i < stSkaicius; i++){
        skaityti >> stac[i].koordX;
        skaityti >> stac[i].koordY;
        skaityti >> stac[i].ilgis;
        skaityti >> stac[i].plotis;
        if (stac[i].ilgis > piesIlgis){ ///Nustotamas piesinio ilgis
            piesIlgis = stac[i].ilgis;
        }
        if (stac[i].plotis > piesPlotis){ ///Nustatomas piesinio plotis
            piesPlotis = stac[i].plotis;
        }
        for (int rgb = 0; rgb < 3; rgb++){
            skaityti >> stac[i].spalva[rgb];
        }
        assert(stac[i].koordX >= 0 && stac[i].koordX <= 99); ///Nurodytu reiksmiu intervalu tikrinimai
        assert(stac[i].koordY >= 0 && stac[i].koordY <= 99);
        assert(stac[i].ilgis >= 1 && stac[i].ilgis <= 20);
        assert(stac[i].plotis >= 1 && stac[i].plotis <= 20);
        assert((stac[i].ilgis+stac[i].koordX) <= 100);
        assert((stac[i].plotis+stac[i].koordY) <= 100);
    }
    skaityti.close();
    //-------------------------------------------------------
    for (int st = 0; st < stSkaicius; st++){ ///st - staciakampis
        spalvinti(piesinys, stac[st]);
    }
    ofstream rasyti("U2rez.txt");
    rasyti << piesPlotis << " " << piesIlgis << endl;
    for (int y = 0; y < piesPlotis; y++){
        for (int x = 0; x < piesIlgis; x++){
            for (int rgb = 0; rgb < 3; rgb++){
                rasyti << piesinys[y][x][rgb] << " ";
            }
            rasyti << endl;
        }

    }

    return 0;
}
