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

	int* getCapacitate(){
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
};

int Pix::nrPixuri = 0;
int Penar::nrPenare = 0;
int Caiet::nrCaiete = 0;

void afiseazaPenar(Penar& p) {
	cout << "Nr penare: " << p.nrPenare<<endl;
	cout << "Capacitate: " << *p.capacitate << endl;
	cout << "Model penar: " << p.model<<endl;
	cout << "Echipat: " << p.echipat << endl;
}

void afiseazaCaiet(Caiet& c) {
	cout << "Nr caiete: " << c.nrCaiete << endl;
	cout << "Nr file: " << c.Nrfile << endl;
	cout << "Brand: " << c.brand<<endl;
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


	cout<<c2.getBrand();
	c2.setBrand((char*)"Herlitz");
}