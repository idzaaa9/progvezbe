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
	Pravougaonik(){
		a = 10;
		b = 5;
	}
	Pravougaonik(int a1, int b1){
		a = a1;
		b = b1;
	}
	Pravougaonik(const Pravougaonik& ref){
		a = ref.a;
		b = ref.b;
	}
	int getA() const 	{return a;}
	int getB() const	{return b;}
	float obim()	{return 2*(a+b);}
	float povrsina()	{return a*b;}
};

class Elipsa : public Figura{
protected:
	int x,y;
public:
	Elipsa()	{x = 10; y = 5;}
	Elipsa(int a,int b)	{x = a; y = b;}
	Elipsa(const Elipsa& ref)	{x = ref.x; y = ref.y;}
	int getX() const	{return x;}
	int getY() const	{return y;}
	float obim()	{return 3.14*(3*(x+y)-sqrt((3*x+y)*(x+3*y)));}
	float povrsina()	{return x*y*3.14;}
};

class Oblik{
protected:
	Pravougaonik A;
	Elipsa B;
public:
	Oblik() : A(10, 5), B(10, 5) {}
	Oblik(int a, int b) : A(a, b), B(a, b)	{}
	Oblik(const Oblik& ref) : A(ref.A.getA(), ref.A.getB()), B(ref.B.getX(), ref.B.getY())	{}
	float obim()	{return A.obim()+B.obim();} 
	float povrsina() {return A.povrsina() - B.povrsina();}
	int getAa()	const	{return A.getA();}
	int getAb()	const	{return A.getB();}
};

class PravilanOblik : public Oblik{
public:
	PravilanOblik(int a) : Oblik(a, a)	{}
	PravilanOblik() : Oblik(5, 5)	{}
	PravilanOblik(const PravilanOblik& ref)	{}
};

int main(int argc, char** argv) {
	Pravougaonik prvi, drugi(10, 15);
	Pravougaonik treci(drugi);
	int a = prvi.getA();
	a = prvi.getB();
	float b = prvi.obim();
	b = prvi.povrsina();
	Elipsa prva, druga(10, 15);
	Elipsa treca(druga);
	a = prva.getX();
	a = prva.getY();
	b = prva.obim();
	b = prva.povrsina();
	Oblik prviO, drugiO(15, 20);
	Oblik treciO(prviO);
	b = treciO.obim();
	b = treciO.povrsina();
	PravilanOblik(5);
	return 0;
}
