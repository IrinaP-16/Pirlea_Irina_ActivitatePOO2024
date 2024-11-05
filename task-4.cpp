#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Pix
{
private:
	static int nrPixuri;
	string culoare;
	const int lungime;
	char* marca;

public:

	Pix() : lungime(12) {  //constructorul default
		nrPixuri = nrPixuri + 1;
		marca = new char[30];
		strcpy(marca, "Default");
		culoare = "Albastru";
	}

	Pix(string culoare, char* marca, int lungimeNou) : lungime(lungimeNou) {
		nrPixuri++;
		this->culoare = culoare;
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}

	Pix(const Pix& p) : lungime(p.lungime) {
		nrPixuri++;
		culoare = p.culoare;
		marca = new char[strlen(p.marca) + 1];
		strcpy(marca, p.marca);
	}

	~Pix() {
		nrPixuri--;
		delete[] marca; //pt cele alocate dinamic
	}

	static int getPixuri() {
		return nrPixuri;
	}

	string getCuloare() {
		return culoare;
	}

	char* getMarca() {
		return marca;
	}

	int getLungime() {
		return lungime;
	}

	void setPixuri(int nrPixuri) {
		this->nrPixuri = nrPixuri;
	}

	void setCuloare(string culoarePix) {
		this->culoare = culoarePix;
	}

	void setMarca(char* marcaPix) {
		this->marca = new char[(strlen(marcaPix) + 1)];
		strcpy(this->marca, marcaPix);
	}


	void afisare() {
		cout << "Nr pixuri : " << nrPixuri << endl;
		cout << "Culoare : " << culoare << endl;
		cout << "Marca:" << marca << endl;
		cout << "Lungime:" << lungime << endl;
	}

	Pix& operator=(Pix& p) {
		this->nrPixuri = p.nrPixuri;
		this->culoare = p.culoare;
		this->marca = new char[strlen(p.marca) + 1];
		strcpy(marca, p.marca);
		return *this;

	}

	friend bool operator <=(Pix& p1, Pix& p2) {   //<, >, <=, >=, !=. == -- sunt de tip bool
		if (p1.lungime <= p2.lungime)
			return true;
		return false;
	}

	Pix& operator +=(Pix& p) {      // se declara la fel pentru -=, *=, /=, +=
		this->nrPixuri += p.nrPixuri;
		return *this;
	}

	friend ostream& operator <<(ostream& os, Pix& p) {
		os << "Nr pixuri : " << p.nrPixuri << endl;
		os << "Culoare : " << p.culoare << endl;
		os << "Marca:" << p.marca << endl;
		os << "Lungime:" << p.lungime << endl;
		return os;
	}
};

class Penar
{
private:
	static int nrPenare;
	int* capacitate;
	const string model;
	bool echipat;

public:

	Penar() :model("Default") {
		nrPenare++;
		capacitate = new int(15);
		echipat = false;
	}
	Penar(int* capacitate, string modelNou, bool echipat) : model(modelNou) {
		nrPenare++;
		this->capacitate = new int(*capacitate);
		this->echipat = echipat;
	}
	Penar(const Penar& pe) : model(pe.model) {
		nrPenare++;
		capacitate = new int(*pe.capacitate);
		echipat = pe.echipat;
	}

	~Penar() {
		nrPenare--;
		delete capacitate;
	}

	static int getPenare() {
		return nrPenare;
	}

	int* getCapacitate() {
		return capacitate;
	}

	string getModel() {
		return model;
	}

	bool getEchipat() {
		return echipat;
	}

	void setNrPenare(int nrPenare) {
		this->nrPenare = nrPenare;
	}

	void setCapacitate(int* capacitatePenar) {
		*this->capacitate = *capacitatePenar;
	}

	void setEchipat(bool eEchipat) {
		this->echipat = eEchipat;
	}

	friend void afiseazaPenar(Penar& p);

	Penar& operator-=(Penar& pe) {
		*this->capacitate -= *pe.capacitate;
		return *this;
	}

	friend istream& operator >>(istream& is, Penar& pe) { // functia de citire
		cout << "Introduceti 1/0-echipat: "; is >> pe.echipat;
		cout << "Introduceti capacitatea: "; is >> *pe.capacitate;
		cout << "Introduceti nr de penare: "; is >> pe.nrPenare;
		return is;
	}

	Penar& operator=(Penar& pe) {
		*this->capacitate = *pe.capacitate;
		this->nrPenare = pe.nrPenare;
		this->echipat = pe.echipat;
		return *this;
	}

	friend bool operator !=(Penar& pe1, Penar& pe2) {
		if (*pe1.capacitate!= *pe2.capacitate)
			return true;
		return false;
	}
};

class Caiet
{
private:
	static int nrCaiete;
	int Nrfile;
	const string tip;
	char* brand;

public:

	Caiet() :tip("Dictando") {
		nrCaiete++;
		Nrfile = 0;
		brand = new char[30];
		strcpy(brand, "Standard");
	}
	Caiet(int Nrfile, string tipNou, char* brand) : tip(tipNou) {
		nrCaiete++;
		this->Nrfile = Nrfile;
		this->brand = new char[strlen(brand) + 1];
		strcpy(this->brand, brand);
	}

	Caiet(const Caiet& c) : tip(c.tip) {
		nrCaiete++;
		Nrfile = c.Nrfile;
		brand = new char[strlen(c.brand) + 1];
		strcpy(brand, c.brand);
	}

