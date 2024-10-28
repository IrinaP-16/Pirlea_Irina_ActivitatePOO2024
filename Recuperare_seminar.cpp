#include<iostream>

using namespace std;

class Magazin {
private:
	string oras;
	int nrAngajati;
	float* salarii;
	float suprafata;
	const int anDeschidere;// nu poate fi modificat
	static int impozitM2;// va fi declarat in zona de memorie a clasei (pt a ocupa mai putina memorie) si nu va fi initializat de constructorul Magazin


public:
	Magazin() :anDeschidere(2024), nrAngajati(0) {        // constructorul NU are tip returnat si se ocupa de obiect; in constructori sunt initializate valortile atributelor
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;//NULL=0, nullptr nu e ac lucru, deci nu trebuie alternate; ori NULL, ori nullptr
	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {      // constructor cu parametri
		this->oras = oras;// stanga atributul, dreapta parametrul
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++)
		{
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& m) :anDeschidere(m.anDeschidere) //lista de initializare a constructorului
	{
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++)
		{
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}

	// ~destructorul distruge obiectul cand se termina durata de viata a obiectului
	// cate obiecte avem, de atatea ori va fi apelat destructorul

	~Magazin() { //nu are tip returnat, nu primeste parametru
		if (this->salarii)
		{
			delete[]this->salarii;
		}
	}

	Magazin operator=(const Magazin& m) {
		if (&m != this) { //verificare de autoasignare

		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++)
		{
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}
		return *this;
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	void setNrAngajati(int nrAngajati, float* salarii) { //la setteri mereu se verifica faptul ca parametrul e diferit de 0
		if (nrAngajati > 0)
		{
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL)
			{
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < nrAngajati; i++)
			{
				this->salarii[i] = salarii[i];// atributul = parametrul
			}
		}
	}

	float getSuprafata() {
		return this->suprafata;

	}

	void setSuprafata(float suprafataNoua)
	{
		if (suprafata > 0)
		{
			this->suprafata = suprafata;
		}

	}

	float* getSalarii() {      //getSalarii returneaza un pointer, deci o adresa
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati)
		{
			return this->salarii[index];
		}
	}

	Magazin operator+(Magazin m2)const { // acest operator e de fapt o metoda, iar metodele sunt apelate prin obiect
		Magazin temp = *this;
		temp.nrAngajati = this->nrAngajati + m2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++)
		{
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < m2.nrAngajati; i++)
		{
			aux[i + this->nrAngajati] = m2.salarii[i];
		}

		if (temp.getSalariu != NULL)
		{
		
		delete[]temp.salarii;
	    }
		temp.salarii = aux;
		return temp;
	}

	Magazin operator+(float salariu) const
	{
		Magazin temp= *this;
		if (temp.salarii != NULL)
		{
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++)
		{
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati]=salariu;
		temp.nrAngajati++;
		return temp;
	}

	friend Magazin operator+(float salariu, Magazin m) //devine fct inline prin friend
	{
		Magazin temp = m;
		if (temp.salarii != NULL)
		{
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < m.nrAngajati; i++)
		{
			temp.salarii[i] = m.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	Magazin& operator+=(Magazin m) {
		*this = *this + m;
		return *this;
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

 Magazin operator+(float salariu, Magazin& m) {
	float valoare = m.nrAngajati;
	return m + salariu;
}
Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}

int main() {
	Magazin m1;
	cout << m1.getNrAngajati() << endl;
	m1.setNrAngajati(6, new float [6] {2, 5, 4, 8, 6, 3}); //initializare inline, mai inatai ii aloc spatiu si apoi completez valorile
	cout << m1.getNrAngajati() << endl;

	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << m2.getSalarii()[1] << endl; // 114 si 115 sunt echivalente
	cout << m2.getSalariu(1) << endl;
	m2.setNrAngajati(5, new float [5] {5, 8, 3, 9, 4});

	cout << m2.getSalariu(3) << endl;

	Magazin* vector = new Magazin[100]; //- va fi apelat constructorul implicit de 100 de ori
	delete[]vector;// - va fi apelat destructorul de 100 de ori

	Magazin m3(m2); //153 si 154 sunt echivalente
	Magazin m4 = m2;
	Magazin m5;
	//m5 = m2;

	m2 = m2; //autoasignare

	Magazin m1;
	Magazin m2("Bucuresti", 3, 80, 2019);
	f(m4);

	int a = 9;
	int b = 6;
	int c = a + b;//c=15

	Magazin m3 = m1 + m2;
	Magazin m4 = m1.operator+(m2);
	Magazin m5 = m1 + 2000.0f; //m1.operator+(2000.0f)
	Magazin m6 = 3000.0f + m1;
	m1 += m2; //m1.operator+=(m2)
	return 0;
}

//metodele sunt functii non-statice

// [] index: deplasare + dereferentiere
// -> sageata: accesare + dereferentiere
// daca avem alocari dinamice, trebuie sa avem constructorul de copiere
// & o referinta la adresa