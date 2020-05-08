#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"

#using namespace std;

class Karta{
private:
  DinString mestoPolaska, mestoDolaska;
  float distanca, cenaKarte;
  int idKarte;
public:
  Karta() : mestoPolaska(), mestoDolaska(), distanca(0), cenaKarte(0), idKarte(0) {}
  Karta(const DinString& refMestoPolaska, const DinString& refMestoDolaska, const float& refDistanca, const float& refCenaKarte, const int& refIdKarte) :
    mestoPolaska(refMestoPolaska), mestoDolaska(refMestoDolaska), distanca(refDistanca), cenaKarte(refCenaKarte), idKarte(refIdKarte){}
  Karta(const Karta& ref) :mestoPolaska(ref.getMestoPolaska()),
			   mestoDolaska(ref.getMestoDolaska()), distanca(ref.getDistanca()), cenaKarte(ref.getCenaKarte()), idKarte(ref.getIdKarte()) {}
  virtual bool jeftinaKarta() = {0};
  DinString getMestoPolaska()const{return mestoPolaska;}
  DinString getMestoDolaska()const{return mestDolaska;}
  float getDistanca()const{return Distanca;}
  float getCenaKarte()const{return cenaKarte;}
  int getIdKarte()const{return idKarte;}
};

class AvionskaKarta : public Karta{
public:
  AvionskaKarta() : Karta(){}
  AvionskaKarta(const Karta& ref) : Karta(ref) {}
  bool jeftinaKarta(){
    return ((cenaKarte/distanca) < 1) ? true : false;}
  void ispisi(){
    cout << mestoPolaska << endl;
    cout << mestoDolaska << endl;
    cout << distanca << endl;
    cout << cenaKarte << endl;
    cout << idKarte << endl;}
};

class Putovanje{
private:
  DinString nazivPutovanja;
  int maxCena, preostalo;
  List<AvionskaKarta> listKarte;
public:
  Putovanje() : nazivPutovanja(), maxCena(0), listKarte(){}
  Putovanje(const DinString& refNaziv, const int& refMaxCena, const List<AvionskaKarta>& refListKarta, const int& refPreostalo) :
    nazivPutovanja(refNaziv), maxCena(refMaxCena), ListKarta(refListKarta), preostalo(refPreostalo) {}
  DinString getNaziv()const{return nazivPutovanja;}
  int getMaxCena()const{return maxCena;}
  bool findKartu(int id, int &retVal){
    AvionskaKarta& placeHolder;
    bool endCheck;
    int i = 0;
    do{
      endCheck = listKarte.read(i, placeHolder);
      if(placeHolder.getIdKarte() == id){
	retVal = i;
	return true;
      }
      ++i;}while(i < listKarte.size());
    return false;
  }
      
  bool dodajKartu(const AvionskaKarta& ref){
    AvionskaKarta lastKarta;
    int someInt;
    bool cardCheck = listKarte.read(listKarte.size(), lastKarta);
    if(cardCheck == false){
      cout << "Lista karti je prazna" << endl;
      if(ref.getCenaKarte() > maxCena){
        cout << "Nedovoljno para za putovanje" << endl;
        return false;}
      else{
	listKarte.add(1, ref);
	preostalo = maxCena - ref.getCenaKarte();
	return true;}
    }
    if(findKartu(ref.getidKarte(), someint) == false){
      if(ref.getCenaKarte() < preostalo){
	if(lastKarta.getMestoDolaska() != ref.getMestoPolaska()){
	  cout << "Lokacije se ne poklapaju" << endl;
	  return false;}
	else{
	  listKarte.add(listKarte.size()+1, ref);
	  cout << "Uspesno dodata karta." << endl;
	  preostalo -= ref.getCenaKarte();
	}}}}

  bool izbaciKartu(int id){
    int retVal;
    if(findKartu(id,retVal) == true)
      listKarte.remove(retVal);
    else
      return false;
    return true;
  }
};
  
