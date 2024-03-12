#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Flacon
{
private:
  string nom;
  double volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  Flacon (string Nom, double v, double ph) 
  : nom(Nom), volume(v), pH(ph) {}
  
  ostream& etiquette(ostream& sortie) const{
	  sortie << nom << " : " << volume << " ml, pH "<<pH; 
	  return sortie;
  } 
  ostream& operator<<(ostream& sortie) const;
	
   Flacon operator +(Flacon const& flac1) const{ 
	  double nvpH= - log10((this->volume* pow(10.0,-this->pH)+flac1.volume* pow(10.0,-flac1.pH))/(this->volume+flac1.volume));
	  Flacon melange(this->nom + " + " + flac1.nom,flac1.volume + this->volume, nvpH);
	  // syntaxe premier attribut //
  return melange;
  }
	  
  
};
ostream& operator <<(ostream& sortie, Flacon const& flacon) {
   return flacon.etiquette(sortie); 
  }

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const& f1, Flacon const& f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique",  800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;

}
