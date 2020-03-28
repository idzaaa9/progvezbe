#include <iostream>

using namespace std;

enum TipPreliva{COKOLADNI = 1, COKOLADNI_SA_SLAGOM = 2};
class Preliv{
private:
    TipPreliva tip;
public:
        Preliv(){
            tip = COKOLADNI;
        }
        Preliv(TipPreliva a){
            tip = a;
        }

        bool dodajSlag(){
            if(tip == COKOLADNI)
                tip = COKOLADNI_SA_SLAGOM;
            else
                return 0;
            return 1;
        }

        bool ukloniSlag(){
            if(tip == COKOLADNI_SA_SLAGOM)
                tip = COKOLADNI;
            else
                return 0;
            return 1;
        }

        TipPreliva getTip() const {
            return tip;
        }

};

void ispisiPreliv(const Preliv& naziv){
    cout << "--------------" << endl << naziv.getTip() << endl << "--------------" << endl;
}


/**enum KolacStanje{ZAGOREO = 0, PECE_SE = 1, U_PRIPREMI = 2, PRIPREMLJEN = 3}
class Kolac{
private:
    KolacStanje stanje;
    int temperatura;
    Preliv preliv;
public:
    Kolac()
};*/

int main()
{
    Preliv a;
    ispisiPreliv(a);
    return 0;
}
