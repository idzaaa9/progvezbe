#include <iostream>
#include "dinstring.hpp"

class Alat{
protected:
  DinString proizvodjac;
  DinString serijskiBroj;
public:
  Alat() : proizvodjac("Ken-Tool"), serijskiBroj("00000") {}
  Alat(const char naziv[], const char broj[]) : proizvodjac(naziv), serijskiBroj(broj) {}
  Alat(const Alat& ref) : proizvodjac(ref.proizvodjac),  serijskiBroj(ref.serijskiBroj) {}
  Alat(const DinString& ref1, const DinString& ref2) : proizvodjac(ref1), serijskiBroj(ref2) {}
  DinString getPro()const  {return proizvodjac;}
  DinString getSer() const {return serijskiBroj;}
  virtual void ispis() = 0;
};

class Cekic : protected Alat{
private:
  double tezina;
  unsigned upotrebljivost;
public:
  Cekic() : Alat(), tezina(2), upotrebljivost(100) {}
  Cekic(const char refProiz[], const char refSB[], double refTez, unsigned refUpo) : Alat(refProiz, refSB), tezina(refTez), upotrebljivost(refTez) {}
  Cekic(const Cekic& ref) : Alat(ref.proizvodjac, ref.serijskiBroj), tezina((double)ref.getTez()), upotrebljivost((unsigned)ref.getUpo()) {}
  double getTez()const {return tezina;}
  unsigned getUpo()const {return upotrebljivost;}
  void setTez(double ref) {tezina = ref;}
  void setUpo(unsigned ref) {upotrebljivost = ref;}
  void ispis(){
    cout << "Proizvodjac cekica je" << proizvodjac  << "." << endl;
    cout << "Serijski broj cekica je" << serijskiBroj << "." << endl;
    cout << "Tezina cekica je" << tezina << "." << endl;
    cout << "Upotrebljivost cekica je" << upotrebljivost << "." << endl;
  }
  bool upotrebi(){
    if(upotrebljivost > 0){
      setUpo(upotrebljivost - 1);
      cout << "Uspesno upotrebljen cekic." << endl;
      return true;}
    cout << "Cekic je neupotrebljiv." << endl;
    return false;
  }
};

class Testera : protected Alat{
private:
  double otupljenost;
public:
  Testera() : Alat(), otupljenost(0) {}
  Testera(const char refPro[], const char refSB[], double refOtu) : Alat(refPro, refSB), otupljenost(refOtu) {}
  Testera(const Testera& ref) : Alat(ref.proizvodjac, ref.serijskiBroj), otupljenost(ref.getOtu()) {}
  double getOtu()const {return otupljenost;}
  void setOtu(double ref){otupljenost = ref;}
  bool upotrebi(){
    if(otupljenost <= 0.95){
      setOtu(otupljenost + 0.05);
      cout << "Uspesno upotrebljena testera." << endl;
      return true;}
    cout << "Testera je neupotrebljiva" << endl;
    return false;
  }
  bool naostri(){
    if(otupljenost >= 0.05){
      setOtu(otupljenost - 0.05);
      cout << "Uspesno naosterna testera." << endl;
      return true;}
    cout << "Testera se ne moze naostriti." << endl;
    return false;
  }
  void ispis(){
    cout << "Proizvodjac testere je " << proizvodjac << "." << endl;
    cout << "Serijski broj testere je " << serijskiBroj << "." << endl;
    cout << "Otupljenost testere je " << otupljenost << "." << endl;
  }
};

int main(){
  Cekic prvi;
  Cekic drugi("m", "n", 15, 15);
  Cekic treci(prvi);
  double bbb = drugi.getTez();
  unsigned ccc = drugi.getUpo();
  treci.setTez(1);
  treci.setUpo(50);
  treci.ispis();
  bool neki = treci.upotrebi();
  Testera prva;
  Testera druga("asd", "qwer", 0.55);
  Testera treca(prva);
  bbb = prva.getOtu();
  druga.setOtu(0.6);
  treca.ispis();
  neki = treca.upotrebi();
  neki = treca.naostri();
  return 0;
}
