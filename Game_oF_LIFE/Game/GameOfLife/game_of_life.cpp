#include "game_of_life.h"

game_of_life::game_of_life() {
    //GENERIRANJE GENERACIJE SLUCAJNO SA 25% MULTIDEMNZ POLJE
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = slucajna_vrijednost(); //ubacivanje slucajne vrijednosti u trenutnu generaciju
        }
    }
}

bool game_of_life::slucajna_vrijednost() {
    int num = rand() % 100 + 1;
    if (num <= 25) {
        return true;
    }
    else {
        return false;
    }
}

bool game_of_life::celija_zauzeta(int i, int j) {
   //PROVJERA ZAUZETOSTI(ako je * onda je zauzeto!!!)
    if (i == '*' or j == '*') {
        return false;
    }
    return _generacija[i][j];
}

void game_of_life::sljedeca_generacija() {
    //NOVA GENERACIJA
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            int susjedi = 0; //KRECE SA 0

           //SUSJEDI
            for (int i2 = -1; i2 <= 1; i2++) {
                for (int j2 = -1; j2 <= 1; j2++) {
                    if (i2 == 0 && j2 == 0) {
                        continue;  //Provjera individualnih celija
                    }
                    if (celija_zauzeta(i + i2, j + j2)) {
                        susjedi++; 
                    }
                }
            }

            //UVJETI
            //ZIVI ORG
            if (_generacija[i][j]) {

                _sljedeca_generacija[i][j] = (susjedi == 2 or susjedi == 3);
            }
            //MRTVI ORG
            else  {
               
                _sljedeca_generacija[i][j] = (susjedi < 2 or susjedi > 3);
            }
        }
    }

     //REFRESHAJ TRENUTNU GEN SA NOVOM
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

void game_of_life::iscrtaj() {
        for (int i = 0; i < REDAKA; i++) { //20
            for (int j = 0; j < STUPACA; j++) { //40
                if (_generacija[i][j]) {
                    cout << "*";
                }
                else {
                    cout << "-";
                }
            }
            cout << endl;
        }
    }


       