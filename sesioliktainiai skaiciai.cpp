#include <iostream>
#include <fstream>
using namespace std;

string konvertuoti (int spalva);

int main()
{
    ifstream skaityti("U1.txt");
    int ilgis, plotis; ///Piesinio ilgis ir plotis
    skaityti >> ilgis >> plotis;
    int spalvuSk = ilgis*plotis; ///Kiek spalvu sudaro paveiksleli
    int dSpalvos[spalvuSk][3]; ///Desimtainiu spalvu masyvas
    string sSpalvos[spalvuSk] = {"","","","","",""}; ///Sesioliktainiu spalvu masyvas
    //---------------------------------------------------------
    for (int ss = 0; ss < spalvuSk; ss++){ /// ss - spalvu skaicius
        for (int s = 0; s < 3; s++){ ///s - spalva
            skaityti >> dSpalvos[ss][s];
            sSpalvos[ss] += konvertuoti(dSpalvos[ss][s]);
        }
    }
    skaityti.close();
    //----------------------------------------------------------
    ofstream rasyti("U1rez.txt");
    for (int ss = 0; ss < spalvuSk; ss++){
        if ((ss+1)%plotis == 0){  ///Paskirsto spalvas pagal nurodytas dimensijas
            rasyti << sSpalvos[ss] << endl;
        }
        else {
            rasyti << sSpalvos[ss] << ";";
        }
    }

    return 0;
}

string konvertuoti(int spalva){
    string kSpalva = ""; /// Konvertuota spalva
    int dalyba, liekana;
    dalyba = spalva/16;
    liekana = spalva%16;
    switch(dalyba){ ///Sveikos dalies konvertavimas i sesioliktaini skaiciu
    case 0:
    kSpalva+= '0';
    break;
    case 1:
    kSpalva+= '1';
    break;
    case 2:
    kSpalva+= '2';
    break;
    case 3:
    kSpalva+= '3';
    break;
    case 4:
    kSpalva+= '4';
    break;
    case 5:
    kSpalva+= '5';
    break;
    case 6:
    kSpalva+= '6';
    break;
    case 7:
    kSpalva+= '7';
    break;
    case 8:
    kSpalva+= '8';
    break;
    case 9:
    kSpalva+= '9';
    break;
    case 10:
    kSpalva+= 'A';
    break;
    case 11:
    kSpalva+= 'B';
    break;
    case 12:
    kSpalva+= 'C';
    break;
    case 13:
    kSpalva+= 'D';
    break;
    case 14:
    kSpalva+= 'E';
    break;
    case 15:
    kSpalva+= 'F';
    break;
    }

    switch(liekana){ ///Liekanos konvertavimas i sesioliktaini skaiciu
    case 0:
    kSpalva+= '0';
    break;
    case 1:
    kSpalva+= '1';
    break;
    case 2:
    kSpalva+= '2';
    break;
    case 3:
    kSpalva+= '3';
    break;
    case 4:
    kSpalva+= '4';
    break;
    case 5:
    kSpalva+= '5';
    break;
    case 6:
    kSpalva+= '6';
    break;
    case 7:
    kSpalva+= '7';
    break;
    case 8:
    kSpalva+= '8';
    break;
    case 9:
    kSpalva+= '9';
    break;
    case 10:
    kSpalva+= 'A';
    break;
    case 11:
    kSpalva+= 'B';
    break;
    case 12:
    kSpalva+= 'C';
    break;
    case 13:
    kSpalva+= 'D';
    break;
    case 14:
    kSpalva+= 'E';
    break;
    case 15:
    kSpalva+= 'F';
    break;
    }
    return kSpalva;
}