	~Caiet() {
		nrCaiete--;
		delete[] brand;
	}

	static int getCaiete() {
		return nrCaiete;
	}

	int getNrfile() {
		return Nrfile;
	}

	char* getBrand() {
		return brand;
	}

	void setCaiete(int NrCaiete) {
		this->nrCaiete = NrCaiete;
	}

	void setFile(int NrFile) {
		this->Nrfile = NrFile;
	}

	void setBrand(char* brandCaiet) {
		this->brand = new char[strlen(brandCaiet) + 1];
		strcpy(this->brand, brandCaiet);
	}

	friend void afiseazaCaiet(Caiet& c);

	Caiet& operator=(Caiet& c) {
		this->nrCaiete = c.nrCaiete;
		this->Nrfile = c.Nrfile;
		this->brand = new char[strlen(c.brand) + 1];
		strcpy(brand, c.brand);
		return *this;
	}

	friend ostream& operator <<(ostream& os, Caiet& c) {
		os << "Nr caiete: " << c.nrCaiete << endl;
		os << "Nr file: " << c.Nrfile << endl;
		os << "Brand: " << c.brand << endl;
		return os;
	}

	Caiet& operator *=(Caiet& c) {
		this->Nrfile *= c.Nrfile;
		return *this;
	}

	friend bool operator >=(Caiet& c1, Caiet& c2) {
		if (c1.Nrfile >= c2.Nrfile)
			return true;
		return false;
	}
};

int Pix::nrPixuri = 0;
int Penar::nrPenare = 0;
int Caiet::nrCaiete = 0;

void afiseazaPenar(Penar& p) {
	cout << "Nr penare: " << p.nrPenare << endl;
	cout << "Capacitate: " << *p.capacitate << endl;
	cout << "Model penar: " << p.model << endl;
	cout << "Echipat: " << p.echipat << endl;
}

void afiseazaCaiet(Caiet& c) {
	cout << "Nr caiete: " << c.nrCaiete << endl;
	cout << "Nr file: " << c.Nrfile << endl;
	cout << "Brand: " << c.brand << endl;
}

int main()
{
	Pix* p1 = new Pix();
	Pix p2("Portocaliu", (char*)"Poenari", 14);
	Pix p3(p2);
	cout << Pix::getPixuri() << endl;
	p1->afisare();
	p2.afisare();
	p3.afisare();


	Penar* pe1 = new Penar();
	int* capacitate = new int(20);
	Penar pe2(capacitate, "Compartimentat", true);
	Penar pe3(pe2);
	cout << "Nr Penare: " << Penar::getPenare() << endl;
	afiseazaPenar(*pe1);
	afiseazaPenar(pe2);
	afiseazaPenar(pe3);

	Caiet* c1 = new Caiet();
	Caiet c2(80, "Matematica", (char*)"Pigna");
	Caiet c3(c2);
	afiseazaCaiet(*c1);
	afiseazaCaiet(c2);
	afiseazaCaiet(c3);
	cout << "Nr caiete:" << Caiet::getCaiete() << endl;


	cout << c2.getBrand()<<endl;
	c2.setBrand((char*)"Herlitz");

	//Supraincarcare operator =  Clasa Pix

	Pix p4=p3;
	cout << endl;
	p3.afisare();
	cout << endl;
	p4.afisare();


	//Supraincarcare opertaor <= Clasa Pix

	if (p4 <= p3)
		cout << "lungimile sunt egale sau mai mici"<<endl;
	else
		cout << "lungimile NU sunt egale sau mai mici" << endl;
	cout << endl;
	//Supraincarcare operator += Clasa Pix

	p4 += p3;
	p4.afisare();

	//Supraincarcare operator << Clasa Pix
	cout <<endl<<p4;

	//Supraincarcare operator -= Clasa Penar
	pe3 -= pe2;
	cout << endl;
	afiseazaPenar(pe3);

	//Supraincarcare operator >> Clasa Penar
	cout << endl;
	Penar pe5;
	cin >> pe5;

	//Supraincarcare operator = Clasa Penar
	cout << endl;
	Penar pe6 = pe5;
	afiseazaPenar(pe6);

	//Supraincarcarea operatorului != Clasa Penar
	cout << endl;
	afiseazaPenar(pe2);
	cout << endl;
	if (pe6 != pe2)
		cout << "Penarele sunt diferite" << endl;
	else
		cout << "Penarele NU sunt diferite" << endl;

	//Supraincarcare operator = Clasa Caiet
	cout << endl;
	Caiet c4 = c2;
	afiseazaCaiet(c2);
	cout << endl;
	afiseazaCaiet(c4);
		
	//Supraincarcare operator << Clasa Caiet
	cout << endl<< c3;

	//Supraincarcare operator *= Clasa Caiet
	cout << endl;
	c4 *= c3;
	afiseazaCaiet(c3);
	cout << endl;
	afiseazaCaiet(c4);

	//Supraincarcare operator >= Clasa Caiet
	cout << endl;
	afiseazaCaiet(*c1);
	cout << endl;
	afiseazaCaiet(c3);
	cout << endl;
	if (*c1 >= c3)
		cout << "Numarul de file este mai mare sau egal " << endl;
	else
		cout << "Numarul de file NU este mai mare sau egal" << endl;

}   