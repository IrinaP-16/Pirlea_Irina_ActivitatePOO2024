#include<iostream>;
using namespace std;

struct Apartament {
	char* adresa;
	char scara;
	string proprietar;
	int nrCamere;
	float suprafata;

};

void afisareApartament(Apartament* ap) {
	cout << "Adresa:" << ap->adresa << endl;
	cout << "Proprietar:" << ap->proprietar << endl;
	cout << "Numar camere:" << ap->nrCamere << endl;
	cout << "Suprafata:" << ap->suprafata << endl;

};

Apartament citireApartament() {
	Apartament ap;
	cout << "Adresa:";
	char buffer[100];
	cin >> buffer;
	ap.adresa = new char[strlen(buffer) + 1];
	strcpy_s(ap.adresa, strlen(buffer) + 1, buffer);

	cout << "Proprietar:";
	cin >> ap.proprietar;
	cout << "Numar camere:";
	cin >> ap.nrCamere;
	cout << "Suprafata:";
	cin >> ap.suprafata;
	return ap;

}

int main() {
	Apartament ap;
	Apartament* pointer;
	ap.nrCamere = 3;

	pointer = new Apartament();//1 singur apartament
	pointer->nrCamere = 5;
	pointer->proprietar = "Gigel";//string
	pointer->adresa = new char[strlen("Bucuresti")+1];//char
	strcpy_s(pointer->adresa, strlen("Bucuresti") + 1, "Bucuresti");
	pointer->suprafata = 120;

	afisareApartament(pointer);
	delete pointer;
	
	int nrApartamente = 2;
	Apartament *apartamente;
	apartamente = new Apartament[2];//am nevoie de 2 apartamente
	for (int i = 0; i < nrApartamente; i++) {
		apartamente[i] = citireApartament();

	}

	for (int i = 0; i < nrApartamente; i++) {
		afisareApartament(&(apartamente[i]));
	}

	for (int i = 0; i < nrApartamente; i++)
	{
		delete[]apartamente[i].adresa; //mai intai sterg fiecare adresa
	}
	delete[]apartamente;


	//Apartament** pointeri;//se pun ** pt ca am vector de pointeri
	//pointeri = new Apartament* [3]; // 3 pointeri la apartament, Apartament*-tipul

	return 0;
}
