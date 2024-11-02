#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Pix
{public:
	static int nrPixuri;
	string culoare;
	const int lungime;
	char* marca;

	Pix(): lungime(12)  {  //constructorul default
		nrPixuri = nrPixuri + 1;
		marca = new char[30];
		strcpy(marca, "Default");
		culoare = "Albastru";
	}

	Pix( string culoare, char* marca, int lungimeNou):  lungime(lungimeNou) {
	   nrPixuri++;
	   this->culoare = culoare;
	   this->marca = new char[strlen(marca) + 1];
	   strcpy(this->marca, marca);
	}

	Pix(const Pix& p): lungime(p.lungime) {
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

	void afisare() {
		cout << "Nr pixuri : " << nrPixuri << endl;
		cout << "Culoare : " << culoare << endl;
		cout << "Marca:" << marca << endl;
		cout << "Lungime:" << lungime << endl;
	}
};

class Penar
{public:
	static int nrPenare;
	int* capacitate;
	const string model;
	bool echipat;

	Penar():model("Default") {
		nrPenare++;
		capacitate = new int(15);
		echipat = false;
	}
	Penar( int* capacitate, string modelNou, bool echipat): model(modelNou) {
		nrPenare++;
		this->capacitate = new int(*capacitate);
		this->echipat = echipat;
	}
	Penar(const Penar& pe): model(pe.model) {
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

	void afisare() {
		cout << "Nr penare : " << nrPenare<<endl;
		cout << "Capacitate: " << *capacitate << endl;
		cout << "Model : " << model << endl;
		cout << "Echipat: " << echipat << endl;
	}
};

class Caiet
{public:
	static int nrCaiete;
	int Nrfile;
	const string tip;
	char* brand;

	Caiet():tip("Dictando") {
		nrCaiete++;
		Nrfile = 0;
		brand = new char[30];
		strcpy(brand, "Standard");
	}
	Caiet(int Nrfile, string tipNou, char* brand): tip(tipNou) {
		nrCaiete++;
		this->Nrfile = Nrfile;
		this->brand = new char[strlen(brand) + 1];
		strcpy(this->brand, brand);
	}

	Caiet(const Caiet& c): tip(c.tip) {
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

	void afisare() {
		cout << "Nr caiete: " << nrCaiete << endl;
		cout << "Nr file : " << Nrfile << endl;
		cout << "Tipul: " << tip << endl;
		cout << "Brandul: " << brand << endl;

	}
};

int Pix::nrPixuri = 0;
int Penar::nrPenare = 0;
int Caiet::nrCaiete = 0;

int main()
{
	Pix* p1 = new Pix();
	Pix p2("Portocaliu", (char*)"Poenari", 14);
	Pix p3(p2); 
	cout << Pix::getPixuri()<<endl;
	p1->afisare();
	p2.afisare();
	p3.afisare();


	Penar* pe1 = new Penar();
	int* capacitate = new int (20);
	Penar pe2(capacitate,"Compartimentat", true);
	Penar pe3(pe2);
	cout << "Nr Penare: " << Penar::getPenare()<<endl;
	pe1->afisare();
	pe2.afisare();
	pe3.afisare();
		
	Caiet* c1 = new Caiet();
	Caiet c2(80, "Matematica", (char*)"Pigna");
	Caiet c3(c2);
	c1->afisare();
	c2.afisare();
	c3.afisare();
	cout << "Nr caiete:" << Caiet::getCaiete() << endl;

}


