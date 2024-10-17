#include<iostream>

using namespace std;

class Magazin {
public:
	string oras;
	int nrAngajati;
	float suprafata;
	const int anDeschidere;// nu poate fi modificat
	static int impozitM2;// va fi declarat in zona de memorie a clasei (pt a ocupa mai putina memorie) si nu va fi initializat de constructorul Magazin

	Magazin():anDeschidere(2024),nrAngajati(2) {        // constructorul NU are tip returnat si se ocupa de obiect
		this->oras = "Bucuresti";
		this->suprafata = 50;
	}  

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {      // constructor cu parametri
		this->oras = oras;// stanga atributul, dreapta parametrul
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
	}

	void afisare() {
		cout << "Oras:" << this->oras << endl; //o metoda va primi pointerul this
		cout << "Nr Angajati:" << this->nrAngajati << endl;
		cout << "Suprafata:" << this->suprafata << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Impozit pe m2:" << this->impozitM2 << endl;
	}

	float calculeazaSuprafataMedie() {

		if (this->nrAngajati != 0)
		{
			return this->suprafata / this->nrAngajati;
		}
		else
			return 0;
	}

	static void modificaImpozit(int impozit) {
		if (impozit > 0)
		{
			Magazin::impozitM2 = impozit;
		}
	}

	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++)
		{
			suma += vector[i].suprafata;
		}
		return suma;
	}
};

int Magazin::impozitM2 = 2;//initializarea unui atribut static (in mod global)

int main() {
	Magazin m1;
	m1.afisare();
	Magazin::modificaImpozit(3);
	m1.modificaImpozit(4);

	Magazin m2("Iasi",7,200,2019);
	m2.afisare();

	Magazin* pointer = new Magazin("Timisoara", 4, 170, 2022);
	pointer->afisare(); // -> face atat dereferentiere, cat si accesare

	cout << "Suprafata medie pe angajat este de:" << pointer->calculeazaSuprafataMedie() << endl;

	int nrMagazine = 3;
	Magazin* vector = new Magazin[nrMagazine]; //va fi apelat constructorul de 3 ori

	//[] - face deplasare si dereferentiere

	for (int i = 0; i < nrMagazine; i++)
	{

		vector[i].afisare(); //(*(vector + i)).afisare()  sau vector[i]->afisare()
	}

	cout << "Suprafata totala:" << Magazin::calculeazaSuprafataTotala(vector, nrMagazine)<<endl;

	delete []vector;
	delete pointer;
	return 0;
}

//metodele sunt functii non-statice