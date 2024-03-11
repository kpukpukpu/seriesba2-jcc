#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractères à utiliser pour les affichages:
/*

été jeté

d'un

n'est

L'oeuvre

bibliothèque

détruit

*/
class Auteur
{
    string nom;
    bool prime;

public:
    Auteur(string Nom, bool p = false)
        : nom(Nom), prime(p) {}
    string getNom() const
    {
        return nom;
    }
    bool getPrix() const
    {
        return prime;
    }
    // copier un auteur //
};
class Oeuvre
{
    string titre;
    Auteur const &auteur;
    string langue;

public:
    Oeuvre(string t, Auteur &a, string l)
        : titre(t), auteur(a), langue(l)
    {
    }
    string getTitre() const
    {
        return titre;
    }
    Auteur const &getAuteur() const
    {
        return auteur;
    }
    string getLangue() const
    {
        return langue;
    }
    string getTitreComplet() const
    {
        return titre + ", " + this->getAuteur().getNom() + ", en " + langue;
    }
    void affiche()
    {
        cout << getTitreComplet() << endl;
    }
    ~Oeuvre() { cout << "L'oeuvre \"" << getTitreComplet() << "\" n'est plus disponible." << endl; }
    // pas copier 0euvre //
};
class Exemplaire
{
    Oeuvre const &oeuvre;

public:
    Exemplaire(Oeuvre &o) : oeuvre(o) { cout << "Nouvel exemplaire de : " << o.getTitreComplet() << endl; } // get ?? //
    Exemplaire(Exemplaire const &autre)
        : oeuvre(autre.oeuvre) { cout << "Copie d'un exemplaire de : " << autre.oeuvre.getTitreComplet() << endl; }
    ~Exemplaire()
    {
        cout << "Un exemplaire de \"" << oeuvre.getTitreComplet() << "\" a été jeté ! " << endl;
    }
    Oeuvre const &getOeuvre() const
    {
        return oeuvre;
    }
    void affiche() const
    {
        cout << "Exemplaire de : " << oeuvre.getTitreComplet() << endl;
    }
};

class Bibliotheque
{ string nom;
 vector <Exemplaire *> biblio; 
  public:
  Bibliotheque (string Nom): nom(Nom) {
    cout << "La bibliothèque "<< nom << " est ouverte !"<< endl; 
  }
  string getNom() const { 
    return nom;
  }
  void stocker(Oeuvre const& oeuvre, size_t nbr = 1){
    for (size_t i=0; i<nbr; ++i){
        biblio.push_back(new Exemplaire(const_cast<Oeuvre&>(oeuvre)));
    }
  }
  void lister_exemplaires(string langue = "")
{
    for (size_t i= 0; i< biblio.size();++i ){
        if (langue == "" || biblio[i]->getOeuvre().getLangue()==langue){
            biblio[i]->affiche();
        }
    }
}
 int compter_exemplaires(Oeuvre const& oeuvre) {
  int resultat = 0;
  for (size_t i= 0; i< biblio.size();++i ){
   if (biblio[i]->getOeuvre().getTitre() == oeuvre.getTitre()){
    ++resultat; 
   }
  }
  return resultat; 
 }
 void afficher_auteurs (bool aprix = false){
  for (size_t i= 0; i< biblio.size();++i ){
   if (aprix and biblio[i]->getOeuvre().getAuteur().getPrix()){
    cout << biblio[i]->getOeuvre().getAuteur().getNom() << endl; 
   }else if (not aprix){
    cout << biblio[i]->getOeuvre().getAuteur().getNom() << endl;
   }
  }
 }
 ~Bibliotheque()
 { cout << "La bibliothèque "<<nom <<" ferme ses portes,"<<endl <<" et détruit ses exemplaires : "<<endl; 
  for(auto& element:biblio){
   delete element;
   element = nullptr;
  }
 }
   
};

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
  Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

  Oeuvre o1("Les Misérables" , a1, "français" ),
         o2("L'Homme qui rit" , a1, "français" ),
         o3("Le Comte de Monte-Cristo" , a2, "français" ),
         o4("Zazie dans le métro" , a3, "français" ),
         o5("The Count of Monte-Cristo", a2, "anglais" );

  Bibliotheque biblio("municipale");
  biblio.stocker(o1, 2);
  biblio.stocker(o2);
  biblio.stocker(o3, 3);
  biblio.stocker(o4);
  biblio.stocker(o5);

  cout << "La bibliothèque " << biblio.getNom()
       << " offre les exemplaires suivants :" << endl;
  biblio.lister_exemplaires();

  const string langue("anglais");
  cout << " Les exemplaires en "<< langue << " sont :" << endl;
  biblio.lister_exemplaires(langue);

  cout << " Les auteurs à succès sont :" << endl;
  biblio.afficher_auteurs(true);

  cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
       << o3.getTitre() << endl;

  return 0;
}
