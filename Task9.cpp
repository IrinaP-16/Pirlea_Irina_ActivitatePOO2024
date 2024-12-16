#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Rechizite {
protected:
	string marca;
	string culoare;
	float pret;

public:
	Rechizite(string NewMarca = "Default", string Culoare = "Albastru", float NewPret = 80) {  // cpnstructorul pt clasa abstracta, cu parametri
		marca = NewMarca;
		culoare = Culoare;
		pret = NewPret;
	}

	virtual float CalculeazaPret() = 0;// fct virtuala pura
	virtual void Afiseaza() = 0;
	
	virtual string getRechizite() {   // fct virtuale PURE trebuie implementate in clasele copil, dar cele normale(fct virtuale),nu trebuie implementate neaparat
		return "Rechizite";
	}

	virtual string getMarca() {
		return marca;
	}

	virtual string getCuloare() {
		return culoare;
	}

	void setMarca(string Marca) {
		this->marca = Marca;
	}

	void setCuloare(string Culoare) {
		this->culoare = Culoare;
	}
};


class ObiecteDepozitare {
protected:
	float capacitate;
	string model;
	string material;

	ObiecteDepozitare(float NewCapacitate=20, string NewModel="Multicolor", string NewMaterial="Piele") {
		capacitate = NewCapacitate;
		model = NewModel;
		material = NewMaterial;
	}

	virtual void AfisareCapacitate() = 0;//functii pure
	virtual void ModelulTeRog() = 0;

	virtual string ObiectDepozitare() {
		return "ObiectDepozitare";
	}
};

class Pix: public Rechizite
{
private:
	static int nrPixuri;
	const int lungime;

public:

	Pix() : lungime(12) {  //constructorul default
		nrPixuri = nrPixuri + 1;
		marca = "Default";
		culoare = "Albastru";
	}

	Pix(string culoare, string marca, int lungimeNou, float pret) : lungime(lungimeNou), Rechizite(marca, culoare, pret) {  // constructorul cu parametri
		nrPixuri++;
		
	}

	Pix(const Pix& p) : lungime(p.lungime) {   // constructorul de copiere
		nrPixuri++;
		culoare = p.culoare;
		marca = p.marca;
	}


	void Afiseaza()override {
		cout << "Nr pixuri : " << nrPixuri << endl;
		cout << "Culoare : " << culoare << endl;
		cout << "Marca:" << marca << endl;
		cout << "Lungime:" << lungime << endl;
	}

	float CalculeazaPret()override {
		return pret + 0.2 * pret;
	}

};

class Penar: public ObiecteDepozitare, public Rechizite
{
private:
	static int nrPenare;
	bool echipat;

public:

	Penar()  {   // constructor default
		nrPenare++;
		echipat = false;
	}
	Penar( bool echipat, string marca, string culoare, float pret, float capacitate, string model,string material) : Rechizite(marca, culoare, pret) ,ObiecteDepozitare(capacitate, model, material){   // constructor cu parametri
		nrPenare++;
		this->echipat = echipat;
	}

	void AfisareCapacitate() override {
		cout << "Capacitate penar: " << capacitate<<endl;
	}

	void ModelulTeRog() override {
		cout << "Model penar: " << model<<endl;
	}

	void Afiseaza() override {
		cout << "Marca penar: " << marca<<endl;
		cout << "Pretul penarului: " << pret<<endl;
		cout << "Culoarea penarului: " << culoare << endl;
	}

	float CalculeazaPret() override {
		return pret + 0.5 * pret;
	}
};


class Caiet: public Rechizite
{
private:
	static int nrCaiete;
	int Nrfile;
	const string tip;
	

public:

	Caiet() :tip("Dictando") {
		nrCaiete++;
		Nrfile = 0;
	}

	Caiet(int Nrfile, string tipNou, string NewMarca, string Culoare, float NewPret) : tip(tipNou), Rechizite(NewMarca,Culoare,NewPret) {
		nrCaiete++;
		this->Nrfile = Nrfile;
	}

	Caiet(const Caiet& c) : tip(c.tip) {
		nrCaiete++;
		Nrfile = c.Nrfile;
	}
     
	void Afiseaza() override {
		cout << "Nr file: " << Nrfile << endl;
		cout << "Tipul:" << tip << endl;
		cout << "Marca" << marca << endl;
		cout << "Culoare caiet: " << culoare << endl;
		cout << "Pret caiet: " << pret << endl;
	}

	float CalculeazaPret() override {
		return pret + 0.8 * pret;
	}
};

class Ghiozdan: public ObiecteDepozitare {
private:
	vector<Rechizite*>obiecte;// numele vectorului: obiecte, tipul vectorului:Rechizite

public:
	Ghiozdan(float Capacitate, string Model, string Material) : ObiecteDepozitare(Capacitate, Model, Material) {

	}

	void AdaugaObiect(Rechizite* obiect){ // adaugare element in vector folosind tipul de date vector
		obiecte.push_back(obiect);
	}

	void AfisareCapacitate() override {
		cout << "Capacitate penar: " << capacitate << endl;
	}

	void ModelulTeRog() override {
		cout << "Model penar: " << model << endl;
	}
};


int Pix::nrPixuri = 0;
int Penar::nrPenare = 0;
int Caiet::nrCaiete = 0;


int main()
{
	vector<Rechizite*>obiecte;
	obiecte.push_back(new Pix("Roz", "Herlitz", 25,80));
	obiecte.push_back(new Penar(true, "Dino", "Violet", 150.5, 25, "Simplu", "Sintetic"));
	obiecte.push_back(new Caiet(100, "Matematica", "Pigna", "Verde", 15));

	for (auto i : obiecte) {
		cout << "pret:" << i->CalculeazaPret() << endl;
		cout << "Categoria: " << i->getRechizite() << endl;
		cout << "Culoarea: " << i->getCuloare() << endl;
		cout << "Marca: " << i->getMarca() << endl;
	}
	return 0;

}