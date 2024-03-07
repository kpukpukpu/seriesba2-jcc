#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
class Patient {
	private:
	double masse; 
	double hauteur;
	public: 
	void init(double inipoids, double initaille){
		if (inipoids < 0 or initaille < 0){
			masse = 0;
			hauteur = 0; 
		}else {
			masse = inipoids;
			hauteur = initaille;
		}
	} 
	void afficher() const {
		cout << "Patient : " << masse <<"kg pour "<< hauteur << "m" <<endl; 
	}
	double poids() const { 
		return masse;
	}
	double taille() const {
		return hauteur; 
	}
	double imc() const { 
		if (hauteur == 0){
			return 0; 
		}else {
			return masse / (hauteur*hauteur);
		}
	}
		
};
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Patient quidam;
  double poids, taille;
  do {
    cout << "Entrez un poids (kg) et une taille (m) : ";
    cin >> poids >> taille;
    quidam.init(poids, taille);
    quidam.afficher();
    cout << "IMC : " << quidam.imc() << endl;
  } while (poids * taille != 0.0);
  return 0;
}
