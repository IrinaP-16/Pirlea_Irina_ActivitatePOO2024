//#include <iostream>
//#define _CRT_SECURE_NO_WARNINGS
//#include <string>
//#include <math.h>
//#include <functional>
//#include <vector>
//#include <numeric>
//
//using namespace std;
//
//class CartelaTransport{
//
//private:
//
//	const string serieCartela;
//	string NumePosesor;
//	int nrZileUtilizare;
//	float sumaPortofel;
//	int nrCalatorii;
//	float* valoriCalatorii;
//	static float valoareMinCalatorie;
//
//public:
//	CartelaTransport() : serieCartela("ZLXW") {   // constructorul default
//		NumePosesor = "Popescu Maria";
//		nrZileUtilizare = 16;
//		sumaPortofel = 45.5;
//		nrCalatorii = 10;
//		valoriCalatorii = new float[10];
//		for (int i = 0; i < nrCalatorii; i++)
//			valoriCalatorii[i] = i;
//	}
//
//	CartelaTransport(string NumePosesor, int nrZileUtilizare, float sumaPortofel, int nrCalatorii, float* valoriCalatorii, string NewSerieCartela) : serieCartela(NewSerieCartela) {   // construnctorul cu parametri + VALIDARI??
//		this->NumePosesor = NumePosesor;
//		if (nrZileUtilizare <= 30) {
//		this->nrZileUtilizare = nrZileUtilizare;
//	    }
//		if (sumaPortofel > 0) {
//			this->sumaPortofel = sumaPortofel;
//		}
//		if (nrCalatorii > 0) {
//			this->nrCalatorii = nrCalatorii;
//		}
//		this->valoriCalatorii = new float[nrCalatorii];
//		for (int i = 0; i < nrCalatorii; i++)
//		{
//			this->valoriCalatorii[i] = valoriCalatorii[i];
//		}
//
//	}
//
//	CartelaTransport(CartelaTransport& ct): serieCartela(ct.serieCartela){   // constructorul de copiere
//		NumePosesor = ct.NumePosesor;
//		nrZileUtilizare = ct.nrZileUtilizare;
//		sumaPortofel = ct.sumaPortofel;
//		nrCalatorii = ct.nrCalatorii;
//		valoriCalatorii =new float[ct.nrCalatorii];
//		for (int i = 0; i < ct.nrCalatorii; i++) 
//		{
//			valoriCalatorii[i] = ct.valoriCalatorii[i];
//		}
//
//	}
//
//	~CartelaTransport() {
//		delete[] valoriCalatorii;  
//	}
//
//	string getNumePosesor() {      // getteri si setteri; VERIFICAREA PARAMETRILOR PRIMITI IN SETTERI
//		return NumePosesor;
//	}
//
//	float* getValoriCalatorii() {
//		return valoriCalatorii;
//	}
//
//	void setNumePosesor(string NumelePosesorului) {
//		if (NumelePosesorului != "") {
//			this->NumePosesor = NumelePosesorului;
//		}
//	}
//
//	void setValoriCalatorii(float* ValorileCalatoriilor, int nrCalatorii) {
//		if (ValorileCalatoriilor != nullptr) {
//
//			this->nrCalatorii = nrCalatorii;
//
//			for (int i = 0; i < nrCalatorii; i++)
//				this->valoriCalatorii[i] = ValorileCalatoriilor[i];
//		}
//	}
//
//
//	CartelaTransport& operator=(CartelaTransport& ct) {    // supraincarcare operator =
//		this->NumePosesor = ct.NumePosesor;
//		this->nrZileUtilizare = ct.nrZileUtilizare;
//		this->sumaPortofel = ct.sumaPortofel;
//		this->nrCalatorii = ct.nrCalatorii;
//		this->valoriCalatorii = new float[ct.nrCalatorii];
//		for (int i = 0; i < nrCalatorii; i++) {
//			this->valoriCalatorii[i] = valoriCalatorii[i];
//		}
//		return *this;
//
//	}
//
//	friend ostream& operator<<(ostream& os, CartelaTransport& ct) {   // supraincarcare operator <<
//		os << "Seria cartelei: " << ct.serieCartela << endl;
//		os << "Numele Posesorului: " << ct.NumePosesor << endl;
//		os << "Numar zile utilizare: " << ct.nrZileUtilizare << endl;
//		os << "Suma ramasa: " << ct.sumaPortofel << endl;
//		os << "Numarul calatoriilor efectuate: " << ct.nrCalatorii << endl;
//		os << "Valorile calatoriilor efectuate: " << endl;
//		for (int i = 0; i < ct.nrCalatorii; i++) {
//			os << ct.valoriCalatorii[i] << endl;
//		}
//		os << "Valoarea minima a unei calatorii: " << ct.valoareMinCalatorie << endl;
//		return os;
//	}
//
//	friend istream& operator>>(istream& is, CartelaTransport& ct) {   //supraincarcare operator >>
//		cout << "Numele Posesorului: ";
//		getline(is,ct.NumePosesor);
//		cout << "Numar zile utilizare: ";
//		is>>ct.nrZileUtilizare;
//		cout << "Suma ramasa: "; 
//		is >> ct.sumaPortofel;
//		cout << "Numarul calatoriilor efectuate: "; is >> ct.nrCalatorii;
//		ct.valoriCalatorii = new float[ct.nrCalatorii];
//		cout << "Valorile calatoriilor efectuate: "; 
//		for (int i = 0; i < ct.nrCalatorii; i++)
//		{
//			is >> ct.valoriCalatorii[i];
//		}
//		cout << "Valoarea minima a unei calatorii: "; is >> ct.valoareMinCalatorie;
//		return is;
//	}
//
//	////8 ??
//
//	CartelaTransport& operator+=(float valoare) {
//
//		if (sumaPortofel < valoare)
//		{
//			cout << "Nu sunt bani suficienti." << endl;
//			return *this;
//		}
//		else
//		{
//			float* aux = new float[nrCalatorii + 1];
//			for (int i = 0; i < nrCalatorii; i++)
//				aux[i] = valoriCalatorii[i];
//			aux[nrCalatorii] = valoare;
//			delete[] valoriCalatorii;
//			valoriCalatorii = aux;
//			nrCalatorii++;
//			sumaPortofel = sumaPortofel - valoare;
//			return *this;
//		}
//			
//	}
//
//	////9?
//	friend bool operator>(CartelaTransport& ct1, CartelaTransport& ct2) {
//		float s1=0, s2=0;
//		s1 = accumulate(ct1.valoriCalatorii, ct1.valoriCalatorii + ct1.nrCalatorii, 0.0f);   // numele vectorului -> primul element al vectorului, numele vectorului + dimensiunea ->ultimul element al vectorului
//		s2 = accumulate(ct2.valoriCalatorii, ct2.valoriCalatorii + ct2.nrCalatorii, 0.0f);
//		if (s1 > s2)
//			return true;
//		return false;
//	}
//
//	float medieSumaPeZi() {
//		float s = 0;
//		s = accumulate(this->valoriCalatorii, valoriCalatorii + nrCalatorii, 0.0f);
//		return s / nrZileUtilizare;
//	};
//};
//
//float CartelaTransport::valoareMinCalatorie =2.5;
//
//int main()
//{
//	CartelaTransport CT1;
//	float v[] = { 8, 7, 9, 4, 3 };
//	CartelaTransport CT2("Ionescu Andrei", 20, 80.7, 5, v,"FGHJ");
//	cout << CT1 << endl;
//	cout << CT2 << endl;
//	CartelaTransport CT3(CT1);
//	cout << CT3 << endl;
//	
//	CT1.setValoriCalatorii(v,5);
//	CT1.setNumePosesor("Ionescu Andrei");
//	cout << CT1<<endl;
//
//	CartelaTransport CT4;
//	cin >> CT4;
//	cout << CT4 << endl;
//
//	CT4 += 3;
//	cout << CT4 << endl;
//
//	if (CT4 > CT2)
//		cout << "E mai mare" << endl;
//	else
//		cout << "E mai mic" << endl;
//
//	float medie = CT4.medieSumaPeZi();
//	cout << "Valoarea medie cheltuita pe zi pentru transport: " << medie << endl;
//}