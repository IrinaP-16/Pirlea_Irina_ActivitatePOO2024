#include <iostream>
#include<vector>
#include<list>
#include<map>

using namespace std;

class Librarie {
protected:
	string nume;

public:
	Librarie() {
		this->nume = "Mihai Eminescu";
	}

	Librarie(string nume) {
		this->nume = nume;
	}

	virtual string getDenumire() {
		return nume;
	}
};

class LibrarieOnline : public Librarie {
	string site;
public:
	LibrarieOnline() :Librarie("Librarie Online") {
		this->site = "www.site.ro";
	}

	LibrarieOnline(string nume, string site) : Librarie(nume) {
		this->site = site;
	}

	string getDenumire() {
		return nume + " - " + site;
	}
};

int main() {
	LibrarieOnline lo("Libris", "libris.ro");
	cout << lo.getDenumire() << endl;

	Librarie* lib = new LibrarieOnline("Humanitas", "humanitas.ro");

	cout << lib->getDenumire() << endl;

	vector<float> v;
	v.push_back(1.2);
	v.push_back(4.5);
	v.push_back(3.7);
	v.push_back(5.9);
	float s = 0;
	for (int i = 0; i < v.size(); i++) {
		s = s + v[i];
	}

	//float suma=accumulate(v.begin(),v.end(),0); // echivalent pt for-ul de mai sus pt a det suma

	if (v.size() > 0) {
		cout << "Media este: " << s / v.size() << endl;
	}
	else
		cout << "Media nu se poate calcula." << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	//list<Librarie> *l; pointer la o lista de librarii

	list<Librarie*> lista;
	lista.push_front(new Librarie());
	lista.push_front(new Librarie("Carturesti"));
	lista.push_front(new LibrarieOnline("Bookzone", "bookzone.ro"));
	lista.push_back(new LibrarieOnline());                            //push_back si push_front pot fi alternate

	list<Librarie*>::iterator it = lista.begin();
	while (it != lista.end()) {
		cout << (*it)->getDenumire() << endl;
		it++;
	}

	map<int, Librarie> librarii;
	librarii.insert(pair<int, Librarie>(1, Librarie()));
	librarii.insert(pair<int, Librarie>(27, Librarie("Carturesti")));
	librarii.insert(pair<int, Librarie>(3, Librarie("Libris")));
	librarii.insert(pair<int, Librarie>(23, Librarie("Graphotek")));
	librarii.insert(pair<int, Librarie>(3, Librarie("Mihail Sadoveanu")));

	cout << librarii[23].getDenumire()<<endl;
	map<int, Librarie>::iterator iterator=librarii.begin();
	cout << "Afisare map: " << endl;
	while (iterator != librarii.end()) {
		cout << iterator->first<<"-";
		cout << iterator->second.getDenumire();
		cout << endl;
		iterator++;
	}

	return 0;
}