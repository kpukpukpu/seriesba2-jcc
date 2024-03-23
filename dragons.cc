#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int distance(int x, int y)
{
  return abs(x - y);
}

class Creature
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
 protected:
 const string nom;
 int niveau_;
 int points_de_vie_; 
 int force_; 
 int position_;
 public:
 Creature(const string n, int niv, int pdv, int strenght, int pos =0)
 : nom(n), niveau_(niv), points_de_vie_(pdv), force_(strenght), position_(pos) {}
 
 int position() const {
	 return position_; 
 }
 
 bool vivant() const {
	 bool vivant = false; 
	 if (points_de_vie_ >0){
		 vivant = true; 
	 }
	 return vivant; 
 }
 int points_attaque(){
	 int attaque = 0; 
	 if (this->vivant() ){
		 attaque = niveau_ * force_; 
	 }
	 return attaque; 
 }
 void deplacer(int n) {
	 if (vivant()) {
		position_= position_ +n;
	 } 
 }
 void adieux() const {
	 cout << this->nom <<" n'est plus!"<<endl; 
 }
 void faiblir (int p_recus){
	int points = points_de_vie_ - p_recus; 
	if (points <=0) {
		points_de_vie_=0; 
		this->adieux(); 
	}else {
		points_de_vie_ = points; 
	}
  }
 void afficher(){
	 cout << this->nom<<", niveau: "<<this->niveau_<<", points de vie: "<<this->points_de_vie_
	 <<", force: "<<this->force_<<", points d'attaque: "
	 <<this->points_attaque()<<", position: "<<this->position_<<endl;
 }
		
};
class Dragon : public Creature {
	int portee_flamme_; 
	public: 
	Dragon(const string n, int niv, int pdv, int strenght, int flamme, int pos=0)
	:Creature(n, niv, pdv, strenght, pos), portee_flamme_(flamme){}
	void voler (int pos) {
		if (Creature::vivant()) {
			position_=pos;
		}
	}
	void souffle_sur(Creature& bete){
		int dist = distance (bete.position(), this->position_);
		bool was_vivant = bete.vivant();
		if (vivant() and bete.vivant() and portee_flamme_>dist){ 
			bete.faiblir(this->points_attaque()); 
			this->faiblir(dist);
		}
		if (vivant() and not bete.vivant() && was_vivant){
			this->niveau_+=1; 
		}
	}
}; 
class Hydre : public Creature {
	int longueur_cou_; 
	int dose_poison_; 
	public: 
	Hydre( string n, int niv, int pdv, int strenght, int cou, int poison, int pos=0)
	:Creature(n, niv, pdv, strenght, pos), longueur_cou_(cou), dose_poison_(poison)
	{}
	void empoisonne(Creature& bete){
		bool was_vivant = bete.vivant();
		int portee_cou = distance(position_, bete.position());
		if (vivant() and bete.vivant() and portee_cou <= longueur_cou_){
			bete.faiblir(points_attaque() + dose_poison_); 
		}
		if (vivant() and not bete.vivant() and was_vivant){
			niveau_+=1; 
		}
	}
	
			
	
}; 
void combat(Dragon& dragon, Hydre& hydre){
		hydre.empoisonne(dragon); 
		dragon.souffle_sur(hydre); 
		}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  Dragon dragon("Dragon rouge"   , 2, 10, 3, 20         );
  Hydre  hydre ("Hydre maléfique", 2, 10, 1, 10, 1,  42 );

  dragon.afficher();
  cout << "se prépare au combat avec :" << endl;
  hydre.afficher();

  cout << endl;
  cout << "1er combat :" << endl;
  cout << "    les créatures ne sont pas à portée, donc ne peuvent pas s'attaquer."
       << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon vole à proximité de l'hydre :" << endl;
  dragon.voler(hydre.position() - 1);
  dragon.afficher();

  cout << endl;
  cout << "L'hydre recule d'un pas :" << endl;
  hydre.deplacer(1);
  hydre.afficher();

  cout << endl;
  cout << "2e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 2 points de vie supplémentaires\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 41 = 2 ].\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "Le dragon avance d'un pas :" << endl;
  dragon.deplacer(1);
  dragon.afficher();

  cout << endl;
  cout << "3e combat :" << endl;
  cout << "\
  + l'hydre inflige au dragon une attaque de 3 points\n\
      [ niveau (2) * force (1) + poison (1) = 3 ] ;\n\
  + le dragon inflige à l'hydre une attaque de 6 points\n\
      [ niveau (2) * force (3) = 6 ] ;\n\
  + pendant son attaque, le dragon perd 1 point de vie supplémentaire\n\
       [ correspondant à la distance entre le dragon et l'hydre : 43 - 42 = 1 ] ;\n\
  + l'hydre est vaincue et le dragon monte au niveau 3.\
" << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  cout << endl;
  cout << "4e Combat :" << endl;
  cout << "    quand une créature est vaincue, rien ne se passe." << endl;
  combat(dragon, hydre);

  cout << "Après le combat :" << endl;
  dragon.afficher();
  hydre.afficher();

  return 0;
}
