#include <iostream>
#include <cmath>

using namespace std;

class Figura{
public:
    virtual float obim() = 0;
    virtual float povrsina() = 0;
};

class Pravougaonik : public Figura{
protected:
    int a, b;
public:
    Pravougaonik() : a(10), b(5)    {}
    Pravougaonik(int x, int y) : a(x), b(y) {}
    Pravougaonik(Pravougaonik& ref) : a(ref.getA()), b(ref.getB())  {}
    int getA() const {return a;}
    int getB() const {return b;}
    float obim() const {return 2*(a+b);}
    float povrsina() const {return a*b;}
};

class Elipsa : public Figura{
protected:
    int x, y;
public:
    Elipsa() : x(10), y(5)  {}
    Elipsa(int a, int b) : x(a), y(b)   {}
    Elipsa(Elipsa& ref) : x(ref.getX()), y(ref.getY())   {}
    int getX() const {return x;}
    int getY() const {return y;}
    float obim()    {return 2*3.14*sqrt((pow(x,2)+pow(y,2))/2);}
    float povrsina()    {return x*y*3.14;}
};

class Kvadrat : protected Pravougaonik{
public:
    Kvadrat() : Pravougaonik(5, 5)  {}
    Kvadrat(int x) : Pravougaonik(x, x) {}
    Kvadrat(Kvadrat& ref) : Pravougaonik(ref.getA(), ref.getA())    {}
};

class Krug : protected Elipsa{
public:
    Krug() : Elipsa(5,5)    {}
    Krug(int a) : Elipsa(a, a)  {}
    Krug(Krug& ref) : Elipsa(ref.getX(), ref.getX())    {}
};

class Oblik{
private:
    Kvadrat a;
    Krug b;
public:
    Oblik() : a(), b()   {}
    Oblik(int len) : a(len), b(len) {}
    Oblik(Oblik& ref) : a(ref.a.getA()), b(ref.a.getA())    {}
    float obim() const {return a.obim()-b.povrsina();}
    float povrsina() const {return a.povrsina() - b.povrsina();}
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
