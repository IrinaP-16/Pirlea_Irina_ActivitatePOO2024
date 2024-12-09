#include <iostream>

using namespace std;

//structura de is a

class Angajat {
protected:          //am acces la ele direct din clasele care mostenesc
	int marca;  // codul dupa care e identificat angajatul
	string nume;
	float salariu;

public:
	Angajat() {
		this->marca = 1234;
		this->nume = "No Name";
		this->salariu = 3000;
	}

	Angajat(int marca, string nume, float salariu) {
		this->marca = marca;
		this->nume =nume;
		this->salariu = salariu;
	}

	/*  float getSalariu() {
		 return this->salariu;
	}*/

	//virtuala ptr ca fiecare angajat are mai multe sporuri-in fct de ce fel de ang primeste mai mult/putine sporuri; 
	//tabela de pointeri la functii virtuale
	//fct virtual pura-> pointerul respectiv este initializat automat cu null =0
	//dc fct virt=0; o clasa care are cel putin o fct virtual pura-> clasa abstracta
	// cls abstracta -> nu pot sa mi declar obiecte de tipul acelei clase (abstracte)/ nu poate fi instantiata;
	//->la randul ei clasa manager nu poate fi instantiata; e mostenita a fi cls abstracta
	//-fac o suprascriere in clasa m de proiect si de dep ptr a functiona
	//o cls abstracta ne permite sa vem constructori- pe care ii va folosi cls fiu-manager...
	//permite sa extindem codul-mostenire + destructor..
	//nu mi permite crearea de obiecte dar pot declara pointeri la obiecte;!!!!!!!!!
	//pointer= new Angajat() nu ma lasa
	//pointer =NULL DA
	//ma lsa sa pun un obiect de tipul clasei fiu


	virtual float getVenitIncasat() = 0;


};

class Manager : public Angajat {
private:
	int nrSubordonati;
	float sporPerSubordonat;

public:
	Manager() : Angajat() {  //construnctorul fara param apeleaza constructorul fara p de la angajat
		this->nrSubordonati=0;
		this->sporPerSubordonat = 0;
	}

	Manager(int nrSubordonati, float sporPerSubordonat) :Angajat(){
		this->nrSubordonati = nrSubordonati;
		this->sporPerSubordonat = sporPerSubordonat;
	}

	// metoda pentru spor
	float getSporConducere() {
		return this->nrSubordonati * this->sporPerSubordonat;
	}

};

class ManagerDepartament :public Manager {
private:
	string numeDepartament;
	bool deCercetare; // pt true => e dept de cercetare si primeste bonus

public:
	ManagerDepartament() :Manager() {
		this->numeDepartament = "Departament";
		this->deCercetare = false;
	}

	ManagerDepartament(string nume, bool deCercetare, int nrSubordonati, float sporPerSubordonat) :Manager(nrSubordonati,sporPerSubordonat){
		this->numeDepartament = nume;
		this->deCercetare = deCercetare;
	}

	//automat pointerul din tab nu mai e nul-> aceasta clasa nu mai e abstracta si putem initializa/crea ob de acest tip


	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		if (this->deCercetare) {
			venit += (10 / 100) * salariu;
		}
		return venit;
	}
};

class ManagerDeProiect : public Manager {
private:
	string numeProiect;
	int nrZile;
	float sporPerZi;

public:
	ManagerDeProiect() :Manager() {
		this->numeProiect = "Project";
		this->nrZile = 0;
		this->sporPerZi = 0;
	}

	ManagerDeProiect(string nume, int nrZile, float sporPeZi, int nrSubordonati, float sporPerSubordonat): Manager(nrSubordonati,sporPerSubordonat) {
		this->numeProiect = nume;
		this->nrZile = nrZile;
		this->sporPerZi = sporPeZi;
	}

	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		venit += (this->nrZile * this->sporPerZi);
		return venit;
	}
};

class Cercetator : public Angajat {
public:
	Cercetator(int marca, string nume, float salariu) : Angajat(marca, nume, salariu) {
		this->marca = marca;
		this->nume = nume;
		this->salariu = salariu;
	}

	float getVenitIncasat() {
		return this->salariu;
	}
};

int main() {
	//Angajat a; nu avem voie sa instantiem o clasa abstracta; va fi eroare si pt clasele care o mostenesc
	//Manager m; la fel

	ManagerDepartament md;
	ManagerDeProiect mdp;

	Angajat* pointer;
	pointer = NULL;
	pointer = new ManagerDepartament();
	pointer->getVenitIncasat(); //va fi apelata metoda din Manager dept pt ca se realizeaza o leg tarzie (latebiding) la mom de executie
	                            //earlybiding- la momentul compilarii

	int nrAngajati = 5;
	Angajat** vector; // vector de pointeri
	vector= new Angajat * [nrAngajati];
	vector[0] = new ManagerDepartament();
	vector[1] = new ManagerDeProiect();
	vector[2] = new ManagerDeProiect("TODO List", 10, 30, 3, 15);
	vector[3] = new ManagerDepartament("AI", true, 10, 15);
	vector[4] = new Cercetator(9876,"Popescu",6000);

	for (int i = 0; i < nrAngajati; i++)
	{
		cout <<(i+1)<<"." << vector[i]->getVenitIncasat() << endl;
	}

	return 0;
}