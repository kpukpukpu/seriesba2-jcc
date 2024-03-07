#include <iostream> 

using namespace std; 

void affiche_date(int annee, int nb_jour){
	if (nb_jour <= 31) {
		cout <<"Date de Paques en "<<annee<<" : "<<nb_jour<<" mars" <<endl;
	}
	if (nb_jour>=32){
		nb_jour= nb_jour -31;
		cout <<"Date de Paques en "<<annee<<" : "<<nb_jour<<" avril" <<endl;
	}
}
