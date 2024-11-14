#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Prajitura {
private:
	char* denumire;
	int nrCalorii;
	int nrIngrediente;
	float* gramajIngrediente;
	bool esteVegana;
	bool contineGluten;
	static int nrPrajiVandute;

public:
	Prajitura() {
		denumire = new char [50];
		strcpy(denumire, "Red Velvet");
		nrCalorii = 500;
		nrIngrediente = 7;
		gramajIngrediente = new float[nrIngrediente]; // pt vector de double/float/int se foloseste for
		for (int i = 0; i < nrIngrediente; i++)
			gramajIngrediente[i] = 100;
		esteVegana = false;
		contineGluten = true;
		nrPrajiVandute++;
	}

	friend ostream& operator<<(ostream& os, Prajitura& pr) {
		os << "Denumire praji: " << pr.denumire << endl;
		os << "Nr calorii: " << pr.nrCalorii << endl;
		os << "Nr de ingrediente: " << pr.nrIngrediente << endl;
		os << "Gramaj ingrediente: " << endl;
		for (int i = 0; i < pr.nrIngrediente; i++)
			os << pr.gramajIngrediente[i]<<endl;
		if (pr.esteVegana == 1)
			os << "Prajitura este vegana" << endl;
		else
			os << "Prajitura nu este vegana" << endl;
		if (pr.contineGluten == 1)
			os << "Prajitura contine gluten." << endl;
		else
			os << "Prajitura nu contine gluten." << endl;
		os << "Numar de prajituri vandute: " << pr.nrPrajiVandute << endl;
		return os;
	}

	// SUPRAINCARE *=(int)

	Prajitura& operator*=(int valoare) {
		for (int i = 0; i < nrIngrediente; i++)
			this->gramajIngrediente[i] *= valoare;
		return *this;
	}

	friend Prajitura& operator+(float ingredient, Prajitura& pr) {
		if (ingredient < 0)
			throw invalid_argument("Valoarea nu e conforma.");
		else
		{
			float* aux = new float[pr.nrIngrediente + 1];
			for (int i = 0; i < pr.nrIngrediente; i++)
				aux[i] = pr.gramajIngrediente[i];
			aux[pr.nrIngrediente] = ingredient;
			delete[] pr.gramajIngrediente;
			pr.gramajIngrediente = aux;
			pr.nrIngrediente++;
			return pr;
		}
	}

};

int Prajitura::nrPrajiVandute = 0;

int main() {
	Prajitura p1;
	cout << p1<<endl;

	p1 *= 5;
	cout << p1 << endl;

	p1 = 3 + p1;
	cout<<p1<< endl;


}