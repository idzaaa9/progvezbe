#include <iostream>

using namespace std;

enum TipPreliva{COKOLADNI, COKOLADNI_SA_SLAGOM};

const string& enumToString(TipPreliva a){
    static string naziv[] = {"Cokoladni", "Cokoladni sa Slagom"};
    return (naziv[a]);
}

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
    cout << "--------------" << endl << enumToString(naziv.getTip()) << endl << "--------------" << endl;
}

enum Stanje{U_PRIPREMI, PECE_SE, ZAGOREO, PRIPREMLJEN};

class Kolac{
private:
    Preliv preliv;
    Stanje stanje;
    int temperatura;
public:
    Kolac(){
        temperatura = 20;
        stanje = U_PRIPREMI;
        preliv.tip = COKOLADNI;
    }
};

int main()
{
    Preliv a;
    ispisiPreliv(a);
    Kolac a;
    return 0;
}
