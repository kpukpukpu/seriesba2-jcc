#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 

class Figure {
	public :
	virtual void affiche() const =0; 
	virtual Figure* copie() const =0; 
	virtual ~Figure (){};
}; 

class Cercle : public Figure {
	double rayon;  // position centre du cercle ? //
	public :
	Cercle (double r =1.) 
	: rayon(r) {
		cout << "Un cercle a été créé ! "<<endl;}
	Cercle (Cercle const& c) 
	: rayon(c.rayon) {
		cout << " Un cercle a été créé par copie ! " <<endl; }
	~Cercle (){
		cout <<"Un cercle a été détruit ! "<<endl; }
	void affiche() const override {
		cout <<" Ceci est un cercle de rayon : "<< rayon <<endl; 
	}
	Cercle* copie() const override {
		return new Cercle(*this); 
	}
}; 

class Triangle : public Figure {
	double base; 
	double hauteur; 
	public : 
	Triangle ( double b , double h)
	: base(b), hauteur(h) {
		cout <<"Un triangle a été créé !"<<endl; }
	Triangle (Triangle const& t) 
	: base(t.base), hauteur(t.hauteur) {
		cout<<"Un triangle a été créé par copie !"<<endl; }
	~Triangle (){
		cout<<"Un triangle a été détruit !"<<endl; }
	void affiche() const override{ 
		cout << " Ceci est un triangle de base : "<<base<<" et de hauteur :"
		<< hauteur << endl; 
	}
	Triangle* copie() const override{
		return new Triangle(*this); 
	}
}; 

class Carre : public Figure {
	double cote; 
	public : 
	Carre (double c=1.) : cote(c){
		cout << "Un carré a été créé !"<<endl; }
	Carre (Carre const& c) : cote(c.cote) {
		cout << "Un carré a été créé par copie ! "<<endl; }
	~Carre(){
		cout << "Un carré a été detruit !" <<endl;}
	void affiche() const override {
		cout << "Ceci est un carre de cote: "<<cote<<endl; 
	}
	Carre* copie() const override {
		return new Carre(*this); 
	}
}; 

class Dessin {
	vector<Figure*> collection;
	public: 
	void ajouteFigure (Figure const& fig){
		collection.push_back(fig.copie());
	}
	void affiche() const { 
		for (auto figure: collection ){
			figure->affiche();
		}
	}
	~Dessin() {
		cout<<"le dessin est detruit !"<<endl; 
		for (auto figure: collection){
			delete figure; 
			figure=nullptr; 
		}
	}
};

int main() { 
	Dessin dessin;
dessin.ajouteFigure(Triangle(3,4)); 
dessin.ajouteFigure(Carre(2)); 
dessin.ajouteFigure(Triangle(6,1)); 
dessin.ajouteFigure(Cercle(12));
cout << endl << "Affichage du dessin : " << endl;
dessin.affiche(); 
}
