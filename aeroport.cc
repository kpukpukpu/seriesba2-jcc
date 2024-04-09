#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Vehicule {
	protected:
	int vitesse; 
	string marque; 
	int passagers; 
	public:
	int get_vitesse()const{
		return vitesse; 
	}
	Vehicule (int v, string m, int p) 
	: vitesse(v), marque(m), passagers(p) {}
	virtual ostream& affiche(ostream& sortie) const{
		sortie <<this-> get_vitesse() <<endl; 
		return sortie; 
	}
	
};

ostream& operator <<(ostream& sortie, Vehicule const& v){
	sortie <<"Vehicule  de vitesse :";
	v.affiche(sortie);
	return sortie; 
}

class Avion : public Vehicule{
	
}; 

ostream& operator<<(ostream& sortie, Avion const& a){
	sortie << "Avion de vitesse :" ;
	a.affiche(sortie);
	return sortie; 
}

class Voiture : public Vehicule{
	public:
	ostream& affiche(ostream& sortie) const;
}; 

ostream& operator<<(ostream& sortie, Voiture const& v) {
	sortie <<" voiture de vitesse :";
	v.affiche(sortie); 
	return sortie; 
}


class Aeroport {
	vector<Vehicule *> vehicules; 
	public: 
	void affiche_vehicules(ostream& sortie)const{
		for (auto vehicule: vehicules){
			cout << &vehicule <<endl; 
		}
	}
	void ajouter_vehicules(Vehicule * v){
		vehicules.push_back(v); 
	}
	void vider_vehicules(){
		vehicules.clear(); 
	}
		
	
};
