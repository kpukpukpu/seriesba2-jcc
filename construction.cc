#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Pour simplifier
typedef string Forme   ;
typedef string Couleur ;

class Brique
{
private:
  Forme   forme   ;
  Couleur couleur ;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
	Brique (Forme f, Couleur c) 
	:forme(f), couleur(c) {}
	
	ostream& afficher(ostream& sortie) const{ 
		if (couleur != " ") {
			sortie << " (" << forme<<", "<<couleur<<")"; 
		}else { 
			sortie << forme; 
		} 
		return sortie; 
	}
	ostream& operator << (ostream& sortie) const; 
};

ostream& operator <<(ostream& sortie, Brique const& b){
	return b.afficher(sortie); 
}

class Construction
{ 
  friend class Grader;
  vector < vector < vector <Brique>>> contenu; 
  public: 
  Construction (Brique const& B) 
  :contenu(1, vector<vector<Brique>>(1, vector<Brique>(1, B))){}
  
  ostream& afficher(ostream& sortie) const {
	  for( size_t i(0); i<=contenu.size(); ++i){
		  sortie <<" Couche "<<i<<" :" << endl; 
		  for(size_t j(0); j<= contenu[i].size(); ++j){
			  for( size_t k(0); k<= contenu[i][j].size(); ++k){
				   sortie<< contenu[i][j][k]; 
			  } 
		  }
	  }
	  return sortie;  
  } 
  
  Construction operator^=(Construction const& batiment){
	  for(size_t i(0); i<= batiment.contenu.size(); ++i) {
		  contenu.push_back(batiment.contenu[i]); 
	  }
	  return *this; 
  } // est ce que ca marhce // 
   const Construction operator^(Construction const& c);
   
	Construction operator-=(Construction const& batiment){ 
		if (batiment.contenu.size() == contenu.size()){
			contenu.push_back(batiment.contenu); // push back vers le haut ici et pas vers l'arrière //
		}else { 
			for (size_t i(0); i<= contenu.size(); ++i){
				contenu[i].push_back(batiment.contenu[i]); 
			}
		}
		return *this; 
	}
	const Construction operator-(Construction const& c);
	
	Construction operator+=(Construction const& batiment) {
		for (size_t i(0); i<= contenu.size();++i){
			for (size_t j(0); j<= contenu[i].size();++j){
				if (batiment.contenu[i].size() >= contenu[i].size() ) {
					contenu[i].push_back(batiment.contenu[i][j]); // à verifier//
				}else if (batiment.contenu[i][j].size() >= contenu [i][j].size()){
					contenu[i][j].push_back(batiment.contenu[i][j]);
				}
			}
		}
		return *this;
	}
const Construction operator+(Construction const& c);

		
};
ostream& operator<<(ostream& sortie, Construction const& batiment){
	return batiment.afficher(sortie);
}

const Construction operator^(Construction c, Construction const& batiment){
	return c.operator ^=(batiment);
}

const Construction operator -(Construction c, Construction const& batiment){
	return c.operator -=(batiment); 
}

const Construction operator+(Construction c, Construction const& batiment){
	return c.operator+=(batiment);
}

const Construction operator*(unsigned int n, Construction a) { 
	while (n >0){
	a.operator+(a); 
	--n;
}
	return a;
}

const Construction operator/(unsigned int n, Construction a)
{ 
	while (n>0){
	a.operator^(a); 
	--n;
	}
	return a;

}
const Construction operator%(unsigned int n, Construction a)
{ while (n>0){
	a.operator-(a);
	--n;
}
	return a;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  // Modèles de briques
  Brique toitD("obliqueD", "rouge");
  Brique toitG("obliqueG", "rouge");
  Brique toitM(" pleine ", "rouge");
  Brique mur  (" pleine ", "blanc");
  Brique vide ("                 ", "");

  unsigned int largeur(4);
  unsigned int profondeur(3);
  unsigned int hauteur(3); // sans le toit

  // on construit les murs
  Construction maison( hauteur / ( profondeur % (largeur * mur) ) );

  // on construit le toit
  Construction toit(profondeur % ( toitG + 2*toitM + toitD ));
  toit ^= profondeur % (vide + toitG + toitD);

  // on pose le toit sur les murs
  maison ^= toit;

  // on admire notre construction
  cout << maison << endl;

  return 0;
}
