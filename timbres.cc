#include <iostream>
#include <string>
using namespace std;

class Timbre
{
private:
  static constexpr unsigned int ANNEE_COURANTE = 2016;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
   protected:  // des guetteurs//
   string nom;
   unsigned int annee; 
   string pays; 
   double valeur_faciale;
   public: 
   unsigned int age()const{
	   return ANNEE_COURANTE - annee; 
   }
   double vente()const{
	   double prix; 
	   if (this->age() <=5){ //inegalite stricte ?//
		   prix = valeur_faciale; 
	   }else {
		   prix = 2.5* valeur_faciale*annee;
	   }
	   return prix; 
   }
   Timbre (string n, unsigned int A, string p = "Suisse", double val=1.0)
   : nom(n), annee(A), pays(p), valeur_faciale(val) {}
   ostream& afficher(ostream& sortie)const{
	   sortie <<"de nom "<<this->nom
	   <<" datant de " <<this->annee<<" (provenance "<<this->pays
	   <<") ayant pour valeur faciale "<<this->valeur_faciale<<" francs";
	   return sortie;
   }
};

ostream& operator<<(ostream& sortie, Timbre const& t) {
	sortie << "Timbre ";
	t.afficher(sortie);
	return sortie;
}
class Rare : public Timbre{
	unsigned int exemplaires;
	public:
	static const int PRIX_BASE_TRES_RARE =600;
	static const int PRIX_BASE_RARE = 400;
	static const int PRIX_BASE_PEU_RARE = 50; 
	double vente()const{
		double prixb;
		if(exemplaires <100){
			prixb=PRIX_BASE_TRES_RARE;
		}else if (exemplaires<1000){
			prixb = PRIX_BASE_RARE;
		}else {
			prixb = PRIX_BASE_PEU_RARE;
		}
		
	return prixb * (this->age()/10.0);
}
   unsigned int get_exemplaires()const{
	   return exemplaires;
	   }
   Rare(string n, unsigned int A, string p = "Suisse", double val=1.0, unsigned int ex=100)
   : Timbre(n, A, p, val), exemplaires(ex) {}
   
};
ostream& operator<<(ostream& sortie, Rare const& r){
	sortie <<"Timbre rare ("<<r.get_exemplaires()<<" ex.) ";
	r.afficher(sortie);
	return sortie; 
}

class Commemoratif : public Timbre{
	public:
	double vente()const{
		return 2* Timbre::vente();
	}
	Commemoratif(string n, unsigned int A, string p = "Suisse", double val=1.0)
	:Timbre(n, A, p, val) {}
};
ostream& operator<<(ostream& sortie, Commemoratif const& c){
	sortie<<"Timbre commémoratif ";
    c.afficher(sortie);
	return sortie; 
}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
int main()
{
  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Rare t1( "Guarana-4574", 1960, "Mexique", 0.2, 98 );
  Rare t2( "Yoddle-201"  , 1916, "Suisse" , 0.8,  3 );

  /* Ordre des arguments :
  *  nom, année d'émission, pays, valeur faciale, nombre d'exemplaires
  */
  Commemoratif t3( "700eme-501"  , 2002, "Suisse", 1.5 );
  Timbre       t4( "Setchuan-302", 2004, "Chine" , 0.2 );

  /* Nous n'avons pas encore le polymorphisme :-(
   * (=> pas moyen de faire sans copie ici :-( )  */
  cout << t1 << endl;
  cout << "Prix vente : " << t1.vente() << " francs" << endl;
  cout << t2 << endl;
  cout << "Prix vente : " << t2.vente() << " francs" << endl;
  cout << t3 << endl;
  cout << "Prix vente : " << t3.vente() << " francs" << endl;
  cout << t4 << endl;
  cout << "Prix vente : " << t4.vente() << " francs" << endl;

  return 0;
}
