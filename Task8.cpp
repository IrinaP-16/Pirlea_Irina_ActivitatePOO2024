#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
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

	Pix(string culoare, char* marca, int lungimeNou) : lungime(lungimeNou) {  // constructorul cu parametri
		nrPixuri++;
		this->culoare = culoare;
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}

	Pix(const Pix& p) : lungime(p.lungime) {   // constructorul de copiere
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

	friend bool operator <=(Pix& p1, Pix& p2) {   // <, >, <=, >=, !=. == -- sunt de tip bool
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

	friend istream& operator >>(istream& is, Pix& p) {
		cout << "Introduceti nr pixuri:"; is >> p.nrPixuri;
		cout << "Introduceti culoarea: "; is >> p.culoare;
		cout << "Introduceti marca: "; is >> p.marca;
		return is;
	}

	void ScriePixInFisier(string file) {
		ofstream f(file);
		if (!f.is_open())
			throw runtime_error("Fisierul nu poate fi deschis");
		else
		{
			f << "Nr pixuri: " << nrPixuri << endl;
			f << "Culoare pix: " << culoare << endl;
			f << "Marca pix: " << marca << endl;
			f << "Lungime pix: " << lungime << endl;
		}

	}

	void PixInFisierBinar(string file) {
		ofstream f(file,ios::binary);
		if (!f.is_open())
			throw runtime_error("Fisierul nu se poate deschide.");
		else
		{
			f.write(reinterpret_cast<char*>(&nrPixuri), sizeof(nrPixuri));
			int lungimeCuloare = culoare.length();
			f.write(reinterpret_cast<char*>(&lungimeCuloare), sizeof(lungimeCuloare));
			f.write(culoare.c_str(), lungimeCuloare);
			int lungimeMarca = strlen(marca);
			f.write(reinterpret_cast<char*>(&lungimeMarca), sizeof(lungimeMarca));
			f.write(marca, lungimeMarca);
			f.close();
		}
	}

	void CitireFisierBinar(string file) {
		ifstream f(file, ios::binary);
		if (!f.is_open())
			throw exception("Fisierul nu poate fi deschis");
		else
		{
			f.read(reinterpret_cast<char*>(&nrPixuri), sizeof(nrPixuri));
			int LungimeCuloare;
			f.read(reinterpret_cast<char*>(&LungimeCuloare), sizeof(LungimeCuloare));
			char* aux = new char[LungimeCuloare + 1];
			f.read(aux, LungimeCuloare);
			aux[LungimeCuloare] = '\0';
			culoare = string(aux);
			int LungimeMarca;
			f.read(reinterpret_cast<char*>(&LungimeMarca), sizeof(LungimeMarca));
			if (marca != nullptr)
				delete[] marca;
			marca = new char[LungimeMarca + 1];
			f.read(marca, LungimeMarca);
			marca[LungimeMarca] = '\0';
			f.close();

			cout << endl<<"Citire din fisier binar: "<<endl;
			cout << "Nr pixuri " << nrPixuri << endl;
			cout << "Culoarea pixului " << culoare << endl;
			cout << "Marca pix: " << marca << endl;

		}
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

	Penar() :model("Default") {   // constructor default
		nrPenare++;
		capacitate = new int(15);
		echipat = false;
	}
	Penar(int* capacitate, string modelNou, bool echipat) : model(modelNou) {   // constructor cu parametri
		nrPenare++;
		this->capacitate = new int(*capacitate);
		this->echipat = echipat;
	}
	Penar(const Penar& pe) : model(pe.model) {   // constructor de copiere
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

	friend ostream& operator<<(ostream& os, Penar& pe) {
		if (pe.echipat == 0)
			os << "echipat: false" << endl;
		else
			os << "echipat: true" << endl;
		os << "Capacitate: " << *pe.capacitate << endl;
		os << "Nr de penare: " << pe.nrPenare << endl;
		os << "Modelul: " << pe.model << endl;
		return os;
	}

	Penar& operator=(Penar& pe) {
		*this->capacitate = *pe.capacitate;
		this->nrPenare = pe.nrPenare;
		this->echipat = pe.echipat;
		return *this;
	}

	friend bool operator !=(Penar& pe1, Penar& pe2) {
		if (*pe1.capacitate != *pe2.capacitate)
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

	friend istream& operator>>(istream& is, Caiet& c) {
		cout << "Introduceti nr de caiete: "; is >> c.nrCaiete;
		cout << "Introduceti nr de file: "; is >> c.Nrfile;
		cout << "Introduceti brandul: "; is >> c.brand;
		return is;
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

class Ghiozdan {
private:
	Caiet* caiete;
	Penar penar;
	Pix* pixuri;
	int nrCaiete;
	int nrPixuri;
	float pret;

public:
	Caiet* getCaiete() {
		return caiete;
	}

	Penar getPenare() {
		return penar;
	}

	Pix* getPixuri() {
		return pixuri;
	}

	float getPret() {
		return pret;
	}

	void adaugaCaiet(Caiet c1) {
		Caiet* aux = new Caiet[nrCaiete + 1];
		for (int i = 0; i < nrCaiete; i++)
			aux[i] = caiete[i];
		aux[nrCaiete] = c1;
		delete[] caiete;
		caiete = aux;
		nrCaiete++;
	}

	void adaugaPix(Pix p1) {
		Pix* aux = new Pix[nrPixuri + 1];
		for (int i = 0; i < nrPixuri; i++)
			aux[i] = pixuri[i];
		aux[nrPixuri] = p1;
		delete[] pixuri;
		pixuri = aux;
		nrPixuri++;
	}

	void setPenar(Penar p) {
		this->penar = p;
	}

	Ghiozdan()
	{
		caiete = new Caiet[10];
		pixuri = new Pix[10];
	}

	Ghiozdan(float pret)
	{
		this->caiete = new Caiet[10];
		this->pixuri = new Pix[10];
		this->pret = pret;
	}

	~Ghiozdan() {
		delete[] caiete;
		delete[] pixuri;
	}

	friend ostream& operator<<(ostream& os, Ghiozdan& g) {
		os << "Caiete: " << endl;
		for (int i = 0; i < g.nrCaiete; i++)
			os << g.caiete[i] << endl;
		os << "Pixuri: " << endl;
		for (int i = 0; i < g.nrPixuri; i++)
			os << g.pixuri[i] << endl;
		os << "Penare: " << g.penar << endl;
		return os;
	}

	friend Ghiozdan operator+(Ghiozdan& g1, Ghiozdan& g2) {
		float s = 0;
		s = g1.pret + g2.pret;
		return Ghiozdan(s);
	}

	Ghiozdan& operator=(const Ghiozdan& g) {
		this->pret = g.pret;
		return *this;
	}
};

class GhiozdanTroller : public Ghiozdan {
private:
	int nrRoti;
	float inaltime;
	bool areModel;
	string brand;

public:
	GhiozdanTroller() {
		nrRoti = 2;
		inaltime = 60.5;
		areModel = true;
		brand = "Desigual";
	}

	GhiozdanTroller(int nrRoti, float inaltime, bool areModel, string brand) {
		this->nrRoti = nrRoti;
		this->inaltime = inaltime;
		this->areModel = areModel;
		this->brand = brand;
	}

	GhiozdanTroller(int nrRoti, float inaltime, bool areModel, string brand, float pret) : Ghiozdan(pret) {
		this->nrRoti = nrRoti;
		this->inaltime = inaltime;
		this->areModel = areModel;
		this->brand = brand;
	}

	int getNrRoti() {
		return nrRoti;
	}

	float getInaltime() {
		return inaltime;
	}

	bool getAreModel() {
		return areModel;
	}

	string getBrand() {
		return brand;
	}

	void setNrRoti(int NewnrRoti) {
		this->nrRoti = NewnrRoti;
	}
	void setInaltime(float NewInaltime) {
		this->inaltime = NewInaltime;
	}
	void setAreModel(bool NewAreModel) {
		this->areModel = NewAreModel;
	}
	void setBrand(string NewBrand) {
		this->brand = NewBrand;
	}

	friend ostream& operator<<(ostream& os, GhiozdanTroller& gt) {
		os << "Nr de roti: " << gt.nrRoti << endl;
		os << "Inaltime: " << gt.inaltime << endl;
		os << "Are model: " << gt.areModel << endl;
		os << "Brand: " << gt.brand << endl;
		return os;
	}
};

class RucsacScoala : public Ghiozdan {
private:
	float greutate;
	bool eIncapator;
	string model;
	int compartimente;

public:
	RucsacScoala() {
		greutate = 700;
		eIncapator = true;
		model = "Natura";
		compartimente = 5;
	}

	RucsacScoala(float NewGreutate, bool eIncapator, string NewModel, int NrCompartimente) {
		this->greutate = NewGreutate;
		this->eIncapator = eIncapator;
		this->model = NewModel;
		this->compartimente = NrCompartimente;
	}

	RucsacScoala(float NewGreutate, bool eIncapator, string NewModel, int NrCompartimente, int nrPixuri) : Ghiozdan(nrPixuri) {
		this->greutate = NewGreutate;
		this->eIncapator = eIncapator;
		this->model = NewModel;
		this->compartimente = NrCompartimente;
	}

	float getGreutate() {
		return greutate;
	}

	bool getEincapator() {
		return eIncapator;
	}

	string getModel() {
		return model;
	}

	int getCompartimente() {
		return compartimente;
	}

	void setGreutate(float NewGreutate) {
		this->greutate = NewGreutate;
	}

	void setEincapator(bool eIncapator) {
		this->eIncapator = eIncapator;
	}

	void setModel(string NewModel) {
		this->model = NewModel;
	}

	void setCompartimente(int NrCompartimente) {
		this->compartimente = NrCompartimente;
	}

	friend ostream& operator<<(ostream& os, RucsacScoala& rs) {
		os << "Greutatea rucsacului: " << rs.greutate << endl;
		os << "E rucsacul incapator? " << rs.eIncapator << endl;
		os << "Modelul rucsacului: " << rs.model << endl;
		os << "Numar compartimente: " << rs.compartimente << endl;
		return os;
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

	try {
		p2.ScriePixInFisier("PixNou.txt");

		p2.PixInFisierBinar("PixFisierBinar.bin");

		p2.CitireFisierBinar("PiFisierBinar.bin"); //trebuie sa aiba acelasi nume ca fisierul in care am scris

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return 0;

}